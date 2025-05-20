//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        status = execute_command(args);

        if (status == 1) {
            printf("Child process terminated with signal 11\n");
        }
    }

    return 0;
}

char **split_string(char *str) {
    int argc = 0;
    int len = strlen(str);
    char **args = malloc((MAX_ARGUMENTS + 1) * sizeof(char*));

    char *token = strtok(str, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
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

    pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        perror("Error executing command");
        exit(1);
    } else if (pid < 0) {
        perror("Error forking");
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}