//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64

// Function to split the command line into arguments
char** split_args(char* line) {
    char** args = malloc(sizeof(char*) * MAX_ARGS);
    int num_args = 0;

    char* token = strtok(line, " ");
    while (token != NULL) {
        args[num_args++] = token;
        token = strtok(NULL, " ");
    }

    args[num_args] = NULL; // Null-terminate the array of arguments

    return args;
}

// Function to execute a command
int execute_command(char** args) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        int status = execvp(args[0], args);
        if (status == -1) {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    } else {
        // Error forking
        perror("Error forking");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// Function to run the shell
void run_shell() {
    char line[MAX_LINE_LENGTH];

    while (1) {
        // Print the prompt
        printf("sh> ");

        // Read a line from the user
        fgets(line, MAX_LINE_LENGTH, stdin);

        // Remove the newline character from the end of the line
        line[strlen(line) - 1] = '\0';

        // Split the line into arguments
        char** args = split_args(line);

        // Check if the user entered "exit" to quit the shell
        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        // Execute the command
        int status = execute_command(args);

        // Free the memory allocated for the arguments
        free(args);
    }
}

int main() {
    // Run the shell
    run_shell();

    return EXIT_SUCCESS;
}