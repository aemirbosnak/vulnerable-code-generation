//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct {
    int destination;
} Passenger;

typedef struct {
    int currentFloor;
    Passenger passengers[MAX_PASSENGERS];
    int passengerCount;
} Elevator;

void initializeElevator(Elevator* elevator) {
    elevator->currentFloor = 0; // Start at ground floor
    elevator->passengerCount = 0;
}

bool addPassenger(Elevator* elevator, int destination) {
    if (elevator->passengerCount < MAX_PASSENGERS && destination >= 0 && destination < MAX_FLOORS) {
        elevator->passengers[elevator->passengerCount].destination = destination;
        elevator->passengerCount++;
        printf("Added passenger to floor %d\n", destination);
        return true;
    }
    printf("Cannot add passenger. Elevator is full or invalid floor!\n");
    return false;
}

void removePassengers(Elevator* elevator) {
    for (int i = 0; i < elevator->passengerCount; i++) {
        if (elevator->passengers[i].destination == elevator->currentFloor) {
            printf("Passenger got off at floor %d\n", elevator->currentFloor);
            for (int j = i; j < elevator->passengerCount - 1; j++) {
                elevator->passengers[j] = elevator->passengers[j + 1];
            }
            elevator->passengerCount--;
            i--; // Adjust index after removal
        }
    }
}

void moveElevator(Elevator* elevator, int targetFloor) {
    if (targetFloor < 0 || targetFloor >= MAX_FLOORS) {
        printf("Invalid target floor!\n");
        return;
    }

    while (elevator->currentFloor != targetFloor) {
        if (elevator->currentFloor < targetFloor) {
            elevator->currentFloor++;
        } else {
            elevator->currentFloor--;
        }
        printf("Elevator at floor %d\n", elevator->currentFloor);
        sleep(1); // Simulate time taken to move
        removePassengers(elevator); // Check for passengers at current floor
    }
}

void displayPassengers(Elevator* elevator) {
    printf("Current Passengers in Elevator:\n");
    for (int i = 0; i < elevator->passengerCount; i++) {
        printf(" - Going to floor %d\n", elevator->passengers[i].destination);
    }
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    int choice;

    while (true) {
        printf("\nElevator Simulation Menu:\n");
        printf("1. Add Passenger\n");
        printf("2. Move Elevator\n");
        printf("3. View Passengers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int floor;
            printf("Enter destination floor (0-%d): ", MAX_FLOORS - 1);
            scanf("%d", &floor);
            addPassenger(&elevator, floor);
        } else if (choice == 2) {
            int floor;
            printf("Enter target floor (0-%d): ", MAX_FLOORS - 1);
            scanf("%d", &floor);
            moveElevator(&elevator, floor);
        } else if (choice == 3) {
            displayPassengers(&elevator);
        } else if (choice == 4) {
            printf("Exiting simulation.\n");
            break;
        } else {
            printf("Invalid choice! Please choose again.\n");
        }
    }
    
    return 0;
}