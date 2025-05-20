//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **split_command(char *command, int *argc) {
    char **args = malloc(MAX_ARGUMENTS * sizeof(char*));
    int i = 0;
    char *token = strtok(command, DELIM);

    while (token!= NULL && i < MAX_ARGUMENTS) {
        args[i] = token;
        i++;
        token = strtok(NULL, DELIM);
    }

    *argc = i;
    args[i] = NULL;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
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

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int argc;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_command(input, &argc);
    execute_command(args);

    free(args);
}

int main(void) {
    loop();
    return 0;
}