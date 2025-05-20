//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 20
#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
    char direction[10];
    int isMoving;
} Vehicle;

void initializeVehicle(Vehicle *v) {
    v->x = GRID_SIZE / 2;
    v->y = GRID_SIZE / 2;
    strcpy(v->direction, "NORTH");
    v->isMoving = 0;
}

void displayPosition(Vehicle *v) {
    printf("Vehicle is at (%d, %d) facing %s. %s\n", v->x, v->y,
           v->direction, v->isMoving ? "Moving" : "Stationary");
}

void moveForward(Vehicle *v) {
    if (v->isMoving) {
        switch (v->direction[0]) {
            case 'N':
                if (v->y < GRID_SIZE - 1) v->y++;
                break;
            case 'E':
                if (v->x < GRID_SIZE - 1) v->x++;
                break;
            case 'S':
                if (v->y > 0) v->y--;
                break;
            case 'W':
                if (v->x > 0) v->x--;
                break;
        }
    }
}

void moveBackward(Vehicle *v) {
    if (v->isMoving) {
        switch (v->direction[0]) {
            case 'N':
                if (v->y > 0) v->y--;
                break;
            case 'E':
                if (v->x > 0) v->x--;
                break;
            case 'S':
                if (v->y < GRID_SIZE - 1) v->y++;
                break;
            case 'W':
                if (v->x < GRID_SIZE - 1) v->x++;
                break;
        }
    }
}

void turnLeft(Vehicle *v) {
    if (strcmp(v->direction, "NORTH") == 0) strcpy(v->direction, "WEST");
    else if (strcmp(v->direction, "WEST") == 0) strcpy(v->direction, "SOUTH");
    else if (strcmp(v->direction, "SOUTH") == 0) strcpy(v->direction, "EAST");
    else if (strcmp(v->direction, "EAST") == 0) strcpy(v->direction, "NORTH");
}

void turnRight(Vehicle *v) {
    if (strcmp(v->direction, "NORTH") == 0) strcpy(v->direction, "EAST");
    else if (strcmp(v->direction, "EAST") == 0) strcpy(v->direction, "SOUTH");
    else if (strcmp(v->direction, "SOUTH") == 0) strcpy(v->direction, "WEST");
    else if (strcmp(v->direction, "WEST") == 0) strcpy(v->direction, "NORTH");
}

void toggleMovement(Vehicle *v) {
    v->isMoving = !v->isMoving;
}

int main() {
    Vehicle myVehicle;
    char command[MAX_COMMAND_LENGTH];

    initializeVehicle(&myVehicle);

    printf("Remote Control Vehicle Simulation\n");
    printf("Commands: FORWARD, BACKWARD, LEFT, RIGHT, STOP, STATUS, QUIT\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "FORWARD") == 0) {
            toggleMovement(&myVehicle);
            if (myVehicle.isMoving) {
                printf("Vehicle started moving forward.\n");
            } else {
                printf("Vehicle stopped.\n");
            }
        } else if (strcmp(command, "BACKWARD") == 0) {
            toggleMovement(&myVehicle);
            if (myVehicle.isMoving) {
                printf("Vehicle started moving backward.\n");
            } else {
                printf("Vehicle stopped.\n");
            }
        } else if (strcmp(command, "LEFT") == 0) {
            turnLeft(&myVehicle);
            printf("Vehicle turned left.\n");
        } else if (strcmp(command, "RIGHT") == 0) {
            turnRight(&myVehicle);
            printf("Vehicle turned right.\n");
        } else if (strcmp(command, "STATUS") == 0) {
            displayPosition(&myVehicle);
        } else if (strcmp(command, "QUIT") == 0) {
            printf("Exiting the simulation.\n");
            break;
        } else {
            printf("Invalid command, please try again.\n");
        }

        moveForward(&myVehicle);
        moveBackward(&myVehicle);
    }

    return 0;
}