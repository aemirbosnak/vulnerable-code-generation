//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)();
} command_t;

void fly_forward(void) {
    printf("Flying forward\n");
}

void fly_backward(void) {
    printf("Flying backward\n");
}

void fly_left(void) {
    printf("Flying left\n");
}

void fly_right(void) {
    printf("Flying right\n");
}

void take_off(void) {
    printf("Taking off\n");
}

void land(void) {
    printf("Landing\n");
}

int main() {
    command_t commands[MAX_COMMANDS] = {{"takeoff", take_off}, {"land", land}, {"forward", fly_forward}, {"backward", fly_backward}, {"left", fly_left}, {"right", fly_right}};
    int num_commands = sizeof(commands) / sizeof(command_t);
    char input[MAX_COMMAND_LENGTH];

    printf("Welcome to the drone remote control!\n");
    printf("Enter commands to control the drone:\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        int i;
        for (i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                (*commands[i].function)();
            }
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }
    }

    return 0;
}