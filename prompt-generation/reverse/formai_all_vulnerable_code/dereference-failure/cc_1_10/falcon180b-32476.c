//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings
char **split(char *str, char delimiter) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(str, delimiter);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, delimiter);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

// Function to execute a command and wait for it to finish
void execute_command(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Failed to fork\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: Failed to execute %s\n", args[0]);
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Split input into an array of strings
        args = split(input, DELIM);

        // Execute the first command
        execute_command(args);

        // Free memory allocated for the array of strings
        for (int i = 0; args[i]!= NULL; i++) {
            free(args[i]);
        }
        free(args);
    }

    return 0;
}