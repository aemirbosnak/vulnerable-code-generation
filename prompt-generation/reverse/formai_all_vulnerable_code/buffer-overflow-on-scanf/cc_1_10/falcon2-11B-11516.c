//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int floor;
} Elevator;

void initializeElevator(Elevator *elevator, int floor) {
    elevator->floor = floor;
}

void moveElevatorUp(Elevator *elevator) {
    elevator->floor++;
}

void moveElevatorDown(Elevator *elevator) {
    elevator->floor--;
}

void printElevatorPosition(Elevator elevator) {
    printf("Elevator is currently at floor %d.\n", elevator.floor);
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator, 0);

    while (1) {
        char command[10];

        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "up") == 0) {
            moveElevatorUp(&elevator);
            printElevatorPosition(elevator);
        } else if (strcmp(command, "down") == 0) {
            moveElevatorDown(&elevator);
            printElevatorPosition(elevator);
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}