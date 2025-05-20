//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

char **split_command(char *command) {
    char **args = malloc(MAX_ARGUMENTS * sizeof(char*));
    int argc = 0;
    char *token;

    token = strtok(command, " ");
    while (token!= NULL) {
        args[argc++] = token;
        if (argc == MAX_ARGUMENTS) {
            printf("Error: Too many arguments\n");
            exit(1);
        }
        token = strtok(NULL, " ");
    }

    args[argc] = NULL;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        printf("Error: No command specified\n");
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            printf("Error: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid < 0) {
        // Error forking
        printf("Error: %s\n", strerror(errno));
        exit(1);
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Basic Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        args = split_command(input);
        if (args == NULL) {
            continue;
        }

        int result = execute_command(args);
        if (result == -1) {
            printf("Child process terminated by signal\n");
        }
    }

    return 0;
}