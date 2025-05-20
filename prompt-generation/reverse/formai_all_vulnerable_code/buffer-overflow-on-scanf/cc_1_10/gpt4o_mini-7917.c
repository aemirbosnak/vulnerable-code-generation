//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> // for sleep()

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    int destinationFloor;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // starts from ground floor
    elevator->destinationFloor = -1; // no destination initially
}

void callElevator(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor! Please enter a floor between 0 and %d.\n", MAX_FLOORS - 1);
        return;
    }
    elevator->destinationFloor = floor;
    printf("Elevator called to floor %d.\n", floor);
}

void moveElevator(Elevator *elevator) {
    if (elevator->destinationFloor == -1) {
        printf("Elevator is idle at floor %d.\n", elevator->currentFloor);
        return;
    }

    printf("Elevator is moving from floor %d to floor %d.\n", elevator->currentFloor, elevator->destinationFloor);
    
    while (elevator->currentFloor != elevator->destinationFloor) {
        if (elevator->currentFloor < elevator->destinationFloor) {
            elevator->currentFloor++;
            printf("Elevator is now at floor %d.\n", elevator->currentFloor);
        } else {
            elevator->currentFloor--;
            printf("Elevator is now at floor %d.\n", elevator->currentFloor);
        }
        sleep(1); // simulate time taken to move between floors
    }

    printf("Elevator has arrived at the destination floor %d.\n", elevator->currentFloor);
    elevator->destinationFloor = -1; // reset destination after arrival
}

void displayMenu() {
    printf("\n---- Elevator Control ----\n");
    for (int i = 0; i < MAX_FLOORS; i++) {
        printf("Press %d to go to floor %d\n", i, i);
    }
    printf("Press %d to exit\n", MAX_FLOORS);
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    int userInput;

    while (true) {
        displayMenu();
        printf("Select a floor: ");
        scanf("%d", &userInput);

        if (userInput == MAX_FLOORS) {
            printf("Exiting the elevator simulation. Goodbye!\n");
            break;
        }

        callElevator(&elevator, userInput);
        moveElevator(&elevator);
    }

    return 0;
}