//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int (*function)();
} Command;

void moveForward(void) {
    printf("Vehicle moves forward.\n");
}

void turnLeft(void) {
    printf("Vehicle turns left.\n");
}

void turnRight(void) {
    printf("Vehicle turns right.\n");
}

void stop(void) {
    printf("Vehicle stops.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }

    Command commands[MAX_COMMANDS] = {
        {"moveForward", &moveForward},
        {"turnLeft", &turnLeft},
        {"turnRight", &turnRight},
        {"stop", &stop}
    };

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    int i;
    for (i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command.\n");
    return 1;
}