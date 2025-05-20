//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

typedef struct {
    float x;
    float y;
    float direction; // Angle in degrees
} Vehicle;

void initializeVehicle(Vehicle *v) {
    v->x = 0.0;
    v->y = 0.0;
    v->direction = 0.0; // Facing "north"
}

void displayPosition(Vehicle *v) {
    printf("Vehicle Position: (%.2f, %.2f), Direction: %.2f degrees\n", v->x, v->y, v->direction);
}

void moveForward(Vehicle *v, float distance) {
    v->x += distance * cos(v->direction * M_PI / 180.0);
    v->y += distance * sin(v->direction * M_PI / 180.0);
    printf("Moved forward %.2f units.\n", distance);
}

void moveBackward(Vehicle *v, float distance) {
    v->x -= distance * cos(v->direction * M_PI / 180.0);
    v->y -= distance * sin(v->direction * M_PI / 180.0);
    printf("Moved backward %.2f units.\n", distance);
}

void turnLeft(Vehicle *v, float angle) {
    v->direction += angle;
    v->direction = fmod(v->direction, 360.0);
    if (v->direction < 0) v->direction += 360.0;
    printf("Turned left %.2f degrees.\n", angle);
}

void turnRight(Vehicle *v, float angle) {
    v->direction -= angle;
    v->direction = fmod(v->direction, 360.0);
    if (v->direction < 0) v->direction += 360.0;
    printf("Turned right %.2f degrees.\n", angle);
}

void processCommand(Vehicle *v, char *command) {
    char cmd[MAX_COMMAND_LENGTH];
    float value;

    if (sscanf(command, "%s %f", cmd, &value) < 1) {
        printf("Invalid command: %s\n", command);
        return;
    }

    if (strcmp(cmd, "forward") == 0) {
        moveForward(v, value);
    } else if (strcmp(cmd, "backward") == 0) {
        moveBackward(v, value);
    } else if (strcmp(cmd, "left") == 0) {
        turnLeft(v, value);
    } else if (strcmp(cmd, "right") == 0) {
        turnRight(v, value);
    } else {
        printf("Unknown command: %s\n", cmd);
    }

    displayPosition(v);
}

int main() {
    Vehicle rcVehicle;
    initializeVehicle(&rcVehicle);

    char command[MAX_COMMAND_LENGTH];

    printf("Remote Control Vehicle Simulation\n");
    printf("Commands: forward <distance>, backward <distance>, left <angle>, right <angle>, exit\n");
    
    while (1) {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline

        if (strcmp(command, "exit") == 0) {
            printf("Exiting simulation...\n");
            break;
        }

        processCommand(&rcVehicle, command);
    }

    return 0;
}