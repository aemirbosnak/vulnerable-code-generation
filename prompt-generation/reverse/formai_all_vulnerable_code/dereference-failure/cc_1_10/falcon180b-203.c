//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

typedef struct {
    char **arguments;
    int argument_count;
} command_t;

void execute_command(command_t *command) {
    if (command->argument_count == 0) {
        printf("No arguments provided for command.\n");
        return;
    }

    char *command_name = command->arguments[0];

    if (strcmp(command_name, "ls") == 0) {
        printf("Listing files...\n");
    } else if (strcmp(command_name, "cd") == 0) {
        if (command->argument_count!= 2) {
            printf("Invalid number of arguments for cd.\n");
            return;
        }

        char *directory = command->arguments[1];
        printf("Changing directory to %s...\n", directory);
    } else if (strcmp(command_name, "pwd") == 0) {
        printf("Current directory: %s\n", getcwd(NULL, 0));
    } else {
        printf("Unknown command: %s\n", command_name);
    }
}

command_t *parse_command(char *input) {
    command_t *command = malloc(sizeof(command_t));
    command->arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    command->argument_count = 0;

    char *token = strtok(input, DELIM);
    while (token!= NULL) {
        command->arguments[command->argument_count++] = token;
        token = strtok(NULL, DELIM);
    }

    return command;
}

void free_command(command_t *command) {
    for (int i = 0; i < command->argument_count; i++) {
        free(command->arguments[i]);
    }
    free(command->arguments);
    free(command);
}

int main() {
    printf("Welcome to the Funny Shell!\n");

    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *trimmed_input = input;
        while (isspace(*trimmed_input)) {
            trimmed_input++;
        }

        if (*trimmed_input == '\0') {
            continue;
        }

        command_t *command = parse_command(trimmed_input);
        execute_command(command);
        free_command(command);
    }

    return 0;
}