//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void fly_forward(void) {
    printf("Drone flying forward\n");
}

void fly_backward(void) {
    printf("Drone flying backward\n");
}

void fly_left(void) {
    printf("Drone flying left\n");
}

void fly_right(void) {
    printf("Drone flying right\n");
}

void take_off(void) {
    printf("Drone taking off\n");
}

void land(void) {
    printf("Drone landing\n");
}

int main(int argc, char *argv[]) {
    command_t commands[MAX_COMMANDS] = {
        {"forward", fly_forward},
        {"backward", fly_backward},
        {"left", fly_left},
        {"right", fly_right},
        {"takeoff", take_off},
        {"land", land},
        {NULL, NULL}
    };

    if (argc < 2) {
        printf("Usage: %s [command]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    int i = 0;

    while (commands[i].command!= NULL) {
        if (strcmp(command, commands[i].command) == 0) {
            (*commands[i].function)();
            return 0;
        }
        i++;
    }

    printf("Invalid command: %s\n", command);
    return 1;
}