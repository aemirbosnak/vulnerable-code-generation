//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: beginner-friendly
#include <stdio.h>

void moveElevator(int, int, int);
void printStatus(int, int);

int main()
{
    int currentFloor = 1; // elevator starts at ground floor
    int numFloors = 6; // number of floors in building
    char input;
    
    printf("Welcome to the elevator!\n\n");
    
    do {
        printf("Current floor: %d\n", currentFloor);
        printf("Select floor to go to (1-%d): ", numFloors);
        scanf(" %c", &input); // read user input
        
        int destinationFloor = input - '0'; // convert character input to integer
        
        if (destinationFloor < 1 || destinationFloor > numFloors) { // check if input is within valid range
            printf("Invalid floor number! Please choose a floor from 1 to %d.\n\n", numFloors);
        } else if (destinationFloor == currentFloor) { // check if elevator is already on the selected floor
            printf("You are already on floor %d!\n\n", currentFloor);
        } else { // move elevator to selected floor
            moveElevator(currentFloor, destinationFloor, numFloors);
            currentFloor = destinationFloor;
            printStatus(currentFloor, numFloors);
        }
    } while (input != 'q'); // continue loop until user quits
    
    printf("Goodbye!\n");
    
    return 0;
}

void moveElevator(int currentFloor, int destinationFloor, int numFloors) // simulate elevator movement
{
    printf("Moving elevator from floor %d to floor %d...\n", currentFloor, destinationFloor);
    
    if (currentFloor < destinationFloor) {
        for (int i = currentFloor; i < destinationFloor; i++) {
            printf("Passing floor %d...\n", i+1);
        }
    } else {
        for (int i = currentFloor; i > destinationFloor; i--) {
            printf("Passing floor %d...\n", i-1);
        }
    }
    
    printf("Elevator has arrived at floor %d!\n\n", destinationFloor);
}

void printStatus(int currentFloor, int numFloors) // display elevator status
{
    printf("Current floor: %d\n", currentFloor);
    
    if (currentFloor == 1) {
        printf("You are on the ground floor.\n\n");
    } else if (currentFloor == numFloors) {
        printf("You are on the top floor.\n\n");
    } else {
        printf("You are currently between floors.\n\n");
    }
}