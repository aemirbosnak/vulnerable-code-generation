//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10

// Function prototypes
void moveElevator(int currentFloor, int requestedFloor);
void displayStatus(int currentFloor, int requestedFloor);
int getRequestedFloor();

int main() {
    int currentFloor = 0; // Start at ground floor
    int requestedFloor;

    printf("Welcome to the Elevator Simulation Program!\n");
    printf("This building has %d floors (0 to %d).\n", MAX_FLOORS, MAX_FLOORS - 1);

    while (1) {
        requestedFloor = getRequestedFloor();

        if (requestedFloor == -1) {
            printf("Exiting the elevator simulation. Goodbye!\n");
            break; // Exit the loop if -1 is entered
        }
        
        if (requestedFloor >= 0 && requestedFloor < MAX_FLOORS) {
            moveElevator(currentFloor, requestedFloor);
            currentFloor = requestedFloor; // Update current floor to the requested floor
        } else {
            printf("Invalid floor selected. Please choose a floor between 0 and %d.\n", MAX_FLOORS - 1);
        }
    }

    return 0;
}

// Function to get the requested floor from user input
int getRequestedFloor() {
    int floor;
    printf("Please enter the floor you want to go to (0 to %d), or -1 to exit: ", MAX_FLOORS - 1);
    scanf("%d", &floor);
    return floor;
}

// Function to simulate moving the elevator
void moveElevator(int currentFloor, int requestedFloor) {
    printf("Elevator moving from floor %d to floor %d...\n", currentFloor, requestedFloor);
    if (requestedFloor > currentFloor) {
        for (int i = currentFloor + 1; i <= requestedFloor; i++) {
            printf("Passing floor %d...\n", i);
        }
    } else if (requestedFloor < currentFloor) {
        for (int i = currentFloor - 1; i >= requestedFloor; i--) {
            printf("Passing floor %d...\n", i);
        }
    }
    // Final arrival notification
    displayStatus(currentFloor, requestedFloor);
}

// Function to display the elevator status upon arrival
void displayStatus(int currentFloor, int requestedFloor) {
    printf("Elevator has arrived at floor %d.\n", currentFloor);
    if (currentFloor == requestedFloor) {
        printf("You have reached your destination!\n\n");
    }
}