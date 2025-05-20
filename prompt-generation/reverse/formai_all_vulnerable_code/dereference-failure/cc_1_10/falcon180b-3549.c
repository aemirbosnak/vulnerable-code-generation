//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Split a string into an array of strings using a delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char **result;
    char *token;

    result = malloc(1024 * sizeof(char *));
    if (result == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    token = strtok(str, delimiter);
    while (token!= NULL) {
        result[count++] = token;
        token = strtok(NULL, delimiter);
    }

    result[count] = NULL;
    return result;
}

// Execute a command and wait for it to finish
void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

// Main shell loop
int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int background = 0;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Split input into an array of strings
        args = split(input, DELIM);

        // Check if the command is "exit"
        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        // Check if the command should be executed in the background
        if (strcmp(args[0], "&") == 0) {
            background = 1;
            args[0] = args[1];
            args[1] = NULL;
        }

        // Execute the command
        execute_command(args);
    }

    return 0;
}