//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 20
#define NUM_COMMANDS 4

typedef struct {
    char *command;
    void (*func)(void);
} command_t;

void takeoff(void) {
    printf("Taking off...\n");
}

void land(void) {
    printf("Landing...\n");
}

void move_left(void) {
    printf("Moving left...\n");
}

void move_right(void) {
    printf("Moving right...\n");
}

command_t commands[NUM_COMMANDS] = {
    {"takeoff", takeoff},
    {"land", land},
    {"move_left", move_left},
    {"move_right", move_right}
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [command]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    int i;

    for (i = 0; i < NUM_COMMANDS; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].func();
            return 0;
        }
    }

    printf("Invalid command: %s\n", command);
    return 1;
}