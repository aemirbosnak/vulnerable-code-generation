//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 50
#define MAX_NUM_COMMANDS 10

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    bool is_valid;
} command_t;

int num_commands = 0;
command_t commands[MAX_NUM_COMMANDS];

void add_command(char* command) {
    if (num_commands >= MAX_NUM_COMMANDS) {
        printf("Error: Too many commands\n");
        return;
    }

    strcpy(commands[num_commands].command, command);
    commands[num_commands].is_valid = true;

    num_commands++;
}

void remove_command(int index) {
    if (index >= num_commands || index < 0) {
        printf("Error: Invalid command index\n");
        return;
    }

    commands[index].is_valid = false;
}

void print_commands() {
    printf("Commands:\n");
    for (int i = 0; i < num_commands; i++) {
        if (commands[i].is_valid) {
            printf("%d. %s\n", i + 1, commands[i].command);
        }
    }
}

int main() {
    printf("Drone Remote Control\n");

    while (true) {
        printf("Enter command (max %d characters): ", MAX_COMMAND_LENGTH - 1);
        scanf("%s", commands[num_commands - 1].command);

        if (strcmp(commands[num_commands - 1].command, "takeoff") == 0) {
            printf("Taking off...\n");
        } else if (strcmp(commands[num_commands - 1].command, "land") == 0) {
            printf("Landing...\n");
        } else if (strcmp(commands[num_commands - 1].command, "forward") == 0) {
            printf("Moving forward...\n");
        } else if (strcmp(commands[num_commands - 1].command, "backward") == 0) {
            printf("Moving backward...\n");
        } else if (strcmp(commands[num_commands - 1].command, "left") == 0) {
            printf("Turning left...\n");
        } else if (strcmp(commands[num_commands - 1].command, "right") == 0) {
            printf("Turning right...\n");
        } else {
            printf("Invalid command\n");
        }

        print_commands();
    }

    return 0;
}