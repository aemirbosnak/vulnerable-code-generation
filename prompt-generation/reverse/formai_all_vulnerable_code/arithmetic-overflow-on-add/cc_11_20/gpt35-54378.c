//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5
#define MAX_CAPACITY 10

int main()
{
    int current_floor = 1; //initial floor is 1
    int passengers = 0; //initial no. of passengers
    int destination = 0; //initial destination
    int elevator_status = 0; //initial elevator status is stopped
    
    srand(time(NULL)); //initialize random seed
    
    printf("Elevator Simulation\n\n");
    printf("Starting at floor %d\n", current_floor);
    
    while(1) //infinite loop for elevator simulation
    {
        if(elevator_status == 0) //if elevator is stopped
        {
            printf("\n");
            sleep(1); //wait for 1 second
            
            //check if there are any passengers on current floor
            int boarding = rand() % 2; //randomly generate 0 or 1
            if(boarding && passengers < MAX_CAPACITY) //if there are passengers and elevator is not full
            {
                int new_passengers = rand() % (MAX_PASSENGERS - passengers) + 1; //randomly generate no. of new passengers
                printf("%d passengers boarding\n", new_passengers);
                passengers += new_passengers; //add new passengers
            }
            
            //check if any passenger wants to get off at current floor
            int unloading = rand() % 2; //randomly generate 0 or 1
            if(unloading && passengers > 0)
            {
                int passengers_to_unload = rand() % passengers + 1; //randomly generate no. of passengers to unload
                printf("%d passengers getting off\n", passengers_to_unload);
                passengers -= passengers_to_unload; //unload passengers
            }
            
            //generate a random destination floor
            if(passengers > 0) //if there are passengers in the elevator
            {
                do
                {
                    destination = rand() % MAX_FLOORS + 1; //randomly generate destination floor until it is different from current floor
                } while(destination == current_floor);
                
                printf("Elevator going to floor %d\n", destination);
                elevator_status = 1; //elevator is now moving
            }
        }
        else //if elevator is moving
        {
            sleep(1); //wait for 1 second
            
            if(current_floor < destination) //if elevator is going up
            {
                current_floor++;
                printf("Elevator going up, now at floor %d\n", current_floor);
            }
            else if(current_floor > destination) //if elevator is going down
            {
                current_floor--;
                printf("Elevator going down, now at floor %d\n", current_floor);
            }
            else //if elevator has reached the destination
            {
                printf("Elevator has arrived at floor %d\n", destination);
                elevator_status = 0; //elevator is now stopped
            }
        }
    }
    
    return 0;
}