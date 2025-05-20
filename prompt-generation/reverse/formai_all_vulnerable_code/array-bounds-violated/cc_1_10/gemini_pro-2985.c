//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

// Function to split a string into an array of strings
char **split_string(char *line) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *token;
    int i = 0;

    token = strtok(line, " ");
    while (token != NULL) {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;
    return args;
}

// Function to execute a command
int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid > 0) {
        // Parent process
        waitpid(pid, &status, 0);
    } else {
        // Error
        perror("Error creating child process");
        return 1;
    }
    return 0;
}

// Main function
int main() {
    char line[MAX_LINE_LENGTH];
    char **args;
    int status = 0;

    printf("Welcome to the Unix-like Shell!\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("> ");
        fgets(line, MAX_LINE_LENGTH, stdin);
        line[strlen(line) - 1] = '\0';  // Remove newline character

        if (strcmp(line, "exit") == 0) {
            break;
        }

        args = split_string(line);
        status = execute_command(args);

        if (status != 0) {
            printf("Error executing command.\n");
        }
    }

    printf("Exiting the shell.\n");
    return 0;
}