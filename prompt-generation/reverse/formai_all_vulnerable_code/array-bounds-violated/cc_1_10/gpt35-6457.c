//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100 // Maximum length of a shell command
#define MAX_ARGS 10 // Maximum number of arguments in a shell command

// Function to execute a shell command
void execute_command(char *command[], int background) {
    pid_t child_pid;
    int child_status;

    child_pid = fork();

    if (child_pid == 0) {
        // Child process
        if (background) {
            // Redirecting stdout to /dev/null for background processes
            freopen("/dev/null", "w", stdout);
            freopen("/dev/null", "w", stderr);
        }
        execvp(command[0], command);
        printf("Unknown command: %s\n", command[0]);
        exit(0);
    } else {
        // Parent process
        if (!background) {
            // Waiting for child to complete its execution
            waitpid(child_pid, &child_status, 0);
        }
        return;
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH]; // Buffer to store input command
    char *args[MAX_ARGS]; // Array of pointers to store command and arguments
    char *token; // Token to split input into command and arguments
    int i, num_args, background;

    while(1) {
        // Reading input from user
        printf(">> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Removing trailing newline character
        command[strlen(command) - 1] = '\0';

        // Splitting input into command and arguments
        token = strtok(command, " ");
        i = 0;
        num_args = 0;
        background = 0;

        while (token != NULL) {
            if (strcmp(token, "&") == 0) {
                // Setting background flag if last argument is &
                background = 1;
                break;
            }
            args[i++] = token;
            num_args++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (num_args > 0) {
            // Executing command
            execute_command(args, background);
        }
    }
    return 0;
}