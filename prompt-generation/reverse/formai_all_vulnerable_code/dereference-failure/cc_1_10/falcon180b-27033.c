//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void takeoff(void) {
    printf("Taking off...\n");
}

void land(void) {
    printf("Landing...\n");
}

void move_forward(void) {
    printf("Moving forward...\n");
}

void move_backward(void) {
    printf("Moving backward...\n");
}

void move_left(void) {
    printf("Moving left...\n");
}

void move_right(void) {
    printf("Moving right...\n");
}

void rotate_left(void) {
    printf("Rotating left...\n");
}

void rotate_right(void) {
    printf("Rotating right...\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s COMMAND\n", argv[0]);
        return 1;
    }

    char *command = argv[1];

    command_t commands[MAX_COMMANDS] = {
        {"takeoff", &takeoff},
        {"land", &land},
        {"forward", &move_forward},
        {"backward", &move_backward},
        {"left", &move_left},
        {"right", &move_right},
        {"rotate_left", &rotate_left},
        {"rotate_right", &rotate_right}
    };

    int num_commands = 0;

    for (int i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(commands[i].command, command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", command);
    return 1;
}