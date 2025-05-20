//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings using a delimiter
char **split_string(char *str, int *count) {
    char **result = NULL;
    char *token = strtok(str, DELIM);
    int i = 0;

    while (token!= NULL) {
        (*count)++;
        result = realloc(result, sizeof(char *) * (*count));
        result[i] = strdup(token);
        i++;
        token = strtok(NULL, DELIM);
    }

    result[i] = NULL;
    return result;
}

// Function to execute a command and wait for it to finish
void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Failed to execute command '%s'\n", args[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

// Function to handle input from the user
void handle_input(char *input) {
    char **args = NULL;
    int count = 0;

    // Split the input into an array of strings
    args = split_string(input, &count);

    // Execute the command
    execute_command(args);

    // Free the memory allocated for the array of strings
    for (int i = 0; i < count; i++) {
        free(args[i]);
    }
    free(args);
}

// Main function
int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        // Print the prompt
        printf("> ");

        // Read input from the user
        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
            fprintf(stderr, "Failed to read input\n");
            exit(1);
        }

        // Remove the newline character from the end of the input
        input[strcspn(input, "\n")] = '\0';

        // Handle the input
        handle_input(input);
    }

    return 0;
}