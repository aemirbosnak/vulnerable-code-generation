//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    bool direction; // 0 = up, 1 = down
    bool requests[MAX_FLOORS]; // requests array
} Elevator;

void initializeElevator(Elevator* elevator) {
    elevator->currentFloor = 0; // start at ground floor
    elevator->direction = 0; // starts moving upwards
    for (int i = 0; i < MAX_FLOORS; i++) {
        elevator->requests[i] = false; // no requests initially
    }
}

void displayStatus(Elevator* elevator) {
    printf("Elevator is currently on floor %d. ", elevator->currentFloor);
    if (elevator->direction == 0) {
        printf("Moving UP.\n");
    } else {
        printf("Moving DOWN.\n");
    }
    printf("Current requests: ");
    for (int i = 0; i < MAX_FLOORS; i++) {
        if (elevator->requests[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void requestFloor(Elevator* elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor request! Please choose between 0 and %d.\n", MAX_FLOORS - 1);
        return;
    }
    elevator->requests[floor] = true;
    printf("Request received for floor %d.\n", floor);
}

void moveElevator(Elevator* elevator) {
    while (true) {
        displayStatus(elevator);
        usleep(1000000); // 1 second delay for realistic simulation

        // Check for requests
        bool requestExist = false;
        for (int i = 0; i < MAX_FLOORS; i++) {
            if (elevator->requests[i]) {
                requestExist = true;
                break;
            }
        }

        if (!requestExist) {
            printf("No requests, elevator is idling.\n");
            continue; // idle until a request is made
        }

        // Handle movement
        if (elevator->direction == 0) { // moving up
            if (elevator->currentFloor < MAX_FLOORS - 1) {
                elevator->currentFloor++;
            } else {
                elevator->direction = 1; // change direction if reached the top
            }
        } else { // moving down
            if (elevator->currentFloor > 0) {
                elevator->currentFloor--;
            } else {
                elevator->direction = 0; // change direction if reached the ground
            }
        }

        // Serve requests
        if (elevator->requests[elevator->currentFloor]) {
            printf("Arrived at floor %d. Serving request.\n", elevator->currentFloor);
            elevator->requests[elevator->currentFloor] = false; // clear the request
        }

        // Check if we need to change direction
        if (elevator->direction == 0 && !elevator->requests[elevator->currentFloor + 1]) {
            elevator->direction = 1; // change direction if no more requests above
        } else if (elevator->direction == 1 && !elevator->requests[elevator->currentFloor - 1]) {
            elevator->direction = 0; // change direction if no more requests below
        }
    }
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);

    int choice;
    while (true) {
        printf("\nElevator Simulation:\n");
        printf("1. Request Floor\n2. Exit\nChoose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int floor;
            printf("Enter floor number (0 - %d): ", MAX_FLOORS - 1);
            scanf("%d", &floor);
            requestFloor(&elevator, floor);
        } else if (choice == 2) {
            printf("Exiting elevator simulation.\n");
            break;
        } else {
            printf("Invalid input! Please select again.\n");
        }

        moveElevator(&elevator);
    }

    return 0;
}