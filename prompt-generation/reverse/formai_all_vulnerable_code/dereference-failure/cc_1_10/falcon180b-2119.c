//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void fly(void) {
    printf("The drone takes off and hovers in the air.\n");
}

void land(void) {
    printf("The drone gracefully lands on the ground.\n");
}

void forward(int distance) {
    printf("The drone moves forward by %d meters.\n", distance);
}

void backward(int distance) {
    printf("The drone moves backward by %d meters.\n", distance);
}

void left(int angle) {
    printf("The drone turns left by %d degrees.\n", angle);
}

void right(int angle) {
    printf("The drone turns right by %d degrees.\n", angle);
}

void up(int height) {
    printf("The drone ascends by %d meters.\n", height);
}

void down(int height) {
    printf("The drone descends by %d meters.\n", height);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s COMMAND [ARGUMENTS]\n", argv[0]);
        return 1;
    }

    command_t commands[] = {
        {"fly", fly},
        {"land", land},
        {"forward", forward},
        {"backward", backward},
        {"left", left},
        {"right", right},
        {"up", up},
        {"down", down}
    };

    char *command = argv[1];
    int i;

    for (i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", command);
    return 1;
}