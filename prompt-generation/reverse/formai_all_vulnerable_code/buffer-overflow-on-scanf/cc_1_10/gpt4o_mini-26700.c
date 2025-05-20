//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct {
    int currentFloor;
    int direction; // 1 for up, -1 for down
    int passengers[MAX_PASSENGERS];
    int numPassengers;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0;
    elevator->direction = 0;
    elevator->numPassengers = 0;
    for(int i = 0; i < MAX_PASSENGERS; i++) {
        elevator->passengers[i] = -1; 
    }
}

void callElevator(Elevator *elevator, int requestedFloor) {
    if(requestedFloor < 0 || requestedFloor >= MAX_FLOORS) {
        printf("Invalid floor requested.\n");
        return;
    }
    elevator->direction = (requestedFloor > elevator->currentFloor) ? 1 : -1;
    printf("Elevator called to floor %d\n", requestedFloor);
}

void moveElevator(Elevator *elevator) {
    if(elevator->direction != 0) {
        printf("Elevator is moving %s to floor %d...\n", 
                elevator->direction == 1 ? "up" : "down", 
                elevator->currentFloor + elevator->direction);
        sleep(1); // Simulates the time taken to move
        elevator->currentFloor += elevator->direction;

        if(elevator->currentFloor == 0 || elevator->currentFloor == MAX_FLOORS - 1) {
            elevator->direction = 0; // Reached the limit floor
        }
    } else {
        printf("Elevator is idle on floor %d\n", elevator->currentFloor);
    }
}

void boardElevator(Elevator *elevator, int passengerID) {
    if(elevator->numPassengers < MAX_PASSENGERS) {
        elevator->passengers[elevator->numPassengers++] = passengerID;
        printf("Passenger %d boarded the elevator on floor %d\n", passengerID, elevator->currentFloor);
    } else {
        printf("Elevator is full. Passenger %d cannot board.\n", passengerID);
    }
}

void disembarkElevator(Elevator *elevator, int passengerID) {
    for(int i = 0; i < elevator->numPassengers; i++) {
        if(elevator->passengers[i] == passengerID) {
            printf("Passenger %d disembarked the elevator on floor %d\n", passengerID, elevator->currentFloor);
            for(int j = i; j < elevator->numPassengers - 1; j++) {
                elevator->passengers[j] = elevator->passengers[j + 1];
            }
            elevator->numPassengers--;
            elevator->passengers[elevator->numPassengers] = -1; // Clear last passenger
            return;
        }
    }
    printf("Passenger %d not found in the elevator.\n", passengerID);
}

void displayElevatorStatus(Elevator *elevator) {
    printf("Elevator status: Current floor %d, Passengers: ", elevator->currentFloor);
    for(int i = 0; i < elevator->numPassengers; i++) {
        printf("%d ", elevator->passengers[i]);
    }
    printf("\n");
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);

    // Simulation loop
    int option, floor, passengerID;
    while(1) {
        printf("\n--- Elevator Simulation ---\n");
        printf("1. Call Elevator\n");
        printf("2. Board Elevator\n");
        printf("3. Disembark Elevator\n");
        printf("4. Move Elevator\n");
        printf("5. Display Elevator Status\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("Enter floor to call elevator (0 to %d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                callElevator(&elevator, floor);
                break;
            case 2:
                printf("Enter passenger ID to board: ");
                scanf("%d", &passengerID);
                boardElevator(&elevator, passengerID);
                break;
            case 3:
                printf("Enter passenger ID to disembark: ");
                scanf("%d", &passengerID);
                disembarkElevator(&elevator, passengerID);
                break;
            case 4:
                moveElevator(&elevator);
                break;
            case 5:
                displayElevatorStatus(&elevator);
                break;
            case 6:
                printf("Exiting simulation...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}