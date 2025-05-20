//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_COMMANDS 1000
#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int bufsize = MAX_COMMANDS, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += MAX_COMMANDS;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid;

    if (args[0] == NULL)
        return -1;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    }

    return pid;
}

int main() {
    char input[MAX_LINE];
    char **args;
    pid_t pid;

    printf("Unix-Like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        args = split_line(input);

        if (args[0] == NULL)
            continue;

        pid = launch_shell(args);

        if (pid == -1)
            printf("Error launching shell\n");

        waitpid(pid, NULL, 0);
    }

    return 0;
}