//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 100
#define MAX_COMMAND_LENGTH 50

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void takeoff(void) {
    printf("Taking off!\n");
}

void land(void) {
    printf("Landing!\n");
}

void forward(int speed) {
    printf("Moving forward at %d%% speed.\n", speed);
}

void backward(int speed) {
    printf("Moving backward at %d%% speed.\n", speed);
}

void left(int speed) {
    printf("Turning left at %d%% speed.\n", speed);
}

void right(int speed) {
    printf("Turning right at %d%% speed.\n", speed);
}

void emergency_stop(void) {
    printf("Emergency stop!\n");
}

int main(int argc, char *argv[]) {
    int i, j, n_commands;
    char input[MAX_COMMAND_LENGTH];
    command_t commands[MAX_COMMANDS];

    n_commands = 0;

    // Add commands
    strcpy(commands[n_commands].command, "takeoff");
    commands[n_commands].function = takeoff;
    n_commands++;

    strcpy(commands[n_commands].command, "land");
    commands[n_commands].function = land;
    n_commands++;

    strcpy(commands[n_commands].command, "forward");
    commands[n_commands].function = forward;
    n_commands++;

    strcpy(commands[n_commands].command, "backward");
    commands[n_commands].function = backward;
    n_commands++;

    strcpy(commands[n_commands].command, "left");
    commands[n_commands].function = left;
    n_commands++;

    strcpy(commands[n_commands].command, "right");
    commands[n_commands].function = right;
    n_commands++;

    strcpy(commands[n_commands].command, "emergency_stop");
    commands[n_commands].function = emergency_stop;
    n_commands++;

    printf("Enter commands separated by spaces:\n");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char *token = strtok(input, " ");
    while (token!= NULL) {
        for (i = 0; i < n_commands; i++) {
            if (strcmp(token, commands[i].command) == 0) {
                commands[i].function();
            }
        }
        token = strtok(NULL, " ");
    }

    return 0;
}