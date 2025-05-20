//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 100
#define MAX_ARGUMENTS 10
#define MAX_ARGUMENT_LENGTH 50

// Structure to hold command and its arguments
typedef struct {
    char command[MAX_ARGUMENT_LENGTH];
    char arguments[MAX_ARGUMENTS][MAX_ARGUMENT_LENGTH];
    int num_arguments;
} command_t;

// Function to execute commands
void execute_command(command_t* cmd) {
    if (strcmp(cmd->command, "takeoff") == 0) {
        printf("Drone taking off...\n");
    } else if (strcmp(cmd->command, "land") == 0) {
        printf("Drone landing...\n");
    } else if (strcmp(cmd->command, "move") == 0) {
        printf("Drone moving...\n");
    } else if (strcmp(cmd->command, "rotate") == 0) {
        printf("Drone rotating...\n");
    } else {
        printf("Invalid command: %s\n", cmd->command);
    }
}

// Function to parse input and store in command structure
void parse_input(char* input, command_t* cmd) {
    char* token = strtok(input, " ");
    strcpy(cmd->command, token);

    int i = 0;
    while ((token = strtok(NULL, " "))!= NULL && i < MAX_ARGUMENTS) {
        strcpy(cmd->arguments[i], token);
        i++;
    }
    cmd->num_arguments = i;
}

// Main function to read commands from user and execute them
int main() {
    command_t cmd;
    char input[MAX_ARGUMENT_LENGTH];

    printf("Enter commands for the drone:\n");

    while (fgets(input, MAX_ARGUMENT_LENGTH, stdin)!= NULL) {
        parse_input(input, &cmd);
        execute_command(&cmd);
    }

    return 0;
}