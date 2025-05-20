//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

// Define elevator struct
typedef struct{
    int currentFloor;
    int destinationFloor;
    bool isOpen;
} Elevator;

// Define array of elevators
Elevator elevators[NUM_ELEVATORS];

// Function to initialize elevators
void initializeElevators(){
    for(int i=0; i<NUM_ELEVATORS; i++){
        elevators[i].currentFloor = 0;
        elevators[i].destinationFloor = 0;
        elevators[i].isOpen = false;
    }
}

// Function to determine which elevator to dispatch
int dispatchElevator(int fromFloor){
    int availableElevator = -1; // Initialize to -1
    int minDistance = NUM_FLOORS + 1; // Start with a distance greater than the total number of floors
    
    // Iterate through elevators to find closest
    for(int i=0; i<NUM_ELEVATORS; i++){
        if(!elevators[i].isOpen){ // Ignore open elevators
            int distance = abs(fromFloor - elevators[i].currentFloor);
            if(distance < minDistance){
                availableElevator = i;
                minDistance = distance;
            }
        }
    }
    
    // Return the index of the closest available elevator
    return availableElevator;
}

// Function to move an elevator to its destination
void moveElevator(int elevatorIndex){
    Elevator* elevator = &elevators[elevatorIndex];
    if(elevator->currentFloor < elevator->destinationFloor){
        printf("Elevator %d going up from floor %d to floor %d...\n", elevatorIndex+1, elevator->currentFloor, elevator->destinationFloor);
        while(elevator->currentFloor < elevator->destinationFloor){
            elevator->currentFloor++;
            printf("Elevator %d is now at floor %d\n", elevatorIndex+1, elevator->currentFloor);
        }
    }
    else if(elevator->currentFloor > elevator->destinationFloor){
        printf("Elevator %d going down from floor %d to floor %d...\n", elevatorIndex+1, elevator->currentFloor, elevator->destinationFloor);
        while(elevator->currentFloor > elevator->destinationFloor){
            elevator->currentFloor--;
            printf("Elevator %d is now at floor %d\n", elevatorIndex+1, elevator->currentFloor);
        }
    }
    elevator->isOpen = true;
    printf("Elevator %d doors open.\n", elevatorIndex+1);
    // Wait 5 seconds before closing the door
    sleep(5);
    elevator->isOpen = false;
    printf("Elevator %d doors close.\n", elevatorIndex+1);
}

int main(){
    initializeElevators();
    int fromFloor, toFloor, elevatorIndex;
    while(true){
        printf("Enter the floor you're on (0-%d) or -1 to exit: ", NUM_FLOORS-1);
        scanf("%d", &fromFloor);
        if(fromFloor == -1){
            break;
        }
        if(fromFloor < 0 || fromFloor >= NUM_FLOORS){
            printf("Invalid input. Please enter a number between 0 and %d.\n", NUM_FLOORS-1);
            continue;
        }
        elevatorIndex = dispatchElevator(fromFloor);
        printf("Elevator %d dispatched to floor %d.\n", elevatorIndex+1, fromFloor);
        printf("Enter the floor you want to go to (0-%d): ", NUM_FLOORS-1);
        scanf("%d", &toFloor);
        if(toFloor < 0 || toFloor >= NUM_FLOORS){
            printf("Invalid input. Please enter a number between 0 and %d.\n", NUM_FLOORS-1);
            continue;
        }
        elevators[elevatorIndex].destinationFloor = toFloor;
        moveElevator(elevatorIndex);
    }
    return 0;
}