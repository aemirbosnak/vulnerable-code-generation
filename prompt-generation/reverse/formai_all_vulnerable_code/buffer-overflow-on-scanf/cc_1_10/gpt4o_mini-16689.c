//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x; // Vehicle's x-position
    int y; // Vehicle's y-position
    int direction; // Direction (0: North, 1: East, 2: South, 3: West)
} Vehicle;

void initializeVehicle(Vehicle *v) {
    v->x = 0;
    v->y = 0;
    v->direction = 0; // Facing North
}

void moveForward(Vehicle *v) {
    switch(v->direction) {
        case 0: v->y += 1; break; // North
        case 1: v->x += 1; break; // East
        case 2: v->y -= 1; break; // South
        case 3: v->x -= 1; break; // West
    }
}

void moveBackward(Vehicle *v) {
    switch(v->direction) {
        case 0: v->y -= 1; break; // North
        case 1: v->x -= 1; break; // East
        case 2: v->y += 1; break; // South
        case 3: v->x += 1; break; // West
    }
}

void turnLeft(Vehicle *v) {
    v->direction = (v->direction + 3) % 4; // Turn left
}

void turnRight(Vehicle *v) {
    v->direction = (v->direction + 1) % 4; // Turn right
}

void displayStatus(const Vehicle *v) {
    const char *directions[] = {"North", "East", "South", "West"};
    printf("Vehicle Position: (%d, %d)\n", v->x, v->y);
    printf("Current Direction: %s\n", directions[v->direction]);
}

void userControl(Vehicle *v) {
    char command[20];

    printf("Enter commands to control the vehicle:\n");
    printf("'f' for forward, 'b' for backward, 'l' for left, 'r' for right, 's' for status, 'q' to quit.\n");

    while (1) {
        printf("Command: ");
        scanf("%s", command);

        if (strcmp(command, "f") == 0) {
            moveForward(v);
        } else if (strcmp(command, "b") == 0) {
            moveBackward(v);
        } else if (strcmp(command, "l") == 0) {
            turnLeft(v);
        } else if (strcmp(command, "r") == 0) {
            turnRight(v);
        } else if (strcmp(command, "s") == 0) {
            displayStatus(v);
        } else if (strcmp(command, "q") == 0) {
            printf("Exiting simulation...\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

int main() {
    Vehicle rcVehicle;
    initializeVehicle(&rcVehicle);
    userControl(&rcVehicle);
    return 0;
}