//Code Llama-13B DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
/*
 * Adventure Game
 * -------------
 *
 * This program is a simple text-based adventure game.
 * It prompts the user to enter a command, and then displays
 * the results of that command.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 256
#define MAX_COMMANDS 10

// Structure to store the command and its description
typedef struct {
    char command[MAX_LINE];
    char description[MAX_LINE];
} command_t;

// Array of commands and their descriptions
command_t commands[MAX_COMMANDS] = {
    { "north", "Go north" },
    { "south", "Go south" },
    { "east", "Go east" },
    { "west", "Go west" },
    { "look", "Look around" },
    { "inventory", "View inventory" },
    { "take", "Take an item" },
    { "drop", "Drop an item" },
    { "quit", "Quit the game" }
};

// Function to get the user's command
char *get_command() {
    char *command = malloc(MAX_LINE);
    if (command == NULL) {
        printf("Error: Could not allocate memory for command.\n");
        exit(1);
    }
    printf("> ");
    fgets(command, MAX_LINE, stdin);
    command[strlen(command) - 1] = '\0';
    return command;
}

// Function to execute the user's command
void execute_command(char *command) {
    int i;
    for (i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(commands[i].command, command) == 0) {
            printf("%s\n", commands[i].description);
            break;
        }
    }
    if (i == MAX_COMMANDS) {
        printf("Invalid command.\n");
    }
}

int main() {
    char *command;
    while (1) {
        command = get_command();
        execute_command(command);
        free(command);
    }
    return 0;
}