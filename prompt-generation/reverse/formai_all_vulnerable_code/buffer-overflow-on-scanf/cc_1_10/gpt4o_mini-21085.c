//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int currentFloor;
    int destinationFloor;
    int passengers;
} Elevator;

void displayFloor(int floor) {
    printf("\n\n---------------------\n");
    printf("   You are on Floor %d\t\n", floor);
    printf("---------------------\n\n");
}

void requestElevator(int currentFloor) {
    printf("Elevator requested to Floor %d\n", currentFloor);
}

void moveElevator(Elevator *elevator) {
    if (elevator->currentFloor < elevator->destinationFloor) {
        elevator->currentFloor++;
    } else if (elevator->currentFloor > elevator->destinationFloor) {
        elevator->currentFloor--;
    }
    displayFloor(elevator->currentFloor);
}

bool boardElevator(Elevator *elevator) {
    if (elevator->passengers < ELEVATOR_CAPACITY) {
        elevator->passengers++;
        printf("A passenger boarded the elevator. Total Passengers: %d\n", elevator->passengers);
        return true;
    } else {
        printf("Elevator is full! Cannot board.\n");
        return false;
    }
}

void exitElevator(Elevator *elevator) {
    if (elevator->passengers > 0) {
        elevator->passengers--;
        printf("A passenger exited the elevator. Total Passengers: %d\n", elevator->passengers);
    } else {
        printf("No passengers to exit.\n");
    }
}

void simulateElevatorSystem() {
    Elevator elevator = {0, 0, 0};
    int userChoice;

    while (true) {
        printf("Elevator Simulation:\n");
        printf("1. Call Elevator to a Floor (0-%d)\n", MAX_FLOORS - 1);
        printf("2. Board Elevator\n");
        printf("3. Exit Elevator\n");
        printf("4. Set Destination Floor (0-%d)\n", MAX_FLOORS - 1);
        printf("5. Move Elevator\n");
        printf("6. Exit Simulation\n");
        printf("Choose an option: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1: {
                int floor;
                printf("Enter the floor to call the elevator (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                requestElevator(floor);
                elevator.currentFloor = floor;  // Simulating the elevator arriving
                displayFloor(elevator.currentFloor);
                break;
            }
            case 2:
                if (boardElevator(&elevator)) {
                    printf("You boarded the elevator on Floor %d.\n", elevator.currentFloor);
                }
                break;
            case 3:
                exitElevator(&elevator);
                break;
            case 4: {
                int destination;
                printf("Enter the destination floor (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &destination);
                if (destination >= 0 && destination < MAX_FLOORS) {
                    elevator.destinationFloor = destination;
                    printf("Elevator will go to Floor %d.\n", elevator.destinationFloor);
                } else {
                    printf("Invalid floor number. Please choose again.\n");
                }
                break;
            }
            case 5:
                if (elevator.destinationFloor >= 0 && elevator.destinationFloor < MAX_FLOORS) {
                    printf("Moving to Floor %d...\n", elevator.destinationFloor);
                    while (elevator.currentFloor != elevator.destinationFloor) {
                        moveElevator(&elevator);
                        sleep(1);
                    }
                    printf("You have arrived at Floor %d.\n", elevator.destinationFloor);
                } else {
                    printf("No destination selected. Please set a destination first.\n");
                }
                break;
            case 6:
                printf("Exiting the simulation. Thank you!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }
}

int main() {
    simulateElevatorSystem();
    return 0;
}