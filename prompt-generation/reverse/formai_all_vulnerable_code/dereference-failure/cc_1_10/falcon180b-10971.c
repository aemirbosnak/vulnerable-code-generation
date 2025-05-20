//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string, char delimiter);
void execute_command(char **arguments);
bool is_builtin_command(char *command);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *username = "Sir";

    printf("Welcome, %s! Enter your commands:\n", username);

    while (1) {
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        char **arguments = split_string(input, DELIM);
        if (arguments[0] == NULL)
            continue;

        if (is_builtin_command(arguments[0])) {
            execute_command(arguments);
        } else {
            char *output = malloc(MAX_COMMAND_LENGTH);
            sprintf(output, "Unknown command: %s\n", arguments[0]);
            printf("%s", output);
            free(output);
        }
    }

    return 0;
}

char **split_string(char *string, char delimiter) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));

    char *token = strtok(string, delimiter);
    while (token!= NULL) {
        tokens[count] = token;
        count++;
        if (count >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, delimiter);
    }
    tokens[count] = NULL;

    return tokens;
}

void execute_command(char **arguments) {
    if (strcmp(arguments[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(arguments[0], "cd") == 0) {
        if (arguments[1] == NULL) {
            printf("Usage: cd [directory]\n");
        } else {
            char *output = malloc(MAX_COMMAND_LENGTH);
            sprintf(output, "Changing directory to %s...\n", arguments[1]);
            printf("%s", output);
            free(output);
        }
    } else if (strcmp(arguments[0], "ls") == 0) {
        printf("Listing files and directories:\n");
    } else {
        printf("Invalid command\n");
    }
}

bool is_builtin_command(char *command) {
    if (strcmp(command, "exit") == 0 ||
        strcmp(command, "cd") == 0 ||
        strcmp(command, "ls") == 0) {
        return true;
    }
    return false;
}