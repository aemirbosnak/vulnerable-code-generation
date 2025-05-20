//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> // For sleep()

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    bool doorsOpen;
} Elevator;

void initElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // Start at ground floor
    elevator->doorsOpen = false; // Doors initially closed
}

void openDoors(Elevator *elevator) {
    if (!elevator->doorsOpen) {
        elevator->doorsOpen = true;
        printf("The doors are now open at floor %d.\n", elevator->currentFloor);
    } else {
        printf("The doors are already open! Come on in!\n");
    }
}

void closeDoors(Elevator *elevator) {
    if (elevator->doorsOpen) {
        elevator->doorsOpen = false;
        printf("Clanging metal sounds as the doors close...\n");
    } else {
        printf("The doors are already closed!\n");
    }
}

void moveToFloor(Elevator *elevator, int destinationFloor) {
    if (destinationFloor < 0 || destinationFloor >= MAX_FLOORS) {
        printf("Invalid floor selection. Please choose a floor between 0 and %d.\n", MAX_FLOORS - 1);
        return;
    }

    closeDoors(elevator);
    printf("Moving from floor %d to floor %d...\n", elevator->currentFloor, destinationFloor);
    sleep(2); // Simulate time taken to move
    elevator->currentFloor = destinationFloor;
    openDoors(elevator);
}

void displayMenu() {
    printf("\n=== Elevator Control ===\n");
    printf("1. Go to a specific floor\n");
    printf("2. Open doors\n");
    printf("3. Close doors\n");
    printf("4. Exit simulation\n");
    printf("========================\n");
}

int main() {
    Elevator elevator;
    initElevator(&elevator);

    int choice;
    
    while (true) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int floor;
                printf("Enter floor number (0 - %d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                moveToFloor(&elevator, floor);
                break;
            }
            case 2:
                openDoors(&elevator);
                break;
            case 3:
                closeDoors(&elevator);
                break;
            case 4:
                printf("Exiting simulation. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}