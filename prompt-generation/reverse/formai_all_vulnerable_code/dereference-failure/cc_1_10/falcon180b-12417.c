//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

// Struct to hold command and its parameters
typedef struct {
    char command[MAX_COMMAND_LENGTH];
    char params[MAX_COMMAND_LENGTH];
} command_t;

// Array to hold all the commands
command_t commands[MAX_COMMANDS];

// Function to parse input and store in command struct
void parse_input(char* input) {
    int i = 0;
    char* command = strtok(input, " ");
    strcpy(commands[i].command, command);

    char* params = strtok(NULL, " ");
    strcpy(commands[i].params, params);

    i++;
}

// Function to execute commands
void execute_commands() {
    for (int i = 0; i < MAX_COMMANDS; i++) {
        if (commands[i].command[0]!= '\0') {
            if (strcmp(commands[i].command, "turn_on") == 0) {
                system("echo Turning on the lights...");
            } else if (strcmp(commands[i].command, "turn_off") == 0) {
                system("echo Turning off the lights...");
            } else if (strcmp(commands[i].command, "dim") == 0) {
                system("echo Dimming the lights...");
            } else if (strcmp(commands[i].command, "brighten") == 0) {
                system("echo Brightening the lights...");
            }
        }
    }
}

// Main function
int main() {
    char input[MAX_COMMAND_LENGTH];

    while (true) {
        printf("Enter a command (e.g. turn_on living_room): ");
        scanf("%s", input);

        parse_input(input);

        execute_commands();
    }

    return 0;
}