//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_REQUESTS 50

typedef struct {
    int floor; // Requested floor number
} Request;

typedef struct {
    Request requests[MAX_REQUESTS];
    int count; // Number of requests
} RequestQueue;

typedef struct {
    int currentFloor;
    RequestQueue queue;    
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // Start at ground floor
    elevator->queue.count = 0;   // No requests initially
}

void addRequest(Elevator *elevator, int floor) {
    if (elevator->queue.count < MAX_REQUESTS && floor >= 0 && floor < MAX_FLOORS) {
        elevator->queue.requests[elevator->queue.count].floor = floor;
        elevator->queue.count++;
        printf("Request added to floor %d.\n", floor);
    } else {
        printf("Could not add request. Queue full or invalid floor.\n");
    }
}

void processRequests(Elevator *elevator) {
    while (elevator->queue.count > 0) {
        int nextFloor = elevator->queue.requests[0].floor;
        printf("Moving to floor %d...\n", nextFloor);
        sleep(1); // Simulating time taken to move
        elevator->currentFloor = nextFloor;
        printf("Arrived at floor %d.\n", nextFloor);
        
        // Shift requests down
        for (int i = 0; i < elevator->queue.count - 1; i++) {
            elevator->queue.requests[i] = elevator->queue.requests[i + 1];
        }
        elevator->queue.count--;
    }
}

void displayMenu() {
    printf("Elevator Simulation Menu:\n");
    printf("1. Add request\n");
    printf("2. Process requests\n");
    printf("3. Exit\n");
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    
    int option, floor;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter floor (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                addRequest(&elevator, floor);
                break;
            case 2:
                processRequests(&elevator);
                break;
            case 3:
                printf("Exiting the elevator simulation.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    
    return 0;
}