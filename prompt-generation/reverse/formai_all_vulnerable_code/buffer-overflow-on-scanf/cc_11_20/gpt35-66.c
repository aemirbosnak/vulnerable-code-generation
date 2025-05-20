//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FLOORS 10 // total floors in the building

// define struct for elevator
typedef struct {
    int current_floor;
    bool is_moving;
    bool is_full;
} Elevator;

int main(){
    Elevator elevator = {1, false, false}; // initialize elevator at first floor, not moving, and not full
    int destination = 0; // initialize destination variable
    char choice; // initialize choice variable
    
    srand(time(NULL)); // seed random number generator
    
    while(true) {
        printf("You are currently on floor %d\n", elevator.current_floor); // display current floor
        
        // check if elevator is at destination
        if(elevator.current_floor == destination && elevator.is_moving) {
            printf("You have arrived at floor %d. Thank you for using the elevator!\n", destination);
            elevator.is_moving = false; // stop moving elevator
            elevator.is_full = false; // reset elevator to not full
        }
        
        // check if elevator is full
        if(elevator.is_full) {
            printf("The elevator is currently full. Please wait for the next elevator.\n");
            break;
        }
        
        printf("Where would you like to go? (Enter a floor number 1-%d or 'q' to quit) ", FLOORS);
        scanf(" %c", &choice); // get user input
        
        // check if user wants to quit
        if (choice == 'q') {
            printf("Thank you for using the elevator!\n");
            break;
        }
        
        // convert user input to integer
        destination = choice - '0';
        
        // check if destination is valid
        if(destination < 1 || destination > FLOORS) {
            printf("Invalid floor number. Please try again.\n");
            continue;
        }
        
        // check if elevator is moving
        if(elevator.is_moving) {
            printf("The elevator is currently moving. Please wait for the elevator to reach floor %d before selecting a new destination.\n", elevator.current_floor+1);
            continue;
        }
        
        // check if destination is same as current floor
        if(destination == elevator.current_floor){
            printf("You are already on floor %d. Please select a different destination.\n", destination);
            continue;
        }
        
        int distance = abs(destination - elevator.current_floor); // calculate distance to destination
        
        // simulate elevator movement
        printf("The elevator is now moving. Please wait...\n");
        elevator.is_moving = true;
        for(int i = 0; i < distance; i++) {
            printf("Floor %d\n", elevator.current_floor + (i + 1) * (destination - elevator.current_floor) / distance);
            if(rand() % 10 == 0) {
                printf("The elevator is stopping on the way to pick up more passengers.\n");
                elevator.is_full = true; // simulate elevator becoming full
            }
            sleep(1); // simulate elevator moving between floors
        }
        
        elevator.current_floor = destination; // update current floor
        
    }
    
    return 0;
}