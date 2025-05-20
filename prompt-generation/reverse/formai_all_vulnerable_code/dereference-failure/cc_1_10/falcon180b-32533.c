//Falcon-180B DATASET v1.0 Category: Recursive ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_ARGUMENT_LENGTH 1024

typedef struct {
    char *command;
    int arguments;
    char **argument_strings;
} Command;

void execute_command(Command *command) {
    if (command->arguments > MAX_ARGUMENTS) {
        printf("Error: Too many arguments\n");
        return;
    }

    for (int i = 0; i < command->arguments; i++) {
        printf("Argument %d: %s\n", i + 1, command->argument_strings[i]);
    }
}

void parse_command(char *input, Command *command) {
    char *token;
    char *saveptr;
    char *arguments_string = strdup(input);
    command->arguments = 0;
    command->argument_strings = malloc(MAX_ARGUMENTS * sizeof(char *));

    token = strtok_r(arguments_string, " ", &saveptr);
    while (token!= NULL) {
        command->argument_strings[command->arguments] = strdup(token);
        command->arguments++;
        token = strtok_r(NULL, " ", &saveptr);
    }

    command->command = strdup(input);
}

void run_command(char *input) {
    Command command;
    parse_command(input, &command);
    execute_command(&command);
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter a command: ");
        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
            printf("Error: Failed to read input\n");
            return 1;
        }

        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        run_command(input);
    }

    return 0;
}