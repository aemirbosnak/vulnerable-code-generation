//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define FLOOR_COUNT 10
#define ELEVATOR_SPEED 1000
#define DOORS_DELAY 2000

typedef enum {
    STOPPED,
    MOVING_UP,
    MOVING_DOWN
} ElevatorStatus;

typedef struct {
    int currentFloor;
    ElevatorStatus status;
} Elevator;

void moveElevator(Elevator* elevator, int targetFloor);
void openDoors();
void closeDoors();

int main() {
    Elevator elevator = { .currentFloor = 1, .status = STOPPED };
    int targetFloor;

    printf("Welcome to the elevator!\n");

    while (1) {
        printf("Current Floor: %d\n", elevator.currentFloor);
        printf("Elevator Status: %d\n", elevator.status);
        printf("Enter your desired floor: ");
        scanf("%d", &targetFloor);

        if (targetFloor == elevator.currentFloor) {
            printf("You are already on that floor!\n");
            continue;
        }

        if (targetFloor < 1 || targetFloor > FLOOR_COUNT) {
            printf("Invalid floor number!\n");
            continue;
        }

        moveElevator(&elevator, targetFloor);
    }

    return 0;
}

void moveElevator(Elevator* elevator, int targetFloor) {
    if (targetFloor > elevator->currentFloor) {
        printf("Moving up!\n");
        elevator->status = MOVING_UP;
        for (int i = elevator->currentFloor + 1; i <= targetFloor; i++) {
            printf("Floor: %d\n", i);
            elevator->currentFloor = i;
            usleep(ELEVATOR_SPEED);
        }
    } else if (targetFloor < elevator->currentFloor) {
        printf("Moving down!\n");
        elevator->status = MOVING_DOWN;
        for (int i = elevator->currentFloor - 1; i >= targetFloor; i--) {
            printf("Floor: %d\n", i);
            elevator->currentFloor = i;
            usleep(ELEVATOR_SPEED);
        }
    }

    openDoors();
    closeDoors();
}

void openDoors() {
    printf("Opening doors...\n");
    usleep(DOORS_DELAY);
    printf("Doors open!\n");
}

void closeDoors() {
    printf("Closing doors...\n");
    usleep(DOORS_DELAY);
    printf("Doors closed!\n");
}