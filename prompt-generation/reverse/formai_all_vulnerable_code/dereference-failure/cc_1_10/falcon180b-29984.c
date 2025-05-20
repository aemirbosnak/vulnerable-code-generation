//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 1024

char **split_line(char *line) {
    int argc = 0;
    char **argv = malloc(MAX_ARGS * sizeof(char*));
    char *token = strtok(line, " ");

    while (token!= NULL && argc < MAX_ARGS) {
        argv[argc++] = strdup(token);
        token = strtok(NULL, " ");
    }

    argv[argc] = NULL;
    return argv;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_LINE];
    char **args = NULL;
    int status;

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        args = split_line(input);
        status = execute_command(args);

        free(args);
    }

    return 0;
}