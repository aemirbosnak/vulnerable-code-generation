//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024 // Maximum length of command
#define MAX_ARGS 64 // Maximum number of arguments

int main(void) {
    char command[MAX_LENGTH]; // Command entered by user
    char *arguments[MAX_ARGS]; // Array of command arguments
    char *token; // Token used to split command into arguments
    int status; // Status of child process
    pid_t pid; // Process ID of child process

    while (1) {
        printf("StatShell> "); // Prompt user for input
        fgets(command, sizeof(command), stdin); // Read command entered by user
        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0'; // Remove newline character
        }

        if (strcmp(command, "exit") == 0) { // Check if user entered "exit"
            break; // Exit loop
        }

        int i = 0;
        token = strtok(command, " "); // Split command into arguments using whitespace as delimiter
        while (token != NULL && i < MAX_ARGS - 1) { // Loop through all arguments and add them to arguments array
            arguments[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        arguments[i] = NULL; // Null terminate arguments array

        pid = fork(); // Create child process
        if (pid == 0) { // Child process
            execvp(arguments[0], arguments); // Execute command entered by user
            perror("execvp"); // Print error message if command failed to execute
            exit(EXIT_FAILURE); // Exit child process with failure status
        } else if (pid > 0) { // Parent process
            waitpid(pid, &status, 0); // Wait for child process to finish executing
            if (WIFEXITED(status)) {
                printf("Child process exited with status %d\n", WEXITSTATUS(status)); // Print status of child process
            }
        } else { // Error in creating child process
            perror("fork"); // Print error message
        }
    }

    exit(EXIT_SUCCESS); // Exit program with success status
}