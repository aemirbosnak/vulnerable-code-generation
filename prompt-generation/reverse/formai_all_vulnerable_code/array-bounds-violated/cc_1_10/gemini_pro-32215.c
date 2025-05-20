//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

void parse_args(char *line, char **args) {
    int i = 0;
    char *arg;

    arg = strtok(line, " ");
    while (arg != NULL) {
        args[i] = arg;
        i++;
        arg = strtok(NULL, " ");
    }
    args[i] = NULL;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        fprintf(stderr, "Error: execvp failed.\n");
        exit(1);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
        return status;
    } else {
        fprintf(stderr, "Error: fork failed.\n");
        return -1;
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *args[MAX_ARGS];
    int status;

    while (1) {
        printf("myshell> ");
        fgets(line, MAX_LINE_LENGTH, stdin);
        line[strlen(line) - 1] = '\0';

        if (strcmp(line, "exit") == 0) {
            exit(0);
        }

        parse_args(line, args);
        status = execute_command(args);

        if (status == -1) {
            fprintf(stderr, "Error: command not found.\n");
        }
    }

    return 0;
}