//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings
char **split_string(char *str) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
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
        fprintf(stderr, "Error: No command specified\n");
        return;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed\n");
        return;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s not found\n", args[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

// Function to handle signals
void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            fprintf(stdout, "\nInterrupted\n");
            break;
        case SIGQUIT:
            fprintf(stdout, "\nQuit\n");
            break;
        case SIGTERM:
            fprintf(stdout, "\nTerminated\n");
            break;
        default:
            fprintf(stdout, "Signal %d received\n", signum);
            break;
    }
}

// Function to loop and read commands from user
void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        execute_command(args);

        free(args);
    }
}

int main(void) {
    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    loop();

    return 0;
}