//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int len = strlen(str);
    char **tokens = malloc(sizeof(char *) * (len + 1));
    char *token = strtok(str, DELIM);
    int i = 0;

    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

void execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }
}

void handle_signal(int signal) {
    switch (signal) {
        case SIGINT:
            printf("\nInterrupted by user\n");
            break;
        case SIGQUIT:
            printf("\nQuit by user\n");
            break;
        case SIGTERM:
            printf("\nTerminated\n");
            break;
        default:
            printf("\nUnknown signal %d\n", signal);
            break;
    }

    exit(0);
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        execute_command(args);
    }

    return 0;
}