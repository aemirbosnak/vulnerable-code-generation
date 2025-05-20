//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork_and_exec(char **args);
void handle_signal(int signum);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_command(input);

        pid_t pid = fork_and_exec(args);

        if (pid == -1) {
            fprintf(stderr, "Error forking process.\n");
        } else if (pid == 0) {
            execvp(args[0], args);
            fprintf(stderr, "Error executing command.\n");
            exit(1);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char *token = strtok(command, DELIM);
    int count = 0;
    char **args = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2));

    while (token!= NULL && count < MAX_COMMAND_LENGTH / 2) {
        args[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }

    args[count] = NULL;
    return args;
}

pid_t fork_and_exec(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        fprintf(stderr, "Error executing command.\n");
        exit(1);
    }

    return pid;
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\nExiting...\n");
        exit(0);
    }
}