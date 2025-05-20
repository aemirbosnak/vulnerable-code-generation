//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct elevator {
    int floors[10];
    int top;
    int bottom;
};

struct floor {
    int numPassengers;
};

void initializeElevator(struct elevator *elevator) {
    elevator->top = -1;
    elevator->bottom = -1;
    for (int i = 0; i < 10; i++) {
        elevator->floors[i] = 0;
    }
}

void addPassenger(struct elevator *elevator, int floor) {
    if (elevator->top == floor || elevator->bottom == floor) {
        printf("Elevator is already on floor %d.\n", floor);
        return;
    }
    if (elevator->floors[floor] >= 2) {
        printf("Elevator cannot carry more than 2 passengers on floor %d.\n", floor);
        return;
    }
    elevator->floors[floor]++;
}

void removePassenger(struct elevator *elevator, int floor) {
    if (elevator->top == floor || elevator->bottom == floor) {
        printf("Elevator is not currently on floor %d.\n", floor);
        return;
    }
    if (elevator->floors[floor] <= 1) {
        printf("No passengers on floor %d.\n", floor);
        return;
    }
    elevator->floors[floor]--;
}

void moveElevator(struct elevator *elevator, int startFloor, int endFloor) {
    if (startFloor > endFloor) {
        printf("Error: cannot move elevator from floor %d to floor %d.\n", startFloor, endFloor);
        return;
    }
    if (startFloor == endFloor) {
        printf("Elevator is already on floor %d.\n", startFloor);
        return;
    }
    if (startFloor == elevator->bottom) {
        elevator->bottom = endFloor;
        printf("Elevator moved from floor %d to floor %d.\n", startFloor, endFloor);
        return;
    }
    if (startFloor == elevator->top) {
        elevator->top = endFloor;
        printf("Elevator moved from floor %d to floor %d.\n", startFloor, endFloor);
        return;
    }
    printf("Elevator cannot move between floors %d and %d.\n", startFloor, endFloor);
}

bool isFull(struct elevator *elevator) {
    for (int i = 0; i <= elevator->bottom; i++) {
        if (elevator->floors[i] < 2) {
            return false;
        }
    }
    return true;
}

int main() {
    struct elevator elevator;
    initializeElevator(&elevator);

    while (true) {
        printf("Enter command (add | remove | move | isFull): ");
        char command[100];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            int floor;
            printf("Enter floor: ");
            scanf("%d", &floor);
            addPassenger(&elevator, floor);
        } else if (strcmp(command, "remove") == 0) {
            int floor;
            printf("Enter floor: ");
            scanf("%d", &floor);
            removePassenger(&elevator, floor);
        } else if (strcmp(command, "move") == 0) {
            int startFloor, endFloor;
            printf("Enter start floor: ");
            scanf("%d", &startFloor);
            printf("Enter end floor: ");
            scanf("%d", &endFloor);
            moveElevator(&elevator, startFloor, endFloor);
        } else if (strcmp(command, "isFull") == 0) {
            printf("Is the elevator full? %s\n", isFull(&elevator)? "Yes" : "No");
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}