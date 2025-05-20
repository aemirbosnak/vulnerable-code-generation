//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork_and_exec(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Enter your commands, sweet Juliet:\n");
    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        char **args = split_command(input);
        pid_t pid = fork_and_exec(args);
        if (pid == -1) {
            printf("Error forking process\n");
        } else if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}

char **split_command(char *command) {
    char **args = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2));
    int argc = 0;
    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        if (argc >= MAX_COMMAND_LENGTH / 2) {
            break;
        }
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;
    return args;
}

pid_t fork_and_exec(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
    }
    return pid;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            printf("Interrupted by Romeo\n");
            break;
        case SIGTERM:
            printf("Terminated by Tybalt\n");
            break;
        default:
            printf("Unknown signal\n");
            break;
    }
}