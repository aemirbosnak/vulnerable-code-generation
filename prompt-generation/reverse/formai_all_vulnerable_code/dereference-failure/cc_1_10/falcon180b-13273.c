//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 50

typedef struct {
    char *command;
    void (*function)(void);
} Command;

void moveForward(void) {
    printf("Moving forward...\n");
}

void moveBackward(void) {
    printf("Moving backward...\n");
}

void turnLeft(void) {
    printf("Turning left...\n");
}

void turnRight(void) {
    printf("Turning right...\n");
}

void stop(void) {
    printf("Stopping...\n");
}

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    Command commands[MAX_COMMANDS] = {{"forward", moveForward},
                                     {"backward", moveBackward},
                                     {"left", turnLeft},
                                     {"right", turnRight},
                                     {"stop", stop}};
    int numCommands = sizeof(commands) / sizeof(Command);
    bool quit = false;

    printf("Remote control vehicle simulation\n");
    printf("Enter commands: forward, backward, left, right, stop\n");

    while (!quit) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        for (int i = 0; i < numCommands; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                commands[i].function();
            }
        }

        if (strcmp(input, "quit") == 0) {
            quit = true;
        }
    }

    return 0;
}