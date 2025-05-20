//Falcon-180B DATASET v1.0 Category: System administration ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *token = strtok(command, DELIM);

    while (token!= NULL && argc < MAX_ARGS) {
        args[argc] = token;
        argc++;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;
    int status;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_command(input);

        if (args[0] == NULL) {
            continue;
        }

        pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}