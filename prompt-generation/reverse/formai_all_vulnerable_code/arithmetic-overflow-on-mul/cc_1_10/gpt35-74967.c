//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10

int main() {
    //initialize variables
    int currentFloor = 1;
    int destinationFloor;
    int direction = 1; // 1 = up, -1 = down
    int numPassengers = 0;
    int maxCapacity;
    int waitTime;
    int totalTime = 0;
    int avgWaitTime;
    int numTrips = 0;
    int maxTrips;
    int maintenanceMode = 0;
    
    //random seed for wait times
    srand(time(0));
    
    //intro message
    printf("Welcome to the Mind-Bending Elevator Simulation!\n");
    
    //get user input for max capacity and max number of trips before maintenance
    printf("Please enter the maximum capacity of the elevator: ");
    scanf("%d", &maxCapacity);
    printf("Please enter the maximum number of trips before elevator maintenance: ");
    scanf("%d", &maxTrips);
    
    //start simulation loop
    while(maintenanceMode == 0){
        
        //wait time before doors open
        waitTime = rand() % 5;
        printf("Door closing in %d seconds...\n", waitTime);
        sleep(waitTime);
        
        //check if the elevator is at max capacity
        if(numPassengers >= maxCapacity){
            printf("Elevator is at maximum capacity. Please wait for the next elevator.\n");
        }
        else{ //if there is still room for passengers
            
            //get user input for destination floor
            printf("Please enter your destination floor (1-%d): ", NUM_FLOORS);
            scanf("%d", &destinationFloor);
            
            //check if the elevator is already on the requested floor
            if(destinationFloor == currentFloor){
                printf("You are already on floor %d. Please select a different floor.\n", currentFloor);
            }
            else{ //if the requested floor is different from current floor
                
                //check if the requested floor is above or below the current floor
                if(destinationFloor > currentFloor){
                    printf("Going up...\n");
                    direction = 1;
                }
                else{
                    printf("Going down...\n");
                    direction = -1;
                }
                
                //wait time for elevator to reach requested floor
                waitTime = abs(destinationFloor-currentFloor) * 2;
                printf("Elevator arriving in %d seconds...\n", waitTime);
                sleep(waitTime);
                
                //update current floor
                currentFloor = destinationFloor;
                
                //wait time for passengers to disembark and enter elevator
                waitTime = rand() % 10 + 1;
                printf("Door opening in %d seconds...\n", waitTime);
                sleep(waitTime);
                
                //passenger disembarkation
                printf("Passengers exiting...\n");
                numPassengers--;
                
                //passenger embarkation
                printf("Passengers entering...\n");
                numPassengers++;
                
                //update total time and number of trips
                totalTime += waitTime;
                numTrips++;
            }
        }
        
        //check if elevator has reached max trips
        if(numTrips >= maxTrips){
            maintenanceMode = 1;
            printf("Elevator has reached maximum number of trips. Entering maintenance mode...\n");
        }
    }
    
    //calculate and display average wait time
    avgWaitTime = totalTime / numTrips;
    printf("Average wait time: %d seconds\n", avgWaitTime);

    return 0;
}