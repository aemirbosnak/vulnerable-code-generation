//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complex
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

void turn_left(void) {
    printf("Turning left...\n");
}

void turn_right(void) {
    printf("Turning right...\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }

    command_t commands[MAX_COMMANDS] = {{"move_forward", move_forward},
                                        {"turn_left", turn_left},
                                        {"turn_right", turn_right}};

    char *command = argv[1];
    int index = 0;

    for (index = 0; index < MAX_COMMANDS; index++) {
        if (strcmp(commands[index].command, command) == 0) {
            commands[index].function();
            break;
        }
    }

    if (index == MAX_COMMANDS) {
        printf("Invalid command.\n");
    }

    return 0;
}