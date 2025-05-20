//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int currentFloor;
    int passengers[MAX_CAPACITY];
    int numPassengers;
} Elevator;

void initElevator(Elevator *elevator) {
    elevator->currentFloor = 0;
    elevator->numPassengers = 0;
}

void printStatus(Elevator *elevator) {
    printf("Elevator is currently on floor: %d\n", elevator->currentFloor);
    printf("Number of passengers: %d\n", elevator->numPassengers);
    printf("Passengers IDs: ");
    for (int i = 0; i < elevator->numPassengers; i++) {
        printf("%d ", elevator->passengers[i]);
    }
    printf("\n\n");
}

bool pickUpPassenger(Elevator *elevator, int passengerID) {
    if (elevator->numPassengers < MAX_CAPACITY) {
        elevator->passengers[elevator->numPassengers++] = passengerID;
        printf("Passenger %d picked up.\n", passengerID);
        return true;
    } else {
        printf("Elevator is full! Can't pick up passenger %d.\n", passengerID);
        return false;
    }
}

void dropOffPassenger(Elevator *elevator, int passengerID) {
    for (int i = 0; i < elevator->numPassengers; i++) {
        if (elevator->passengers[i] == passengerID) {
            printf("Passenger %d dropped off.\n", passengerID);
            for (int j = i; j < elevator->numPassengers - 1; j++) {
                elevator->passengers[j] = elevator->passengers[j + 1];
            }
            elevator->numPassengers--;
            return;
        }
    }
}

void moveToFloor(Elevator *elevator, int targetFloor) {
    if (targetFloor < 0 || targetFloor >= MAX_FLOORS) {
        printf("Invalid floor request!\n");
        return;
    }

    printf("Moving from floor %d to floor %d...\n", elevator->currentFloor, targetFloor);
    
    // Simulating the movement
    while (elevator->currentFloor != targetFloor) {
        if (elevator->currentFloor < targetFloor) {
            elevator->currentFloor++;
        } else {
            elevator->currentFloor--;
        }
        printStatus(elevator);
        sleep(1); // Simulate time taken to move one floor
    }

    printf("Arrived at floor %d.\n", elevator->currentFloor);
}

void simulateElevator(Elevator *elevator) {
    char command;
    int passengerID;
    int targetFloor;

    while (1) {
        printf("Enter command (p: pick up, d: drop off, m: move, s: status, q: quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'p':
                printf("Enter passenger ID to pick up: ");
                scanf("%d", &passengerID);
                pickUpPassenger(elevator, passengerID);
                break;
            case 'd':
                printf("Enter passenger ID to drop off: ");
                scanf("%d", &passengerID);
                dropOffPassenger(elevator, passengerID);
                break;
            case 'm':
                printf("Enter target floor (0 to %d): ", MAX_FLOORS - 1);
                scanf("%d", &targetFloor);
                moveToFloor(elevator, targetFloor);
                break;
            case 's':
                printStatus(elevator);
                break;
            case 'q':
                printf("Exiting the elevator simulation.\n");
                return;
            default:
                printf("Invalid command!\n");
                break;
        }
    }
}

int main() {
    Elevator elevator;
    initElevator(&elevator);
    printf("Welcome to the Elevator Simulation!\n");
    simulateElevator(&elevator);
    return 0;
}