//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 100
#define DELIM " \t\r\n\a"

char **split(char *line);
int execute_command(char **args);

int main() {
    char input[1024];
    char **args;
    int status;

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        args = split(input);
        status = execute_command(args);

        if (status == 1) {
            printf("Child process exited with non-zero status\n");
        }
    }

    return 0;
}

char **split(char *line) {
    int count = 0;
    char *token;
    char **tokens = malloc(MAX_COMMANDS * sizeof(char *));

    if (tokens == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    token = strtok(line, DELIM);
    while (token!= NULL) {
        tokens[count++] = token;
        if (count >= MAX_COMMANDS) {
            fprintf(stderr, "Too many arguments\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Failed to execute command: %s\n", args[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}