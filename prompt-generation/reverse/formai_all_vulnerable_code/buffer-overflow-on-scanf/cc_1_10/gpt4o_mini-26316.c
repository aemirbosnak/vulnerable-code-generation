//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    bool movingUp;
} Elevator;

void printElevatorStatus(Elevator *elevator) {
    printf("🚀 Elevator is on floor %d, moving %s! 🎉\n", elevator->currentFloor, elevator->movingUp ? "up" : "down");
}

void moveElevator(Elevator *elevator, int targetFloor) {
    if (targetFloor < 0 || targetFloor >= MAX_FLOORS) {
        printf("❌ That's not a valid floor!\n");
        return;
    }

    if (targetFloor == elevator->currentFloor) {
        printf("🏢 You're already on floor %d!\n", targetFloor);
        return;
    }

    if (targetFloor > elevator->currentFloor) {
        elevator->movingUp = true;
        while (elevator->currentFloor < targetFloor) {
            sleep(1); // Simulating movement
            elevator->currentFloor++;
            printElevatorStatus(elevator);
        }
    } else {
        elevator->movingUp = false;
        while (elevator->currentFloor > targetFloor) {
            sleep(1); // Simulating movement
            elevator->currentFloor--;
            printElevatorStatus(elevator);
        }
    }
    
    printf("🎈 You've arrived at floor %d! Welcome! 🎉\n", targetFloor);
}

int main() {
    Elevator elevator = {0, true};
    
    while (true) {
        int targetFloor;
        printf("\n🌈 Welcome to the Happy Elevator Simulation! 🌈\n");
        printf("You are currently on floor %d. 🎈\n", elevator.currentFloor);
        printf("Please select a floor (0 to %d) or -1 to exit: ", MAX_FLOORS - 1);
        
        scanf("%d", &targetFloor);
        
        if (targetFloor == -1) {
            printf("🚪 Thanks for riding! Have a fantastic day! 🌟\n");
            break;
        }
        
        moveElevator(&elevator, targetFloor);
    }

    return 0;
}