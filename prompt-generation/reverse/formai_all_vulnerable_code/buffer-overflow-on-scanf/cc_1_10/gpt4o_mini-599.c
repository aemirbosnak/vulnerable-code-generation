//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_RIDES 50

typedef struct {
    int currentFloor;
    bool isMovingUp;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // Start at ground floor
    elevator->isMovingUp = true; // Initial direction
    printf("Elevator initialized at ground floor 0. Thank you for a smooth start!\n");
}

void requestFloor(Elevator *elevator, int requestedFloor) {
    printf("Request received for floor %d. Bringing you joy!\n", requestedFloor);
    
    if (requestedFloor < 0 || requestedFloor >= MAX_FLOORS) {
        printf("Requested floor %d is out of service. Thank you for your understanding!\n", requestedFloor);
        return;
    }

    while (elevator->currentFloor != requestedFloor) {
        elevator->isMovingUp = elevator->currentFloor < requestedFloor;
        if (elevator->isMovingUp) {
            elevator->currentFloor++;
        } else {
            elevator->currentFloor--;
        }
        
        printf("Elevator is now at floor %d. Elevator is grateful to serve you!\n", elevator->currentFloor);
        sleep(1); // Simulate time taken to move
    }

    printf("You have arrived at floor %d! Have a wonderful day!\n", elevator->currentFloor);
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    
    int requests[MAX_RIDES];
    int numRequests, i;

    printf("How many rides would you like to request today (max %d rides)? ", MAX_RIDES);
    scanf("%d", &numRequests);

    if (numRequests > MAX_RIDES) {
        printf("Wow! That's ambitious! Limiting to %d rides.\n", MAX_RIDES);
        numRequests = MAX_RIDES;
    }
    
    printf("Please enter your requested floors (0 to %d):\n", MAX_FLOORS - 1);
    for (i = 0; i < numRequests; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }

    for (i = 0; i < numRequests; i++) {
        requestFloor(&elevator, requests[i]);
    }

    printf("Thank you for using our elevator service today! We look forward to serving you again!\n");
    
    return 0;
}