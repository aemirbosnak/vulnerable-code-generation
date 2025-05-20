//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_COMMANDS 10

typedef struct {
    char *command;
    void (*function)();
} command_t;

int num_commands = 0;
command_t commands[MAX_COMMANDS];

void register_command(char *command, void (*function)()) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Too many commands registered.\n");
        return;
    }

    commands[num_commands].command = strdup(command);
    commands[num_commands].function = function;
    num_commands++;
}

void execute_command(char *input) {
    char command[MAX_COMMAND_LENGTH];
    strcpy(command, input);

    for (int i = 0; i < num_commands; i++) {
        if (strcmp(commands[i].command, command) == 0) {
            (*commands[i].function)();
            return;
        }
    }

    printf("Error: Unknown command '%s'.\n", command);
}

void move_forward() {
    printf("Drone moving forward...\n");
}

void move_backward() {
    printf("Drone moving backward...\n");
}

void move_left() {
    printf("Drone moving left...\n");
}

void move_right() {
    printf("Drone moving right...\n");
}

void main() {
    register_command("forward", move_forward);
    register_command("backward", move_backward);
    register_command("left", move_left);
    register_command("right", move_right);

    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        execute_command(input);
    }
}