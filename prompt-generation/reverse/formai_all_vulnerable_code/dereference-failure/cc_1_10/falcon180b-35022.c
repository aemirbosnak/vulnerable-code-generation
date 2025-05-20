//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void move_forward(void);
void move_backward(void);
void turn_left(void);
void turn_right(void);
void stop(void);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [command]\n", argv[0]);
        return 1;
    }

    command_t commands[MAX_COMMANDS] = {
        {"move_forward", move_forward},
        {"move_backward", move_backward},
        {"turn_left", turn_left},
        {"turn_right", turn_right},
        {"stop", stop}
    };

    char *command = argv[1];
    int i;

    for (i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", command);
    return 1;
}

void move_forward(void) {
    printf("Moving forward...\n");
}

void move_backward(void) {
    printf("Moving backward...\n");
}

void turn_left(void) {
    printf("Turning left...\n");
}

void turn_right(void) {
    printf("Turning right...\n");
}

void stop(void) {
    printf("Stopping...\n");
}