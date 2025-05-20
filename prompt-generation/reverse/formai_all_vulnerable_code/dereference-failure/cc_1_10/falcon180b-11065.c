//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
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

command_t *parse_command(char *input) {
    command_t *command = malloc(sizeof(command_t));
    char *token = strtok(input, DELIM);
    command->arguments = malloc((MAX_ARGUMENTS - 1) * sizeof(char *));
    command->argument_count = 0;

    while (token!= NULL && command->argument_count < MAX_ARGUMENTS) {
        command->arguments[command->argument_count] = strdup(token);
        command->argument_count++;
        token = strtok(NULL, DELIM);
    }

    command->arguments[command->argument_count] = NULL;

    return command;
}

void execute_command(command_t *command) {
    if (command->argument_count == 0) {
        printf("No command specified.\n");
        return;
    }

    char *command_name = command->arguments[0];

    if (strcmp(command_name, "exit") == 0) {
        exit(0);
    } else if (strcmp(command_name, "help") == 0) {
        printf("Usage: %s [command]\n", command_name);
        printf("Commands:\n");
        printf("  exit   - Exit the shell\n");
        printf("  help   - Display this help message\n");
    } else {
        printf("Unknown command: %s\n", command_name);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *trimmed_input = strdup(input);
        char *token = strtok(trimmed_input, DELIM);
        while (token!= NULL) {
            *token = tolower(*token);
            token = strtok(NULL, DELIM);
        }

        command_t *command = parse_command(trimmed_input);
        execute_command(command);

        free(command->arguments);
        free(command);
        free(trimmed_input);
    }

    return 0;
}