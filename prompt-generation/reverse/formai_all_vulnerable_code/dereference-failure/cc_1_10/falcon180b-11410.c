//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void fly(void) {
    printf("Flying the drone...\n");
}

void land(void) {
    printf("Landing the drone...\n");
}

void takeoff(void) {
    printf("Taking off the drone...\n");
}

void left(void) {
    printf("Moving the drone to the left...\n");
}

void right(void) {
    printf("Moving the drone to the right...\n");
}

void forward(void) {
    printf("Moving the drone forward...\n");
}

void backward(void) {
    printf("Moving the drone backward...\n");
}

int main(int argc, char **argv) {
    command_t commands[MAX_COMMANDS] = {
        {"fly", fly},
        {"land", land},
        {"takeoff", takeoff},
        {"left", left},
        {"right", right},
        {"forward", forward},
        {"backward", backward}
    };

    int num_commands = sizeof(commands) / sizeof(commands[0]);

    printf("Drone Remote Control\n");
    printf("Enter 'help' for a list of commands\n");

    char input[100];
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        char *token = strtok(input, " ");
        if (strcmp(token, "help") == 0) {
            for (int i = 0; i < num_commands; i++) {
                printf("%s\n", commands[i].command);
            }
        } else {
            for (int i = 0; i < num_commands; i++) {
                if (strcmp(token, commands[i].command) == 0) {
                    commands[i].function();
                    break;
                }
            }
        }
    }

    return 0;
}