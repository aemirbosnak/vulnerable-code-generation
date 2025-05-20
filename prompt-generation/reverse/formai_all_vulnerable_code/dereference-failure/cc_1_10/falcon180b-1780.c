//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*string) {
        if (strchr(DELIM, *string)) {
            *string++ = '\0';
        } else {
            bufsize++;
        }
    }

    tokens = malloc((bufsize + 1) * sizeof(char *));
    if (tokens == NULL) {
        fprintf(stderr, "Error: malloc() failed\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(string, DELIM);
    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: command not found\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: fork() failed\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while (1) {
        printf("> ");
        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
            fprintf(stderr, "Error: fgets() failed\n");
            exit(EXIT_FAILURE);
        }

        args = split_string(input);
        if (args[0] == NULL) {
            continue;
        }

        execute_command(args);
        free(args);
    }

    return 0;
}