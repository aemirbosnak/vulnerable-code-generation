//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)();
} command_t;

void takeoff() {
    printf("Taking off!\n");
}

void land() {
    printf("Landing!\n");
}

void move_forward() {
    printf("Moving forward!\n");
}

void move_backward() {
    printf("Moving backward!\n");
}

void move_left() {
    printf("Moving left!\n");
}

void move_right() {
    printf("Moving right!\n");
}

void rotate_left() {
    printf("Rotating left!\n");
}

void rotate_right() {
    printf("Rotating right!\n");
}

int main() {
    command_t commands[MAX_COMMANDS] = {{"takeoff", &takeoff},
                                         {"land", &land},
                                         {"forward", &move_forward},
                                         {"backward", &move_backward},
                                         {"left", &move_left},
                                         {"right", &move_right},
                                         {"rotate_left", &rotate_left},
                                         {"rotate_right", &rotate_right}};

    int num_commands = sizeof(commands) / sizeof(commands[0]);

    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command: ");
        scanf("%s", input);

        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                commands[i].function();
            }
        }
    }

    return 0;
}