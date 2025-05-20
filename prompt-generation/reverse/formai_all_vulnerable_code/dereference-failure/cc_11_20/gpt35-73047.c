//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
// A Unix-like Shell program in C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 20
#define MAX_COMMAND_LENGTH 100

int main() {
    // Print welcome message
    printf("Welcome to My Shell!\n");

    while (1) {
        char command[MAX_COMMAND_LENGTH];
        char* args[MAX_ARGS];

        // Prompt user to enter a command
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from end of command
        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }

        // Split command into arguments
        int arg_count = 0;
        char* arg = strtok(command, " ");
        while (arg != NULL && arg_count < MAX_ARGS - 1) {
            args[arg_count++] = arg;
            arg = strtok(NULL, " ");
        }
        args[arg_count] = NULL; // Last argument must be NULL

        // Check for built-in commands
        if (strcmp(args[0], "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }
        else if (strcmp(args[0], "cd") == 0) {
            if (chdir(args[1]) == -1) {
                perror("cd");
            }
            continue;
        }

        // Fork a child process to execute command
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
        }
        else if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror(args[0]); // execvp only returns if there's an error
            exit(1);
        }
        else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                printf("Child process exited with status %d\n", WEXITSTATUS(status));
            }
        }
    }

    return 0;
}