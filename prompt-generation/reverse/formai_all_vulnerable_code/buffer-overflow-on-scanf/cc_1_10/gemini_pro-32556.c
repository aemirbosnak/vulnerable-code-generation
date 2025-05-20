//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_COMMANDS 10

typedef struct {
    char *command;
    void (*function)(void);
} Command;

void take_off(void) {
    printf("Taking off...\n");
}

void land(void) {
    printf("Landing...\n");
}

void forward(void) {
    printf("Moving forward...\n");
}

void backward(void) {
    printf("Moving backward...\n");
}

void left(void) {
    printf("Turning left...\n");
}

void right(void) {
    printf("Turning right...\n");
}

void up(void) {
    printf("Moving up...\n");
}

void down(void) {
    printf("Moving down...\n");
}

void hover(void) {
    printf("Hovering...\n");
}

void exit_program(void) {
    printf("Exiting program...\n");
    exit(0);
}

Command commands[] = {
    {"takeoff", take_off},
    {"land", land},
    {"forward", forward},
    {"backward", backward},
    {"left", left},
    {"right", right},
    {"up", up},
    {"down", down},
    {"hover", hover},
    {"exit", exit_program}
};

int main(void) {
    char command[MAX_COMMAND_LENGTH];
    int i;

    while (1) {
        printf("> ");
        scanf("%s", command);

        for (i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(command, commands[i].command) == 0) {
                commands[i].function();
                break;
            }
        }

        if (i == MAX_COMMANDS) {
            printf("Invalid command.\n");
        }
    }

    return 0;
}