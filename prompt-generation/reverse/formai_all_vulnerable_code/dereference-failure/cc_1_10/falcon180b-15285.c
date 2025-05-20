//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings
char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

// Function to execute a command
void execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        fprintf(stderr, "Error: No command specified.\n");
        exit(1);
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Failed to fork.\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            fprintf(stderr, "Error: Failed to execute command.\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, WUNTRACED);
    }
}

// Function to handle signals
void handle_signal(int signal) {
    switch (signal) {
        case SIGINT:
            fprintf(stdout, "\nInterrupted.\n");
            break;
        case SIGQUIT:
            fprintf(stdout, "\nQuit.\n");
            exit(0);
        default:
            fprintf(stdout, "Received signal %d.\n", signal);
    }
}

// Main function
int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;
    int status;

    // Install signal handlers
    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);

    // Print welcome message
    fprintf(stdout, "Welcome to the Basic Unix-like Shell!\n");

    // Main loop
    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Split input into arguments
        arguments = split_string(input);

        // Execute command
        execute_command(arguments);

        // Free memory
        for (int i = 0; arguments[i]!= NULL; i++) {
            free(arguments[i]);
        }
        free(arguments);
    }

    return 0;
}