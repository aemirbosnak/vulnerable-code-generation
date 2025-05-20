//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
        }

        token = strtok(NULL, DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    }

    return pid;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
        case SIGTERM:
            printf("\nExiting...\n");
            exit(0);
        default:
            printf("Unknown signal %d\n", signum);
    }
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    printf("Welcome to the Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        pid = launch_shell(args);

        waitpid(pid, NULL, 0);
    }

    return 0;
}