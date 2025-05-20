//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void fly(void) {
    printf("The drone is flying.\n");
}

void land(void) {
    printf("The drone is landing.\n");
}

void takeoff(void) {
    printf("The drone is taking off.\n");
}

void move_left(void) {
    printf("The drone is moving left.\n");
}

void move_right(void) {
    printf("The drone is moving right.\n");
}

void move_forward(void) {
    printf("The drone is moving forward.\n");
}

void move_backward(void) {
    printf("The drone is moving backward.\n");
}

void rotate_left(void) {
    printf("The drone is rotating left.\n");
}

void rotate_right(void) {
    printf("The drone is rotating right.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command [parameters]\n", argv[0]);
        return 1;
    }

    command_t commands[MAX_COMMANDS] = {
        {"fly", fly},
        {"land", land},
        {"takeoff", takeoff},
        {"move_left", move_left},
        {"move_right", move_right},
        {"move_forward", move_forward},
        {"move_backward", move_backward},
        {"rotate_left", rotate_left},
        {"rotate_right", rotate_right}
    };

    char *command = argv[1];
    int i;

    for (i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", command);
    return 1;
}