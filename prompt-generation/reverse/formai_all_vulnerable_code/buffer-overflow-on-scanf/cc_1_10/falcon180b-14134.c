//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

typedef struct command {
    char *name;
    void (*function)();
} Command;

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

int main() {
    Command commands[MAX_COMMANDS] = {
        {"fly", fly},
        {"land", land},
        {"takeoff", takeoff},
        {"forward", forward},
        {"backward", backward},
        {"left", left},
        {"right", right},
        {"up", up},
        {"down", down}
    };

    int num_commands = sizeof(commands) / sizeof(Command);

    char input[50];
    while (1) {
        printf("Enter command: ");
        scanf("%s", input);

        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].name) == 0) {
                commands[i].function();
            }
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }
    }

    return 0;
}