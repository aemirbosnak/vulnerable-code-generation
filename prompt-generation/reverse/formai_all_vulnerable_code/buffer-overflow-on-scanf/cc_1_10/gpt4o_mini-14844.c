//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int currentFloor;
    int capacity;
    int passengers[MAX_CAPACITY];
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // Start at ground floor
    elevator->capacity = 0; // No passengers initially
    for (int i = 0; i < MAX_CAPACITY; i++) {
        elevator->passengers[i] = -1; // No passengers
    }
}

void displayElevatorStatus(Elevator *elevator) {
    printf("Elevator is currently at floor %d and carrying %d passengers: ", elevator->currentFloor, elevator->capacity);
    for (int i = 0; i < elevator->capacity; i++) {
        if (elevator->passengers[i] != -1) {
            printf("%d ", elevator->passengers[i]);
        }
    }
    printf("\n");
}

void callElevator(Elevator *elevator, int requestedFloor) {
    if (requestedFloor < 0 || requestedFloor >= MAX_FLOORS) {
        printf("Invalid floor: %d. Please choose a floor between 0 and %d.\n", requestedFloor, MAX_FLOORS - 1);
        return;
    }
    
    printf("Elevator called to floor %d.\n", requestedFloor);
    while (elevator->currentFloor != requestedFloor) {
        printf("Moving to floor %d...\n", elevator->currentFloor < requestedFloor ? elevator->currentFloor + 1 : elevator->currentFloor - 1);
        sleep(1); // Simulate the time taken to move between floors
        elevator->currentFloor += (elevator->currentFloor < requestedFloor) ? 1 : -1;
    }
    printf("Elevator has arrived at floor %d.\n", elevator->currentFloor);
}

void boardPassenger(Elevator *elevator, int passengerID) {
    if (elevator->capacity >= MAX_CAPACITY) {
        printf("Sorry, the elevator is full! Cannot board passenger %d.\n", passengerID);
        return;
    }
    elevator->passengers[elevator->capacity++] = passengerID;
    printf("Passenger %d boarded the elevator. Total passengers: %d\n", passengerID, elevator->capacity);
}

void deboardPassenger(Elevator *elevator, int passengerID) {
    int found = 0;
    for (int i = 0; i < elevator->capacity; i++) {
        if (elevator->passengers[i] == passengerID) {
            found = 1;
            printf("Passenger %d has deboarded from the elevator.\n", passengerID);
            for (int j = i; j < elevator->capacity - 1; j++) {
                elevator->passengers[j] = elevator->passengers[j + 1];
            }
            elevator->passengers[elevator->capacity - 1] = -1; // Reset last passenger
            elevator->capacity--;
            break;
        }
    }
    if (!found) {
        printf("Passenger %d not found in the elevator.\n", passengerID);
    }
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    
    int choice;
    while (1) {
        printf("\nElevator System Menu:\n");
        printf("1. Call Elevator\n");
        printf("2. Board Passenger\n");
        printf("3. Deboard Passenger\n");
        printf("4. View Elevator Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int floor;
                printf("Enter the floor to call the elevator (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                callElevator(&elevator, floor);
                break;
            }
            case 2: {
                int passengerID;
                printf("Enter the passenger ID to board: ");
                scanf("%d", &passengerID);
                boardPassenger(&elevator, passengerID);
                break;
            }
            case 3: {
                int passengerID;
                printf("Enter the passenger ID to deboard: ");
                scanf("%d", &passengerID);
                deboardPassenger(&elevator, passengerID);
                break;
            }
            case 4:
                displayElevatorStatus(&elevator);
                break;
            case 5:
                printf("Exiting the elevator system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }
    
    return 0;
}