//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 100

// Struct to hold command and its parameters
typedef struct {
    char *command;
    char *params[3];
} Command;

// Function to parse command and its parameters
Command parse_command(char *input) {
    Command cmd;
    char *token;
    int i = 0;

    // Copy command to cmd.command
    strcpy(cmd.command, input);

    // Tokenize input by space
    token = strtok(input, " ");

    // Parse parameters
    while (token!= NULL && i < 3) {
        strcpy(cmd.params[i], token);
        token = strtok(NULL, " ");
        i++;
    }

    // Terminate params array
    cmd.params[i] = NULL;

    return cmd;
}

// Function to execute command
void execute_command(Command cmd) {
    if (strcmp(cmd.command, "turn_on") == 0) {
        printf("Turning on the light...\n");
    } else if (strcmp(cmd.command, "turn_off") == 0) {
        printf("Turning off the light...\n");
    } else if (strcmp(cmd.command, "set_brightness") == 0) {
        printf("Setting brightness to %s...\n", cmd.params[0]);
    } else {
        printf("Invalid command.\n");
    }
}

// Main function
int main() {
    char input[MAX_COMMAND_LENGTH];

    printf("Welcome to the Smart Home Light Control!\n");
    printf("Enter commands to control the light.\n");
    printf("Commands:\n");
    printf("- turn_on\n");
    printf("- turn_off\n");
    printf("- set_brightness [value]\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        Command cmd = parse_command(input);
        execute_command(cmd);
    }

    return 0;
}