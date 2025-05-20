//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

int main() {
    while (1) {
        char input[MAX_COMMAND_LENGTH];
        char* arguments[MAX_ARGUMENTS];

        printf(">> ");

        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
            break;
        }

        // Remove newline character
        input[strlen(input)-1] = '\0';

        // Split input into arguments
        char* argument;
        int argument_index = 0;
        argument = strtok(input, " ");
        while (argument != NULL) {
            arguments[argument_index] = argument;
            argument_index++;
            argument = strtok(NULL, " ");
        }
        arguments[argument_index] = NULL;

        // Check for exit command
        if (strcmp(arguments[0], "exit") == 0) {
            break;
        }

        // Create child process
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execvp(arguments[0], arguments);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(NULL);
        }
    }

    return 0;
}