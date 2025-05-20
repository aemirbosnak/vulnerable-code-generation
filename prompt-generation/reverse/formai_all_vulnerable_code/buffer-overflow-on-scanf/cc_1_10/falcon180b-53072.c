//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_COMMANDS 10

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void move_forward(void) {
    printf("Vehicle moving forward...\n");
}

void move_backward(void) {
    printf("Vehicle moving backward...\n");
}

void turn_left(void) {
    printf("Vehicle turning left...\n");
}

void turn_right(void) {
    printf("Vehicle turning right...\n");
}

void stop(void) {
    printf("Vehicle stopped...\n");
}

int main(void) {
    char input[50];
    int i, choice, num_commands = 0;
    command_t commands[MAX_COMMANDS];

    commands[num_commands].command = "forward";
    commands[num_commands].function = move_forward;
    num_commands++;

    commands[num_commands].command = "backward";
    commands[num_commands].function = move_backward;
    num_commands++;

    commands[num_commands].command = "left";
    commands[num_commands].function = turn_left;
    num_commands++;

    commands[num_commands].command = "right";
    commands[num_commands].function = turn_right;
    num_commands++;

    commands[num_commands].command = "stop";
    commands[num_commands].function = stop;
    num_commands++;

    while (TRUE) {
        printf("Enter command: ");
        scanf("%s", input);

        for (i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                commands[i].function();
                break;
            }
        }

        if (i == num_commands) {
            printf("Invalid command...\n");
        }
    }

    return 0;
}