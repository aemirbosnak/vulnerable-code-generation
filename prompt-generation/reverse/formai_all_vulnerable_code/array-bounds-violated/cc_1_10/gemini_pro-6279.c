//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

// Prototypes
int parse_args(char *line, char **args);
int execute(char **args);
void print_prompt();

// Main function
int main() {
    // Declare variables
    char line[MAX_LINE_LENGTH];
    char *args[MAX_ARGS];
    int status;

    // Print greeting
    printf("Welcome to the funniest shell in the world!\n");

    // Main loop
    while (1) {
        // Print prompt
        print_prompt();

        // Get input
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            break;
        }

        // Remove newline
        line[strlen(line) - 1] = '\0';

        // Parse arguments
        if (parse_args(line, args) == -1) {
            fprintf(stderr, "Invalid command\n");
            continue;
        }

        // Execute command
        if (execute(args) == -1) {
            fprintf(stderr, "Failed to execute command\n");
            continue;
        }

        // Wait for child process to finish
        wait(&status);
    }

    // Exit
    return 0;
}

// Parse arguments
int parse_args(char *line, char **args) {
    int i = 0;
    char *token;

    // Get first token
    token = strtok(line, " ");
    if (token == NULL) {
        return -1;
    }

    // Get remaining tokens
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    // Terminate args array
    args[i] = NULL;

    return 0;
}

// Execute command
int execute(char **args) {
    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        return -1;
    }

    // Child process
    if (pid == 0) {
        // Execute command
        if (execvp(args[0], args) == -1) {
            return -1;
        }
    
        // If we reach this point, execvp failed
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    // Parent process
    else {
        // Wait for child process to finish
        int status;
        wait(&status);

        // Print exit status
        if (WIFEXITED(status)) {
            printf("Exit status: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Terminated by signal: %d\n", WTERMSIG(status));
        }
    }

    return 0;
}

// Print prompt
void print_prompt() {
    printf("funshell> ");
}