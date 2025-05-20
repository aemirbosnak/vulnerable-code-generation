//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_CMD_LENGTH 100

void parse_args(char *input, char **args)
{
    int i = 0;
    char *token = strtok(input, " ");

    while (token != NULL && i < MAX_ARGS) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    args[i] = NULL;
}

int main()
{
    char input[MAX_CMD_LENGTH];
    char *args[MAX_ARGS];
    pid_t pid;

    while (1) {
        printf("> ");
        fgets(input, MAX_CMD_LENGTH, stdin);
        input[strlen(input) - 1] = '\0'; // remove trailing newline

        parse_args(input, args);

        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        pid = fork();

        if (pid < 0) {
            perror("fork error");
            exit(1);
        }

        if (pid == 0) {
            execvp(args[0], args);
            perror("execvp error");
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}