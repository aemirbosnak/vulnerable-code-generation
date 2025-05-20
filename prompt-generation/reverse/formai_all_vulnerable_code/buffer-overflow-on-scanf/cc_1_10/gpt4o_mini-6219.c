//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 1

typedef struct {
    int currentFloor;
    int direction; // -1 for down, 1 for up, 0 for idle
} Elevator;

typedef struct {
    int requests[MAX_FLOORS];
} RequestQueue;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0;
    elevator->direction = 0;
}

void initializeRequestQueue(RequestQueue *queue) {
    for(int i = 0; i < MAX_FLOORS; i++) {
        queue->requests[i] = 0;
    }
}

void requestElevator(RequestQueue *queue, int floor) {
    if(floor >= 0 && floor < MAX_FLOORS) {
        queue->requests[floor]++;
    } else {
        printf("Invalid floor request!\n");
    }
}

void moveElevator(Elevator *elevator) {
    if(elevator->direction == 1 && elevator->currentFloor < MAX_FLOORS - 1) {
        elevator->currentFloor++;
    } else if(elevator->direction == -1 && elevator->currentFloor > 0) {
        elevator->currentFloor--;
    }
}

void determineDirection(Elevator *elevator, RequestQueue *queue) {
    bool hasRequests = false;
    for(int i = 0; i < MAX_FLOORS; i++) {
        if(queue->requests[i] > 0) {
            hasRequests = true;
            break;
        }
    }
    
    if(!hasRequests) {
        elevator->direction = 0; // idle if no requests
        return;
    }

    if(elevator->currentFloor == MAX_FLOORS - 1) {
        elevator->direction = -1; // set to down if at top floor
    } else if(elevator->currentFloor == 0) {
        elevator->direction = 1; // set to up if at ground floor
    } else {
        elevator->direction = (queue->requests[elevator->currentFloor + 1] > 0) ? 1 : -1;
    }
}

void serveRequests(Elevator *elevator, RequestQueue *queue) {
    if(queue->requests[elevator->currentFloor] > 0) {
        printf("Stopping at floor %d to serve %d request(s).\n", elevator->currentFloor, queue->requests[elevator->currentFloor]);
        queue->requests[elevator->currentFloor] = 0; // serve the requests
    }
}

int main() {
    Elevator elevator[MAX_ELEVATORS];
    RequestQueue queue;
    int floorRequest;

    initializeElevator(&elevator[0]);
    initializeRequestQueue(&queue);

    while(true) {
        printf("Current Elevator Floor: %d\n", elevator[0].currentFloor);
        printf("Enter Floor Request (0 to %d), or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &floorRequest);

        if(floorRequest == -1) {
            break; // exit the simulation
        } else {
            requestElevator(&queue, floorRequest);
        }

        determineDirection(&elevator[0], &queue);
        moveElevator(&elevator[0]);
        serveRequests(&elevator[0], &queue);

        printf("Elevator is moving %s.\n", elevator[0].direction == 1 ? "up" : elevator[0].direction == -1 ? "down" : "idle");
        sleep(1); // simulate time delay for elevator movement
    }

    printf("Elevator simulation ended.\n");
    return 0;
}