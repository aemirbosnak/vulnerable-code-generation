//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (strchr(DELIM, *str)) {
            *str = '\0';
            bufsize++;
        }
        str++;
    }

    tokens = malloc((bufsize + 1) * sizeof(char *));
    if (!tokens) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    str = strtok(str, DELIM);
    while (str) {
        tokens[i] = strdup(str);
        i++;
        str = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s not found.\n", args[0]);
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

    fprintf(stdout, "Welcome to the Basic Unix-like Shell!\n");
    fprintf(stdout, "Type 'exit' to quit.\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        args = split_string(input);

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else {
            execute_command(args);
        }
    }

    return 0;
}