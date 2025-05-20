//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork_and_exec(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_command(input);

        if (args[0] == NULL) {
            continue;
        }

        pid_t pid = fork_and_exec(args);

        if (pid == -1) {
            perror("fork");
        } else if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char *token;
    char **args = malloc(sizeof(char *) * MAX_ARGUMENTS);
    int argc = 0;

    token = strtok(command, DELIM);
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

pid_t fork_and_exec(char **args) {
    pid_t pid;

    if (args[0] == NULL) {
        return -1;
    }

    pid = fork();

    if (pid == -1) {
        return -1;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    }

    return pid;
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\n");
    }
}