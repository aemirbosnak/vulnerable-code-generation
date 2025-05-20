//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define ELEVATOR_IDLE 0
#define ELEVATOR_MOVING 1

typedef struct {
    int currentFloor;
    int targetFloor;
    int state;
} Elevator;

void moveElevator(Elevator *elevator);
void requestElevator(Elevator *elevator, int floor);
void displayStatus(Elevator *elevator);
void delay(int seconds);

int main() {
    Elevator elevator = {0, -1, ELEVATOR_IDLE};
    int command;

    printf("Welcome to the Elevator Simulator!\n");
    printf("Select a floor (0 - %d) to request the elevator (or -1 to exit):\n", MAX_FLOORS - 1);

    while (1) {
        scanf("%d", &command);
        
        if (command == -1) {
            printf("Exiting the elevator simulator. Goodbye!\n");
            break;
        }
        
        if (command < 0 || command >= MAX_FLOORS) {
            printf("Invalid floor! Please select a floor between 0 and %d.\n", MAX_FLOORS - 1);
            continue;
        }

        requestElevator(&elevator, command);
        displayStatus(&elevator);
        moveElevator(&elevator);
    }
    
    return 0;
}

void requestElevator(Elevator *elevator, int floor) {
    if (elevator->state == ELEVATOR_IDLE) {
        elevator->targetFloor = floor;
        elevator->state = ELEVATOR_MOVING;
        printf("Elevator requested to floor %d.\n", floor);
    } else {
        printf("Elevator is currently busy moving to floor %d.\n", elevator->targetFloor);
    }
}

void moveElevator(Elevator *elevator) {
    if (elevator->state == ELEVATOR_MOVING) {
        while (elevator->currentFloor != elevator->targetFloor) {
            if (elevator->currentFloor < elevator->targetFloor) {
                elevator->currentFloor++;
            } else {
                elevator->currentFloor--;
            }
            displayStatus(elevator);
            delay(1); // Simulate the time taken to move one floor
        }
        printf("Elevator has reached floor %d.\n", elevator->currentFloor);
        elevator->state = ELEVATOR_IDLE;
    }
}

void displayStatus(Elevator *elevator) {
    printf("Current Floor: %d | Target Floor: %d | State: %s\n", 
           elevator->currentFloor, 
           elevator->targetFloor, 
           elevator->state == ELEVATOR_IDLE ? "Idle" : "Moving");
}

void delay(int seconds) {
    int milliSeconds = 1000 * seconds;
    usleep(milliSeconds);
}