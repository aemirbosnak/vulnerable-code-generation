//Falcon-180B DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

// Function to execute a command
void execute_command(char *command) {
    pid_t pid;
    int status;

    // Fork a new process to execute the command
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Failed to fork: %s\n", strerror(errno));
        exit(1);
    } else if (pid == 0) {
        // Child process
        char *argv[MAX_ARGUMENTS];
        int argc = 0;

        // Parse the command into arguments
        char *token = strtok(command, " ");
        while (token!= NULL) {
            argv[argc++] = token;
            token = strtok(NULL, " ");
        }
        argv[argc] = NULL;

        // Execute the command
        execvp(argv[0], argv);
        fprintf(stderr, "Failed to execute command: %s\n", strerror(errno));
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

// Function to handle signals
void handle_signal(int signal) {
    switch (signal) {
        case SIGINT:
            fprintf(stdout, "Interrupted by user\n");
            break;
        case SIGTERM:
            fprintf(stdout, "Terminated\n");
            break;
        default:
            fprintf(stdout, "Received signal %d\n", signal);
            break;
    }
}

// Main function
int main() {
    char input[MAX_COMMAND_LENGTH];
    char *command;
    int command_length;

    // Set up signal handlers
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    // Loop to read commands and execute them
    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        // Parse the input into a command
        command = strtok(input, " ");
        command_length = strlen(command);

        // Check if the command is empty
        if (command_length == 0) {
            continue;
        }

        // Execute the command
        execute_command(command);
    }

    return 0;
}