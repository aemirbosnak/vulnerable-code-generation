//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Maximum length of command line
#define MAX_ARGS 10 // Maximum number of arguments in command line

// Function to parse the command line into an array of arguments
void parse_args(char *line, char **args) {
    int i = 0;
    char *token;

    // Get the first argument
    token = strtok(line, " ");

    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    args[i] = NULL; // Set the last argument to NULL
}

int main() {
    char *args[MAX_ARGS + 1]; // Array to hold the command line arguments
    char line[MAX_LINE + 1]; // Buffer to hold the command line
    pid_t pid; // Process ID of the child process
    int status; // Status of the child process

    // Main shell loop
    while (1) {
        printf("brave-shell> ");
        fgets(line, MAX_LINE, stdin); // Read the command line

        if (line[0] == '\n') {
            continue; // Ignore empty command line
        }

        line[strlen(line) - 1] = '\0'; // Remove newline character

        // Exit if "exit" command is entered
        if (strcmp(line, "exit") == 0) {
            break;
        }

        parse_args(line, args); // Parse the command line into arguments

        // Create child process
        pid = fork();

        if (pid == 0) { // Child process
            execvp(args[0], args); // Execute the command
            perror("Error"); // Print error message if command fails
            exit(1); // Terminate child process
        }
        else if (pid < 0) { // Fork failed
            perror("Error");
        }
        else { // Parent process
            waitpid(pid, &status, 0); // Wait for child process to terminate
        }
    }

    return 0;
}