//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10 // maximum number of floors in the building
#define MIN_FLOORS 2 // minimum number of floors in the building

int main(){

    int num_floors = 0; // to hold the number of floors in the building

    while(num_floors < MIN_FLOORS || num_floors > MAX_FLOORS){ // loop until a valid number of floors is entered
        printf("Enter the number of floors in the building (between %d and %d): ", MIN_FLOORS, MAX_FLOORS);
        scanf("%d", &num_floors);
    }

    int current_floor = 1; // the elevator starts at the first floor
    int target_floor = 1; // the initial target floor is also the first floor
    int direction = 0; // 0 indicates the elevator is idle, 1 indicates it's going up, -1 indicates it's going down
    
    while(1){ // infinite loop for elevator operation

        printf("\nCurrent floor: %d\n", current_floor);

        if(current_floor == target_floor){ // check if the elevator has reached the target floor

            printf("\nArrived at floor %d\n", current_floor);

            target_floor = 1 + rand() % num_floors; // randomize the next target floor
            printf("Next target floor: %d\n", target_floor);

            if(current_floor < target_floor) direction = 1; // set direction to up if target floor is above the current floor
            if(current_floor > target_floor) direction = -1; // set direction to down if target floor is below the current floor
            if(current_floor == target_floor) direction = 0; // set direction to idle if target floor has already been reached

        }

        if(direction == 1){ // if elevator is going up

            printf("\nGoing up...\n");
            current_floor++;

        }

        if(direction == -1){ // if elevator is going down

            printf("\nGoing down...\n");
            current_floor--;

        }

    }

    return 0;

}