//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 0
#define SUCCESS 1

#define COMMANDS_COUNT 5

typedef struct command {
    char label[255];
    int value;
} Command;

Command commands[COMMANDS_COUNT] = {
    {"Forward", 1},
    {"Right", 2},
    {"Backward", 3},
    {"Left", 4},
    {"Stop", 5},
};

int validate_input(char input[255]) {
    for (int i = 0; i < COMMANDS_COUNT; i++) {
        if (strcmp(input, commands[i].label) == 0) {
            return commands[i].value;
        }
    }
    return ERROR;
}

void send_command(int command) {
    printf("Sending command %d...\n", command);
    // This is where you would interface with the drone remote control hardware to send the command.
}

int main() {
    char input[255];
    int command;
    printf("Welcome to the drone remote control system!\n");

    while (1) {
        printf("Enter a command ('Forward', 'Right', 'Backward', 'Left', 'Stop'): ");
        scanf("%s", input);
        command = validate_input(input);

        if (command == ERROR) {
            printf("Invalid command! Please try again.\n");
            continue;
        }

        send_command(command);
    }

    return 0;
}