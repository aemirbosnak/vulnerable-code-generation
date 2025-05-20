//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LENGTH 80 // Maximum command length
#define MAX_ARGUMENTS 10 // Maximum number of arguments that can be passed to the command

int main(void) {
    char command[MAX_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int should_run = 1; // Flag to determine when to exit the shell
    pid_t pid; // Process ID
    int status; // Status of the child process

    while (should_run) {
        printf("osh>");
        fflush(stdout); // Flush the output buffer

        // Read the command input
        fgets(command, MAX_LENGTH, stdin);
        command[strlen(command) - 1] = '\0'; // Remove the newline character at the end

        // Tokenize the arguments of the command
        char *token = strtok(command, " ");
        int i = 0;
        while (token != NULL) {
            arguments[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        arguments[i] = NULL; // Set the last argument to NULL for execvp

        if (strcmp(arguments[0], "exit") == 0) { // Exit the shell
            should_run = 0;
            continue;
        }

        pid = fork(); // Fork a new process
        if (pid < 0) { // Fork failed
            fprintf(stderr, "Fork failed\n");
            return 1;
        } else if (pid == 0) { // Child process
            execvp(arguments[0], arguments); // Execute the command
            fprintf(stderr, "Error executing command\n");
            return 1;
        } else { // Parent process
            waitpid(pid, &status, 0); // Wait for the child process to complete
        }
    }

    return 0;
}