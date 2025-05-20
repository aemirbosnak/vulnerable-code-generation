//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)();
} command_t;

void move_forward(void) {
    printf("Moving forward...\n");
}

void move_backward(void) {
    printf("Moving backward...\n");
}

void turn_left(void) {
    printf("Turning left...\n");
}

void turn_right(void) {
    printf("Turning right...\n");
}

int main(int argc, char *argv[]) {
    command_t commands[MAX_COMMANDS] = {
        {"move_forward", move_forward},
        {"move_backward", move_backward},
        {"turn_left", turn_left},
        {"turn_right", turn_right}
    };

    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter command: ");
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