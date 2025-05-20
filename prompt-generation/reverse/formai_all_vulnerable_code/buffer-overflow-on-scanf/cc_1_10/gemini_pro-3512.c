//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

typedef struct {
    char *command;
    void (*function)();
} Command;

void take_off() {
    printf("Drone is taking off!\n");
}

void land() {
    printf("Drone is landing!\n");
}

void forward(int distance) {
    printf("Drone is flying forward %d meters.\n", distance);
}

void backward(int distance) {
    printf("Drone is flying backward %d meters.\n", distance);
}

void left(int angle) {
    printf("Drone is turning left %d degrees.\n", angle);
}

void right(int angle) {
    printf("Drone is turning right %d degrees.\n", angle);
}

void up(int height) {
    printf("Drone is ascending %d meters.\n", height);
}

void down(int height) {
    printf("Drone is descending %d meters.\n", height);
}

void quit() {
    printf("Quitting drone remote control.\n");
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
    {"quit", quit},
};

int main() {
    char input[100];

    while (1) {
        printf("Enter a command: ");
        scanf("%s", input);

        for (int i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                commands[i].function();
                break;
            }
        }
    }

    return 0;
}