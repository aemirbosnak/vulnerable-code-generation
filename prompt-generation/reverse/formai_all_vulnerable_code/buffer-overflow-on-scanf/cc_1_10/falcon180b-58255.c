//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
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

void forward(void) {
    printf("Moving the drone forward...\n");
}

void backward(void) {
    printf("Moving the drone backward...\n");
}

void left(void) {
    printf("Moving the drone left...\n");
}

void right(void) {
    printf("Moving the drone right...\n");
}

void up(void) {
    printf("Moving the drone up...\n");
}

void down(void) {
    printf("Moving the drone down...\n");
}

int main(void) {
    command_t commands[MAX_COMMANDS];
    int num_commands = 0;

    commands[num_commands++] = (command_t){.command = "fly",.function = fly};
    commands[num_commands++] = (command_t){.command = "land",.function = land};
    commands[num_commands++] = (command_t){.command = "takeoff",.function = takeoff};
    commands[num_commands++] = (command_t){.command = "forward",.function = forward};
    commands[num_commands++] = (command_t){.command = "backward",.function = backward};
    commands[num_commands++] = (command_t){.command = "left",.function = left};
    commands[num_commands++] = (command_t){.command = "right",.function = right};
    commands[num_commands++] = (command_t){.command = "up",.function = up};
    commands[num_commands++] = (command_t){.command = "down",.function = down};

    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command: ");
        scanf("%s", input);

        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                commands[i].function();
            }
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }
    }

    return 0;
}