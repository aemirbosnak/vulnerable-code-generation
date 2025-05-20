//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 3
#define MAX_REQUESTS 10

typedef struct {
    int startFloor;
    int endFloor;
    int direction;
    int elevator;
} request;

typedef struct {
    int currentFloor;
    int targetFloor;
} elevator;

elevator elevators[MAX_ELEVATORS];

void initializeElevators() {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].currentFloor = 0;
        elevators[i].targetFloor = 0;
    }
}

void moveElevator(int elevatorId, int targetFloor) {
    elevators[elevatorId].targetFloor = targetFloor;
}

void processRequest(request req) {
    int elevatorId = -1;
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        if (elevators[i].currentFloor == req.startFloor && elevators[i].targetFloor == 0) {
            elevatorId = i;
            break;
        }
    }
    if (elevatorId!= -1) {
        moveElevator(elevatorId, req.endFloor);
    }
}

int main() {
    initializeElevators();

    int numRequests = 0;
    request requests[MAX_REQUESTS];

    while (numRequests < MAX_REQUESTS) {
        printf("Enter start floor (0-%d): ", MAX_FLOORS - 1);
        scanf("%d", &requests[numRequests].startFloor);

        printf("Enter end floor (0-%d): ", MAX_FLOORS - 1);
        scanf("%d", &requests[numRequests].endFloor);

        printf("Enter direction (0=up, 1=down): ");
        scanf("%d", &requests[numRequests].direction);

        numRequests++;
    }

    for (int i = 0; i < numRequests; i++) {
        processRequest(requests[i]);
    }

    return 0;
}