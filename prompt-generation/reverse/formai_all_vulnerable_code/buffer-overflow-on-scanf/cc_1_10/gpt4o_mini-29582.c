//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    int requestedFloor;
    int direction; // 1 for up, -1 for down, 0 for idle
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 1; // Start at ground floor
    elevator->requestedFloor = -1; // No request yet
    elevator->direction = 0; // Idle
}

void displayMenu() {
    printf("Elevator Simulation Menu:\n");
    printf("1. Request Elevator\n");
    printf("2. Move Elevator\n");
    printf("3. Show Current Elevator Status\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void requestElevator(Elevator *elevator) {
    int floor;
    printf("Enter the floor number (1-%d): ", MAX_FLOORS);
    scanf("%d", &floor);
    
    if (floor < 1 || floor > MAX_FLOORS) {
        printf("Invalid floor. Please try again.\n");
        return;
    }
    
    elevator->requestedFloor = floor;
    elevator->direction = (elevator->currentFloor < floor) ? 1 : -1; // Determine direction
    printf("Elevator requested to floor %d.\n", floor);
}

void moveElevator(Elevator *elevator) {
    if (elevator->requestedFloor == -1) {
        printf("No floor requested.\n");
        return;
    }

    while (elevator->currentFloor != elevator->requestedFloor) {
        sleep(1); // Simulate time taken to move
        elevator->currentFloor += elevator->direction; // Move in the determined direction
        printf("Elevator is at floor %d...\n", elevator->currentFloor);
    }

    printf("Elevator has arrived at floor %d.\n", elevator->currentFloor);
    elevator->requestedFloor = -1; // Reset the request
    elevator->direction = 0; // Set to idle after arrival
}

void showStatus(Elevator *elevator) {
    printf("Current Floor: %d\n", elevator->currentFloor);
    if (elevator->requestedFloor != -1) {
        printf("Requested Floor: %d\n", elevator->requestedFloor);
        printf("Direction: %s\n", elevator->direction == 1 ? "Up" : "Down");
    } else {
        printf("No current requests.\n");
        printf("Direction: Idle\n");
    }
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    
    int choice;
    
    while (true) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                requestElevator(&elevator);
                break;
            case 2:
                moveElevator(&elevator);
                break;
            case 3:
                showStatus(&elevator);
                break;
            case 4:
                printf("Exiting the elevator simulation. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
    
    return 0;
}