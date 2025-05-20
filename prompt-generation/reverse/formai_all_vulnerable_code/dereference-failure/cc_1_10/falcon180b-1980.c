//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings
char **split(char *str, int delimiter) {
    int count = 0;
    char **tokens = malloc(sizeof(char *) * (MAX_ARGUMENTS + 1));
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;
    return tokens;
}

// Function to execute a command
void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: No command specified.\n");
        return;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed.\n");
        return;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s not found.\n", args[0]);
            exit(1);
        }
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

// Function to handle signals
void handle_signal(int signal) {
    fprintf(stdout, "\nSignal %d received.\n", signal);
}

// Main function
int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int background = 0;
    int exit_shell = 0;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (!exit_shell) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split(input, 0);
        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            exit_shell = 1;
        } else if (strcmp(args[0], "bg") == 0) {
            background = 1;
        } else {
            execute_command(args);
        }
    }

    return 0;
}