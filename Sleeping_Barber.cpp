
 
#include <iostream>
#include <thread>
#include <deque>
#include <cstdlib>
  
using namespace std;

 
 
int cust_id = 0;

deque < int >waiting_room;

thread tarr[1000];

int i = 1;

int capacity;

int haircut_interval;

 
int
print_waiting_room () 
{
  
cout << "Waiting room: ";
  
for (int k = 0; k < waiting_room.size (); k++)
    
    {
      
cout << waiting_room[k] << " ";
    
} 
cout << endl;
  
 
return 0;

}


 
int
serve_the_customer (int c_id) 
{
  
cout << "Barber is cutting hair of customer " << c_id << endl;
  
return 0;

}


 
int
call_barber_cutting_hair () 
{
  
while (true)
    
    {
      
if (waiting_room.size () > 0)
	
	{
	  
print_waiting_room ();

thread t5 (serve_the_customer, waiting_room[0]);
	  
haircut_interval = (rand () % 5) + 1;

this_thread::sleep_for (chrono::milliseconds (haircut_interval));
	  

	  
t5.join ();
	  
waiting_room.pop_front ();
	
}
      
      else
	
	{

	  
this_thread::sleep_for (chrono::milliseconds (2000));

cout << "Barber is sleeping" << endl;

	
}
    
}

}


 
int
add_customer_to_waiting_room1 (int customer_id) 
{
  
waiting_room.push_back (customer_id);
  
return 0;

}


 
int
add_customer_to_waiting_room () 
{
  
while (i > 0)
    
    {
      
i = i + 1;
      
cust_id = cust_id + 1;
      
if (waiting_room.size () < capacity)
	
	{
	  
tarr[i] = std::thread (add_customer_to_waiting_room1, cust_id);
	  
this_thread::sleep_for (chrono::milliseconds (3000));
	  
tarr[i].join ();
	  
print_waiting_room ();
	
}
      
      else
	
	{
	  
cout << "Customer " << cust_id << " leaving." << endl;
	  
print_waiting_room ();
	
 
}
      
this_thread::sleep_for (chrono::milliseconds (1000));
    
}
  
return 0;

}


 
 
 
int
main () 
{
  
 
cout << "Enter the capacity of waiting room." << endl;
  
cin >> capacity;
  
thread t1 = std::thread (add_customer_to_waiting_room);
  
thread t2 = std::thread (call_barber_cutting_hair);
  
t1.join ();
  
t2.join ();
  
 
 
return 0;

 
}


