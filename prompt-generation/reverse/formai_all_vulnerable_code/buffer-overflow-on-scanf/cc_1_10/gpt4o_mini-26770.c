//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int currentFloor;
    int targetFloor;
    int numPersons;
    int persons[ELEVATOR_CAPACITY];
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // Start at ground floor
    elevator->targetFloor = -1;  // No target floor initially
    elevator->numPersons = 0;     // No persons in the elevator
}

void requestElevator(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor request.\n");
        return;
    }

    if (elevator->targetFloor == -1 || elevator->targetFloor == floor) {
        elevator->targetFloor = floor;
        printf("Elevator requested to floor: %d\n", floor);
    } else {
        printf("Elevator is heading to floor: %d\n", elevator->targetFloor);
    }
}

void loadPersons(Elevator *elevator) {
    int personsToLoad = rand() % (ELEVATOR_CAPACITY + 1);
    
    if (elevator->numPersons + personsToLoad > ELEVATOR_CAPACITY) {
        personsToLoad = ELEVATOR_CAPACITY - elevator->numPersons;
    }

    printf("Loading %d persons into the elevator.\n", personsToLoad);
    for (int i = 0; i < personsToLoad; i++) {
        elevator->persons[elevator->numPersons] = rand() % MAX_FLOORS;
        elevator->numPersons++;
    }
}

void unloadPersons(Elevator *elevator) {
    int personsToUnload = rand() % (elevator->numPersons + 1);

    printf("Unloading %d persons from the elevator at floor %d.\n", personsToUnload, elevator->currentFloor);
    elevator->numPersons -= personsToUnload;
    if (elevator->numPersons < 0) {
        elevator->numPersons = 0;
    }
}

void moveElevator(Elevator *elevator) {
    if (elevator->targetFloor == -1) {
        printf("No target floor set. Elevator is idle.\n");
        return;
    }

    while (elevator->currentFloor != elevator->targetFloor) {
        if (elevator->currentFloor < elevator->targetFloor) {
            elevator->currentFloor++;
        } else {
            elevator->currentFloor--;
        }
        printf("Elevator moving... Current floor: %d\n", elevator->currentFloor);
        sleep(1); // Simulate time taken to move
    }

    printf("Elevator has arrived at the target floor: %d\n", elevator->currentFloor);
    unloadPersons(elevator);
    elevator->targetFloor = -1; // Reset target after arriving
}

void printElevatorStatus(Elevator *elevator) {
    printf("Elevator at floor %d with %d persons inside.\n", elevator->currentFloor, elevator->numPersons);
}

int main() {
    srand(time(NULL));
    Elevator elevator;
    int choice, floor;

    initializeElevator(&elevator);

    do {
        printf("\nElevator System Menu\n");
        printf("1. Request Elevator to Floor\n");
        printf("2. Load Persons\n");
        printf("3. Move Elevator\n");
        printf("4. View Elevator Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter target floor (0 to %d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                requestElevator(&elevator, floor);
                break;
            case 2:
                loadPersons(&elevator);
                break;
            case 3:
                moveElevator(&elevator);
                break;
            case 4:
                printElevatorStatus(&elevator);
                break;
            case 5:
                printf("Exiting elevator simulation.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}