//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

struct Elevator {
    int currentFloor;
    int destinationFloor;
    int direction; // 1 for up, -1 for down
};

void displayElevator(struct Elevator elevator) {
    if(elevator.direction == 1) {
        printf("Elevator going up from floor %d to floor %d\n", elevator.currentFloor, elevator.destinationFloor);
    } else {
        printf("Elevator going down from floor %d to floor %d\n", elevator.currentFloor, elevator.destinationFloor);
    }
}

void displayFloors(int activeFloor) {
    for(int i = NUM_FLOORS; i > 0; i--) {
        if(i == activeFloor) {
            printf("E ");
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

void moveElevator(struct Elevator *elevator) {
    if(elevator->currentFloor == elevator->destinationFloor) {
        elevator->direction = 0;
    } else if(elevator->currentFloor < elevator->destinationFloor) {
        elevator->currentFloor++;
    } else if(elevator->currentFloor > elevator->destinationFloor) {
        elevator->currentFloor--;
    }
}

int main() {
    struct Elevator elevators[NUM_ELEVATORS];
    int requests[NUM_FLOORS] = {0};

    elevators[0].currentFloor = 1;
    elevators[0].destinationFloor = 3;
    elevators[0].direction = 1;

    elevators[1].currentFloor = 6;
    elevators[1].destinationFloor = 2;
    elevators[1].direction = -1;

    elevators[2].currentFloor = 10;
    elevators[2].destinationFloor = 7;
    elevators[2].direction = -1;

    printf("*** ELEVATOR SIMULATION ***\n");

    while(1) {
        system("clear"); // Clear the console

        // Display current locations of elevators
        printf("Elevator Locations:\n");
        for(int i = 0; i < NUM_ELEVATORS; i++) {
            displayElevator(elevators[i]);
        }

        // Display the floors
        printf("\nFloor Status:\n");
        for(int i = NUM_FLOORS; i > 0; i--) {
            printf("%d ", i);
            if(requests[i-1] == 1) {
                printf("X ");
            } else {
                printf("- ");
            }
            displayFloors(i);
        }

        // Check for any new requests
        int floorRequest = 0;
        printf("\nEnter floor number (1-10) to request an elevator (0 to exit): ");
        scanf("%d", &floorRequest);
        if(floorRequest == 0) {
            break;
        }

        if(floorRequest < 1 || floorRequest > NUM_FLOORS) {
            printf("\nInvalid Floor Number. Please enter a number between 1 and 10.\n");
            continue;
        }

        // Check if an elevator is already heading towards that floor
        int elevatorFound = 0;
        for(int i = 0; i < NUM_ELEVATORS; i++) {
            if(elevators[i].destinationFloor == floorRequest && elevators[i].direction != 0) {
                printf("\nElevator already heading towards floor %d.\n", floorRequest);
                elevatorFound = 1;
                break;
            }
        }
        if(elevatorFound == 1) {
            continue;
        }

        // Find an available elevator
        int availableElevator = -1;
        int minDistance = NUM_FLOORS + 1;
        for(int i = 0; i < NUM_ELEVATORS; i++) {
            if(elevators[i].direction == 0 && abs(elevators[i].currentFloor - floorRequest) < minDistance) {
                availableElevator = i;
            }
        }
        if(availableElevator == -1) {
            printf("\nAll elevators are currently busy. Please wait.\n");
            requests[floorRequest-1] = 1;
            continue;
        }

        // Send the elevator to the requested floor
        elevators[availableElevator].destinationFloor = floorRequest;
        if(elevators[availableElevator].currentFloor < floorRequest) {
            elevators[availableElevator].direction = 1;
        } else {
            elevators[availableElevator].direction = -1;
        }
    }

    return 0;
}