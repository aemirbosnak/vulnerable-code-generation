//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

// Function to split the input string into arguments
char **split_args(char *line) {
    char **args = malloc(sizeof(char *) * MAX_ARGS);
    char *arg;

    int i = 0;
    while ((arg = strtok(line, " ")) != NULL) {
        args[i] = arg;
        i++;
    }

    args[i] = NULL; // Null-terminate the array of arguments
    return args;
}

// Function to execute a command
int execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    } else {
        // Fork failed
        perror("fork");
        return -1;
    }
}

// Main function
int main() {
    char line[MAX_LINE_LENGTH];
    char **args;

    while (1) {
        // Print the prompt
        printf("myshell> ");

        // Read the input line
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            break;
        }

        // Remove the newline character from the end of the line
        line[strlen(line) - 1] = '\0';

        // Split the line into arguments
        args = split_args(line);

        // Execute the command
        int status = execute_command(args);

        // Free the allocated memory
        free(args);

        // Check if the user entered "exit"
        if (strcmp(args[0], "exit") == 0) {
            break;
        }
    }

    return 0;
}