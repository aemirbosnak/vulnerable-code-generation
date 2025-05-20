//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: excited
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    int destinationFloor;
    int isMoving;
} Elevator;

void initializeElevator(Elevator* elev) {
    elev->currentFloor = 0; // Start at ground floor
    elev->destinationFloor = 0;
    elev->isMoving = 0;
}

void moveElevator(Elevator* elev) {
    if (elev->isMoving) {
        if (elev->currentFloor < elev->destinationFloor) {
            elev->currentFloor++;
        } else if (elev->currentFloor > elev->destinationFloor) {
            elev->currentFloor--;
        }
        printf("Elevator is currently at floor %d\n", elev->currentFloor);
        if (elev->currentFloor == elev->destinationFloor) {
            elev->isMoving = 0;
            printf("Ding! You've reached floor %d\n", elev->currentFloor);
        }
    }
}

void requestElevator(Elevator* elev) {
    printf("Requesting elevator to which floor (0-%d)? ", MAX_FLOORS - 1);
    scanf("%d", &elev->destinationFloor);
    
    if (elev->destinationFloor < 0 || elev->destinationFloor >= MAX_FLOORS) {
        printf("Invalid floor! Try again.\n");
        elev->destinationFloor = elev->currentFloor; // Reset
    } else {
        elev->isMoving = 1;
        printf("Elevator moving to floor %d...\n", elev->destinationFloor);
    }
}

int main() {
    Elevator elev;
    initializeElevator(&elev);
    printf("🚀 Welcome to the Amazing Elevator Simulator! 🚀\n");

    while (1) {
        requestElevator(&elev);
        
        // Simulate elevator moving
        while (elev.isMoving) {
            moveElevator(&elev);
            usleep(500000); // Sleep for a while to simulate movement
        }
        
        char choice;
        printf("Do you want to request another floor? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        } else {
            printf("Let’s go again! 🌟\n");
        }
    }

    printf("Thank you for using the Amazing Elevator Simulator! See you next time! 🏢✨\n");
    return 0;
}