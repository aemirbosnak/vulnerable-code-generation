//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define TOTAL_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int currentFloor;
    int destinationFloor;
    int passengers;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // Ground floor
    elevator->destinationFloor = 0;
    elevator->passengers = 0;
}

void callElevator(Elevator *elevator, int requestedFloor) {
    if (requestedFloor < 0 || requestedFloor >= TOTAL_FLOORS) {
        printf("Error: Invalid floor! Choose between 0 and %d.\n", TOTAL_FLOORS - 1);
    } else {
        elevator->destinationFloor = requestedFloor;
        printf("Elevator called to floor %d!\n", requestedFloor);
    }
}

void enterElevator(Elevator *elevator) {
    if (elevator->passengers < MAX_CAPACITY) {
        elevator->passengers++;
        printf("A passenger entered the elevator. Passengers: %d\n", elevator->passengers);
    } else {
        printf("The elevator is at full capacity! No more passengers can enter.\n");
    }
}

void exitElevator(Elevator *elevator) {
    if (elevator->passengers > 0) {
        elevator->passengers--;
        printf("A passenger exited the elevator. Passengers: %d\n", elevator->passengers);
    } else {
        printf("Oops! No passengers in the elevator to exit.\n");
    }
}

void moveElevator(Elevator *elevator) {
    while (elevator->currentFloor != elevator->destinationFloor) {
        if (elevator->currentFloor < elevator->destinationFloor) {
            elevator->currentFloor++;
            printf("Going up! Current floor: %d\n", elevator->currentFloor);
        } else {
            elevator->currentFloor--;
            printf("Going down! Current floor: %d\n", elevator->currentFloor);
        }
        sleep(1); // Simulate time taken to move
    }
    printf("Arrived at floor %d!\n", elevator->currentFloor);
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);

    int action = -1, floor;

    while (action != 0) {
        printf("\n*** Elevator Simulation ***\n");
        printf("1. Call Elevator\n");
        printf("2. Enter Elevator\n");
        printf("3. Exit Elevator\n");
        printf("4. Move Elevator\n");
        printf("0. Exit Program\n");
        printf("Choose an action: ");
        scanf("%d", &action);

        switch (action) {
            case 1:
                printf("To which floor would you like to call the elevator? ");
                scanf("%d", &floor);
                callElevator(&elevator, floor);
                break;
            case 2:
                enterElevator(&elevator);
                break;
            case 3:
                exitElevator(&elevator);
                break;
            case 4:
                if (elevator.destinationFloor != elevator.currentFloor) {
                    moveElevator(&elevator);
                } else {
                    printf("The elevator is already on the requested floor!\n");
                }
                break;
            case 0:
                printf("Exiting... Thank you for using the elevator simulation!\n");
                break;
            default:
                printf("Unbelievable! Invalid option, please try again!\n");
                break;
        }
    }
    
    return 0;
}