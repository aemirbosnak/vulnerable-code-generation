//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *command;
    char **args;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        command = strtok(input, DELIM);
        args = split_command(command);

        if (args[0] == NULL) {
            continue;
        }

        execute_command(args);
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = malloc(sizeof(char *));

    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        args = realloc(args, sizeof(char *) * ++argc);
        args[argc - 1] = token;

        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            printf("Usage: cd [directory]\n");
        } else {
            if (chdir(args[1])!= 0) {
                perror("chdir");
            }
        }
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
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