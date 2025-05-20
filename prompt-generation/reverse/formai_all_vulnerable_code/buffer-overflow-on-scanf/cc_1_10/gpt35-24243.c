//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

#define NUM_FLOORS 6 // number of floors in the building

int currentFloor = 1; // starting floor of the elevator
int destinationFloor = 1; // floor the elevator needs to go to

bool goingUp = true; // flag to determine elevator direction
bool doorsOpen = false; // flag to determine if elevator doors are open

// helper functions
void updateDirection();
int getDestinationFloor();
void openDoors();
void closeDoors();
void moveToFloor(int floor);

int main() {
    int floorRequest;
    printf("Welcome to the elevator! You are currently on floor %d.\n", currentFloor);
    
    while(true) {
        printf("Please enter the floor you wish to go to: ");
        scanf("%d", &floorRequest);
        
        if (floorRequest == currentFloor) {
            printf("You are already on floor %d.\n", currentFloor);
        }
        else if (floorRequest < 1 || floorRequest > NUM_FLOORS) {
            printf("Invalid floor number.\n");
        }
        else {
            destinationFloor = floorRequest;
            updateDirection();
            
            while(currentFloor != destinationFloor) {
                if (doorsOpen) {
                    printf("Please close the doors.\n");
                    closeDoors();
                }
                
                moveToFloor(currentFloor + (goingUp ? 1 : -1));
                printf("The elevator has arrived at floor %d.\n", currentFloor);
                
                if (currentFloor == destinationFloor) {
                    printf("You have arrived at your destination.\n");
                    break;
                }
            }
        }
    }
    
    return 0;
}

void updateDirection() {
    if (destinationFloor > currentFloor) {
        goingUp = true;
    }
    else {
        goingUp = false;
    }
}

int getDestinationFloor() {
    int floorRequest;
    printf("Please enter the floor you wish to go to: ");
    scanf("%d", &floorRequest);
    return floorRequest;
}

void openDoors() {
    printf("Doors opening...\n");
    doorsOpen = true;
}

void closeDoors() {
    printf("Doors closing...\n");
    doorsOpen = false;
}

void moveToFloor(int floor) {
    if (goingUp) {
        currentFloor = floor;
        printf("Going up to floor %d.\n", currentFloor);
    }
    else {
        currentFloor = floor;
        printf("Going down to floor %d.\n", currentFloor);
    }
}