//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)(void);
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

void stop(void) {
    printf("Stopping...\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    command_t commands[MAX_COMMANDS] = {
        {"move_forward", move_forward},
        {"turn_left", turn_left},
        {"turn_right", turn_right},
        {"stop", stop}
    };

    int num_commands = sizeof(commands) / sizeof(command_t);

    for (int i = 0; i < num_commands; i++) {
        if (strcmp(commands[i].command, command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command.\n");
    return 1;
}