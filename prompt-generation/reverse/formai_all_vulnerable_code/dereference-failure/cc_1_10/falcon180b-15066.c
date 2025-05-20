//Falcon-180B DATASET v1.0 Category: System administration ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command, int *argc) {
    char **args = malloc(MAX_COMMAND_LENGTH * sizeof(char*));
    int i = 0;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        args[i] = strdup(token);
        i++;
        token = strtok(NULL, DELIM);
    }
    args[i] = NULL;

    *argc = i;
    return args;
}

pid_t fork_and_exec(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return pid;
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int argc;
    pid_t pid;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_command(input, &argc);
        if (argc == 0)
            continue;

        pid = fork_and_exec(args);
        if (pid == -1)
            continue;

        waitpid(pid, NULL, 0);
    }

    return 0;
}