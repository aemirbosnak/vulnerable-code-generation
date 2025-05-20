//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define TRUE 1
#define FALSE 0

typedef struct {
    int currentFloor;
    int requestedFloors[MAX_FLOORS];
    int numRequests;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // Start at the ground floor (0)
    elevator->numRequests = 0;
    for (int i = 0; i < MAX_FLOORS; i++) {
        elevator->requestedFloors[i] = FALSE;
    }
}

void displayCurrentState(Elevator *elevator) {
    printf("\nElevator is currently on floor %d.\n", elevator->currentFloor + 1);
    printf("Pending requests: ");
    for (int i = 0; i < MAX_FLOORS; i++) {
        if (elevator->requestedFloors[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

void requestFloor(Elevator *elevator, int floor) {
    if (floor < 1 || floor > MAX_FLOORS) {
        printf("Invalid floor selection. Please choose a floor between 1 and %d.\n", MAX_FLOORS);
    } else if (elevator->requestedFloors[floor - 1]) {
        printf("Floor %d has already been requested.\n", floor);
    } else {
        elevator->requestedFloors[floor - 1] = TRUE;
        elevator->numRequests++;
        printf("Floor %d requested.\n", floor);
    }
}

void moveToNextFloor(Elevator *elevator) {
    for (int i = 0; i < MAX_FLOORS; i++) {
        if (elevator->requestedFloors[i]) {
            elevator->requestedFloors[i] = FALSE;
            elevator->numRequests--;
            printf("Moving to floor %d...\n", i + 1);
            elevator->currentFloor = i;
            return;
        }
    }
    printf("No more requests. Elevator is idle.\n");
}

void displayMenu() {
    printf("\n=== Elevator Simulation ===\n");
    printf("1. Request a floor\n");
    printf("2. Move to next requested floor\n");
    printf("3. Display current elevator state\n");
    printf("4. Exit\n");
    printf("==========================\n");
}

int main() {
    Elevator elevator;
    char choice;
    int requestedFloor;

    initializeElevator(&elevator);

    while (TRUE) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        choice = getchar();
        while (getchar() != '\n'); // Clear input buffer

        switch (choice) {
            case '1':
                printf("Enter the floor number you want to request (1 to %d): ", MAX_FLOORS);
                scanf("%d", &requestedFloor);
                while (getchar() != '\n'); // Clear input buffer
                requestFloor(&elevator, requestedFloor);
                break;
            case '2':
                moveToNextFloor(&elevator);
                break;
            case '3':
                displayCurrentState(&elevator);
                break;
            case '4':
                printf("Exiting the elevator simulation. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}