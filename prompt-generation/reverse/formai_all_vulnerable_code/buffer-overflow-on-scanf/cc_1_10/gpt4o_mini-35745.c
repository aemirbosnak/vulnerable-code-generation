//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Ada Lovelace
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
    elevator->currentFloor = 0;  // Start on the ground floor
    elevator->doorsOpen = false; // Doors starting closed
}

void openDoors(Elevator *elevator) {
    if (!elevator->doorsOpen) {
        printf("Opening doors on floor %d...\n", elevator->currentFloor);
        elevator->doorsOpen = true;
    } else {
        printf("The doors are already open on floor %d.\n", elevator->currentFloor);
    }
}

void closeDoors(Elevator *elevator) {
    if (elevator->doorsOpen) {
        printf("Closing doors on floor %d...\n", elevator->currentFloor);
        elevator->doorsOpen = false;
    } else {
        printf("The doors are already closed on floor %d.\n", elevator->currentFloor);
    }
}

void moveElevator(Elevator *elevator, int targetFloor) {
    if (targetFloor < 0 || targetFloor >= MAX_FLOORS) {
        printf("Invalid floor! Please choose a floor between 0 and %d.\n", MAX_FLOORS - 1);
        return;
    }
    closeDoors(elevator);
    
    while (elevator->currentFloor != targetFloor) {
        if (elevator->currentFloor < targetFloor) {
            elevator->currentFloor++;
        } else {
            elevator->currentFloor--;
        }
        printf("Elevator is on floor %d...\n", elevator->currentFloor);
        sleep(1); // Simulate time taken to move to the next floor
    }
    openDoors(elevator);
}

int main() {
    Elevator elevator;
    int targetFloor;
    char command;

    initializeElevator(&elevator);

    printf("Welcome to the Elevator Simulation!\n");
    printf("The elevator is currently at floor %d.\n", elevator.currentFloor);

    while (true) {
        printf("\nWhat would you like to do?\n");
        printf("1. Move to a floor (Enter floor number: 0 to %d)\n", MAX_FLOORS - 1);
        printf("2. Exit the simulation (Press 'e')\n");
        
        if (elevator.doorsOpen) {
            printf("3. Close doors (Press 'c')\n");
        } else {
            printf("4. Open doors (Press 'o')\n");
        }

        printf("Your selection: ");
        scanf(" %c", &command);

        if (command == '1') {
            printf("Enter the floor number you wish to go to: ");
            scanf("%d", &targetFloor);
            moveElevator(&elevator, targetFloor);
        } else if (command == '2') {
            printf("Exiting the simulation. Goodbye!\n");
            break;
        } else if (command == '3' && elevator.doorsOpen) {
            closeDoors(&elevator);
        } else if (command == '4' && !elevator.doorsOpen) {
            openDoors(&elevator);
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    }

    return 0;
}