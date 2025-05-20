//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP
} Command;

typedef struct {
    float x;
    float y;
    float angle;
} Position;

typedef struct {
    Command command;
    int duration;
} RemoteControlSignal;

void execute_command(Position *position, RemoteControlSignal signal) {
    switch (signal.command) {
        case FORWARD:
            position->y += signal.duration * 0.1;
            break;
        case BACKWARD:
            position->y -= signal.duration * 0.1;
            break;
        case LEFT:
            position->angle -= signal.duration * 0.1;
            break;
        case RIGHT:
            position->angle += signal.duration * 0.1;
            break;
        case STOP:
            break;
    }
}

void print_position(Position position) {
    printf("Position: (%.2f, %.2f, %.2f degrees)\n", position.x, position.y, position.angle);
}

int main() {
    Position position = {0.0, 0.0, 0.0};
    RemoteControlSignal signal;

    while (1) {
        printf("Enter command (f/b/l/r/s): ");
        char command[10];
        scanf("%s", command);

        printf("Enter duration: ");
        int duration;
        scanf("%d", &duration);

        if (strcmp(command, "f") == 0) {
            signal.command = FORWARD;
        } else if (strcmp(command, "b") == 0) {
            signal.command = BACKWARD;
        } else if (strcmp(command, "l") == 0) {
            signal.command = LEFT;
        } else if (strcmp(command, "r") == 0) {
            signal.command = RIGHT;
        } else if (strcmp(command, "s") == 0) {
            signal.command = STOP;
        } else {
            printf("Invalid command\n");
            continue;
        }

        signal.duration = duration;

        execute_command(&position, signal);

        print_position(position);
    }

    return 0;
}