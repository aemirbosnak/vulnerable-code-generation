//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    argv = (char **)malloc((MAX_COMMAND_LENGTH / 2) * sizeof(char *));
    if (argv == NULL) {
        fprintf(stderr, "Error: malloc() failed\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_COMMAND_LENGTH / 2) {
            fprintf(stderr, "Error: command too long\n");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

void execute_command(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: fork() failed\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error: execvp() failed\n");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            fprintf(stdout, "\nInterrupted\n");
            break;
        case SIGQUIT:
            fprintf(stdout, "\nQuit\n");
            break;
        default:
            fprintf(stdout, "Signal %d received\n", signum);
            break;
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);

    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        argv = split_command(input);
        execute_command(argv);
    }

    return 0;
}