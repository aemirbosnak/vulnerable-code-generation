//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    int destinationFloor;
    bool requests[MAX_FLOORS]; // Whether there is a request for each floor
} Elevator;

void initializeElevator(Elevator* elevator) {
    elevator->currentFloor = 0; // Start at the ground floor
    elevator->destinationFloor = -1; // No destination initially
    for(int i = 0; i < MAX_FLOORS; i++) {
        elevator->requests[i] = false; // Initialize all requests to false
    }
}

void requestFloor(Elevator* elevator, int floor) {
    if (floor >= 0 && floor < MAX_FLOORS) {
        elevator->requests[floor] = true;
        printf("Request received for floor %d\n", floor);
    } else {
        printf("Invalid floor request.\n");
    }
}

void moveElevator(Elevator* elevator) {
    if (elevator->destinationFloor == -1) {
        // Find next request
        for(int i = 0; i < MAX_FLOORS; i++) {
            if (elevator->requests[i]) {
                elevator->destinationFloor = i;
                break;
            }
        }
        // If there are no requests, exit the function
        if (elevator->destinationFloor == -1) {
            printf("No requests to fulfill.\n");
            return;
        }
    }

    // Move elevator towards the destination floor
    if (elevator->currentFloor < elevator->destinationFloor) {
        elevator->currentFloor++;
        printf("Elevator moving up to floor %d\n", elevator->currentFloor);
    } else if (elevator->currentFloor > elevator->destinationFloor) {
        elevator->currentFloor--;
        printf("Elevator moving down to floor %d\n", elevator->currentFloor);
    }

    // Check if we've reached the destination
    if (elevator->currentFloor == elevator->destinationFloor) {
        printf("Elevator arrived at floor %d\n", elevator->currentFloor);
        elevator->requests[elevator->destinationFloor] = false; // Clear the request
        elevator->destinationFloor = -1; // Reset destination
    }
}

void printCurrentState(Elevator* elevator) {
    printf("Current floor: %d, Destination floor: %d\n", elevator->currentFloor, elevator->destinationFloor);
    printf("Pending requests: ");
    for (int i = 0; i < MAX_FLOORS; i++) {
        if (elevator->requests[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    srand(time(NULL)); // Seed for random floor requests

    // Simulation loop
    while (true) {
        printCurrentState(&elevator);
        
        int randomRequest = rand() % MAX_FLOORS;
        requestFloor(&elevator, randomRequest);
        moveElevator(&elevator);

        char input;
        printf("Continue simulation? (y/n): ");
        scanf(" %c", &input);
        if (input == 'n' || input == 'N') {
            break; // Exit the simulation loop
        }
    }

    printf("Exiting elevator simulation.\n");
    return 0;
}