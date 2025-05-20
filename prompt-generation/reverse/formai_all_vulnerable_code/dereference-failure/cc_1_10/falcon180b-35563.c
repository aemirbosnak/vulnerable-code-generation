//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char *command;
    int (*function)(void);
} command_t;

int forward(void);
int backward(void);
int left(void);
int right(void);
int stop(void);

command_t commands[MAX_COMMANDS] = {
    {"forward", forward},
    {"backward", backward},
    {"left", left},
    {"right", right},
    {"stop", stop},
    {"invalid", NULL}
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    int i;

    for (i = 0; i < MAX_COMMANDS - 1; i++) {
        if (strcmp(commands[i].command, command) == 0) {
            commands[i].function();
            break;
        }
    }

    if (i == MAX_COMMANDS - 1) {
        printf("Invalid command '%s'\n", command);
    }

    return 0;
}

int forward(void) {
    printf("Moving forward...\n");
}

int backward(void) {
    printf("Moving backward...\n");
}

int left(void) {
    printf("Turning left...\n");
}

int right(void) {
    printf("Turning right...\n");
}

int stop(void) {
    printf("Stopping...\n");
}