//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_LENGTH 80 // Maximum command length
#define MAX_ARG 10 // Maximum number of arguments to command
#define BUFFER_SIZE 1024 // Maximum size of buffer for reading input

int main(void) {
    char command[MAX_LENGTH + 1]; // Buffer for storing command
    char *args[MAX_ARG + 1]; // Array for storing arguments to command
    char buffer[BUFFER_SIZE]; // Buffer for reading user input
    pid_t pid; // Variable for storing the process ID of child process
    int status; // Variable for storing the exit status of the child process

    while (1) {
        printf("> "); // Prompt for user input
        fflush(stdout); // Flush output stream to ensure prompt is displayed

        // Read user input
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            break; // If input is null, break out of while loop
        }

        // Remove newline character at end of input, if present
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }

        // Split user input into command and arguments
        int i = 0;
        args[i] = strtok(buffer, " ");
        while (args[i] != NULL && i < MAX_ARG) {
            i++;
            args[i] = strtok(NULL, " ");
        }
        args[i] = NULL;

        // If no command was entered, prompt again
        if (args[0] == NULL) {
            continue;
        }

        // If user enters "exit", break out of while loop and exit program
        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        // Fork a child process to execute the command
        pid = fork();

        if (pid < 0) { // An error occurred while forking
            fprintf(stderr, "Fork failed\n");
            exit(1);
        } else if (pid == 0) { // Child process
            execvp(args[0], args); // Execute command
            fprintf(stderr, "Command not found\n");
            exit(1);
        } else { // Parent process
            // Wait for child process to complete execution
            waitpid(pid, &status, 0);

            // Check if child process exited normally
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                if (exit_status != 0) {
                    printf("Command failed with exit code %d\n", exit_status);
                }
            } else { // Child process did not exit normally
                fprintf(stderr, "Command failed\n");
            }
        }
    }

    return 0;
}