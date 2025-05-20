//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 20
#define NUM_COMMANDS 6

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void fly(void) {
    printf("The drone takes flight, soaring gracefully through the air.\n");
}

void land(void) {
    printf("The drone descends smoothly, landing gently on the ground.\n");
}

void forward(int distance) {
    printf("The drone moves forward %d meters.\n", distance);
}

void backward(int distance) {
    printf("The drone moves backward %d meters.\n", distance);
}

void left(int angle) {
    printf("The drone turns left by %d degrees.\n", angle);
}

void right(int angle) {
    printf("The drone turns right by %d degrees.\n", angle);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    command_t commands[NUM_COMMANDS] = {
        {"fly", fly},
        {"land", land},
        {"forward", forward},
        {"backward", backward},
        {"left", left},
        {"right", right}
    };

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    for (int i = 0; i < NUM_COMMANDS; i++) {
        if (strcmp(command, commands[i].name) == 0) {
            (*commands[i].function)();
            return 0;
        }
    }

    printf("Invalid command.\n");
    return 1;
}