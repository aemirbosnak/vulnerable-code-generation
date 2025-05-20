//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

#define FLOOR_LOWEST 1
#define FLOOR_HIGHEST 10
#define ELEVATOR_MAX_CAPACITY 10

void clear() {
    system("clear");
}

void printFloorStatus(int floor, int direction, int count) {
    printf("Elevator is at floor %d, going %s, current passenger count: %d\n", floor, (direction == 1 ? "up" : "down"), count);
}

bool isGoingUp(int currentFloor, int destination) {
    return (destination - currentFloor) > 0;
}

int getNextFloor(int currentFloor, int direction) {
    return (direction == 1 ? currentFloor+1 : currentFloor-1);
}

bool isDestinationOnTheWay(int currentFloor, int destination, int direction) {
    if(direction == 1) {
        return (destination - currentFloor) > 0;
    } else {
        return (destination - currentFloor) < 0;
    }
}

bool isDestinationInElevator(int destination, int destinationList[], int count) {
    for(int i=0; i<count; i++) {
        if(destination == destinationList[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    int currentFloor = FLOOR_LOWEST;
    int direction = 1; // Up = 1, Down = -1
    int destinationCount = 0;
    int destinationList[ELEVATOR_MAX_CAPACITY];
    int passengerCount = 0;

    bool isOn = true;

    while(isOn) {
        clear();
        printFloorStatus(currentFloor, direction, passengerCount);

        // Check if there are any destinations to stop
        if(destinationCount > 0) {
            // Check if there is any destination in the way
            bool isDestinationInSameDirection = false;
            for(int i=0; i<destinationCount; i++) {
                if(isDestinationOnTheWay(currentFloor, destinationList[i], direction)) {
                    isDestinationInSameDirection = true;
                    break;
                }
            }

            if(isDestinationInSameDirection) {
                // Stop at the floor
                printf("Elevator is stopping at floor %d.\n", currentFloor);
                for(int i=0; i<destinationCount; i++) {
                    if(destinationList[i] == currentFloor) {
                        destinationList[i] = destinationList[destinationCount-1];
                        destinationCount--;
                        passengerCount--;
                        printf("A passenger has left the elevator. Current passenger count: %d\n", passengerCount);
                    }
                }
            } else {
                // Change direction
                printf("Elevator is changing direction.\n");
                direction = (direction == 1 ? -1 : 1);
            }
        }

        // Check if there are any passengers waiting on the floor
        if(passengerCount < ELEVATOR_MAX_CAPACITY) {
            int destination;
            printf("Any passenger waiting at current floor (1) or select destination (2): ");
            scanf("%d", &destination);

            if(destination == 1) {
                // Add passenger to elevator
                printf("A passenger has entered the elevator at floor %d.\n", currentFloor);
                destinationList[destinationCount] = currentFloor;
                destinationCount++;
                passengerCount++;
                printf("Current passenger count: %d\n", passengerCount);
            } else if(destination >= FLOOR_LOWEST && destination <= FLOOR_HIGHEST) {
                if(destination != currentFloor && !isDestinationInElevator(destination, destinationList, destinationCount)) {
                    // Add passenger to elevator
                    printf("A passenger has entered the elevator at floor %d.\n", currentFloor);
                    destinationList[destinationCount] = destination;
                    destinationCount++;
                    passengerCount++;
                    printf("Current passenger count: %d\n", passengerCount);
                } else {
                    printf("Invalid destination.\n");
                }
            } else {
                printf("Invalid input.\n");
            }
        }

        // Move to next floor
        currentFloor = getNextFloor(currentFloor, direction);
        if(currentFloor == FLOOR_LOWEST || currentFloor == FLOOR_HIGHEST) {
            direction = (direction == 1 ? -1 : 1);
        }
    }

    return 0;
}