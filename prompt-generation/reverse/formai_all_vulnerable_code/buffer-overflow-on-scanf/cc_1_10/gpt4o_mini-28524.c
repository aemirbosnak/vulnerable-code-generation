//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    bool doorsOpen;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 1; // Start at ground floor
    elevator->doorsOpen = false;
}

void callElevator(Elevator *elevator, int requestedFloor) {
    if (requestedFloor < 1 || requestedFloor > MAX_FLOORS) {
        printf("Invalid floor number.\n");
        return;
    }
    
    printf("Elevator called to floor %d...\n", requestedFloor);
    
    while (elevator->currentFloor != requestedFloor) {
        if (elevator->currentFloor < requestedFloor) {
            elevator->currentFloor++;
            printf("Elevator going up to floor %d...\n", elevator->currentFloor);
        } else {
            elevator->currentFloor--;
            printf("Elevator going down to floor %d...\n", elevator->currentFloor);
        }
        sleep(1);
    }
    
    elevator->doorsOpen = true;
    printf("Elevator has arrived at floor %d. Doors open.\n", elevator->currentFloor);
}

void closeDoors(Elevator *elevator) {
    if (elevator->doorsOpen) {
        elevator->doorsOpen = false;
        printf("Closing doors...\n");
        sleep(1);
        printf("Doors closed.\n");
    } else {
        printf("Doors are already closed.\n");
    }
}

void moveToFloor(Elevator *elevator, int targetFloor) {
    closeDoors(elevator);
    callElevator(elevator, targetFloor);
}

void displayMenu() {
    printf("\n=== Elevator Control ===\n");
    printf("1. Call Elevator\n");
    printf("2. Move to a Specific Floor\n");
    printf("3. Exit\n");
    printf("========================\n");
    printf("Select an option: ");
}

int main() {
    Elevator elevator;
    int choice, floor;

    initializeElevator(&elevator);

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter floor number to call elevator (1-%d): ", MAX_FLOORS);
                scanf("%d", &floor);
                callElevator(&elevator, floor);
                break;

            case 2:
                printf("Enter floor number to move to (1-%d): ", MAX_FLOORS);
                scanf("%d", &floor);
                if (floor != elevator.currentFloor) {
                    moveToFloor(&elevator, floor);
                } else {
                    printf("You are already on floor %d.\n", elevator.currentFloor);
                }
                break;

            case 3:
                printf("Exiting the elevator simulation. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}