//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// Function to execute a command and wait for its completion
int execute_command(char **args) {
    pid_t pid;
    int status;

    if ((pid = fork()) == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
        return status;
    }
}

// Function to read input from the user
char *read_input() {
    char *input = NULL;
    char ch;
    int len = 0;

    while ((ch = getchar())!= '\n') {
        input = realloc(input, len + 2);
        input[len++] = ch;
        input[len] = '\0';
    }

    return input;
}

// Main function
int main() {
    char *input;
    char **args;
    int status;

    while (1) {
        // Read input from the user
        input = read_input();

        // Split input into command and arguments
        args = malloc(sizeof(char *));
        args[0] = strtok(input, " ");
        for (int i = 1; args[0]!= NULL; i++) {
            args = realloc(args, sizeof(char *) * (i + 1));
            args[i] = strtok(NULL, " ");
        }

        // Execute command
        status = execute_command(args);

        // Print output
        if (status == 0) {
            printf("Output:\n");
        } else {
            printf("Error: %d\n", status);
        }

        free(args);
        free(input);
    }

    return 0;
}