//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define BUF_SIZE 1024
#define MAX_ARGS 256

char **args;
int argc;

void print_prompt() {
    printf("> ");
}

void parse_args(char *input) {
    char *token;
    int i = 0;

    token = strtok(input, " ");
    while (token!= NULL) {
        if (i >= MAX_ARGS) {
            printf("Too many arguments\n");
            exit(1);
        }
        args[i] = strdup(token);
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

int launch_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error executing command\n");
            exit(1);
        }
    } else if (pid < 0) {
        printf("Error forking\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        }
    }
    return -1;
}

int main() {
    char input[BUF_SIZE];
    int status;

    args = malloc(MAX_ARGS * sizeof(char *));
    argc = 0;

    while (1) {
        print_prompt();
        fgets(input, BUF_SIZE, stdin);
        parse_args(input);

        status = launch_command(args);
        if (status == -1) {
            continue;
        } else {
            break;
        }
    }

    free(args);
    return 0;
}