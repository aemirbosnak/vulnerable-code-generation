//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP
} Direction;

typedef struct {
    int x;
    int y;
    Direction direction;
} Vehicle;

void moveForward(Vehicle *vehicle) {
    switch (vehicle->direction) {
        case FORWARD:
            vehicle->y++;
            break;
        case BACKWARD:
            vehicle->y--;
            break;
        case LEFT:
            vehicle->x--;
            break;
        case RIGHT:
            vehicle->x++;
            break;
        default:
            break;
    }
}

void moveBackward(Vehicle *vehicle) {
    switch (vehicle->direction) {
        case FORWARD:
            vehicle->y--;
            break;
        case BACKWARD:
            vehicle->y++;
            break;
        case LEFT:
            vehicle->x++;
            break;
        case RIGHT:
            vehicle->x--;
            break;
        default:
            break;
    }
}

void turnLeft(Vehicle *vehicle) {
    switch (vehicle->direction) {
        case FORWARD:
            vehicle->direction = LEFT;
            break;
        case BACKWARD:
            vehicle->direction = RIGHT;
            break;
        case LEFT:
            vehicle->direction = BACKWARD;
            break;
        case RIGHT:
            vehicle->direction = FORWARD;
            break;
        default:
            break;
    }
}

void turnRight(Vehicle *vehicle) {
    switch (vehicle->direction) {
        case FORWARD:
            vehicle->direction = RIGHT;
            break;
        case BACKWARD:
            vehicle->direction = LEFT;
            break;
        case LEFT:
            vehicle->direction = FORWARD;
            break;
        case RIGHT:
            vehicle->direction = BACKWARD;
            break;
        default:
            break;
    }
}

void stop(Vehicle *vehicle) {
    vehicle->direction = STOP;
}

int main() {
    Vehicle vehicle = {0, 0, FORWARD};

    char input[100];
    while (1) {
        printf("Enter a command (forward, backward, left, right, stop): ");
        scanf("%s", input);

        if (strcmp(input, "forward") == 0) {
            moveForward(&vehicle);
        } else if (strcmp(input, "backward") == 0) {
            moveBackward(&vehicle);
        } else if (strcmp(input, "left") == 0) {
            turnLeft(&vehicle);
        } else if (strcmp(input, "right") == 0) {
            turnRight(&vehicle);
        } else if (strcmp(input, "stop") == 0) {
            stop(&vehicle);
        } else {
            printf("Invalid command. Please enter a valid command.\n");
        }

        printf("Vehicle position: (%d, %d)\n", vehicle.x, vehicle.y);
        printf("Vehicle direction: %s\n", vehicle.direction == FORWARD ? "FORWARD" : vehicle.direction == BACKWARD ? "BACKWARD" : vehicle.direction == LEFT ? "LEFT" : vehicle.direction == RIGHT ? "RIGHT" : "STOP");
    }

    return 0;
}