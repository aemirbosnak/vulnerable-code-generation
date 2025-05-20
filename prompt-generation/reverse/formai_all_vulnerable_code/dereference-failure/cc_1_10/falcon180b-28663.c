//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split(char *line) {
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(line, DELIM);
    int count = 0;

    while (token!= NULL) {
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int main() {
    char input[MAX_LINE];
    char **args;
    pid_t pid;
    int status;

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        args = split(input);
        if (args[0] == NULL)
            continue;

        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(1);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}