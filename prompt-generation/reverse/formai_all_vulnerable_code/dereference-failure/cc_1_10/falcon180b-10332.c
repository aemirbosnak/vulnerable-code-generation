//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork();
int execute_command(char **args);

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_command(input);
        pid_t pid = fork();
        if (pid == 0) {
            execute_command(args);
            exit(0);
        } else if (pid < 0) {
            perror("fork");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}

char **split_command(char *command) {
    char **args = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2));
    int argc = 0;
    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
        if (argc >= MAX_COMMAND_LENGTH / 2) {
            break;
        }
    }
    args[argc] = NULL;
    return args;
}

pid_t fork() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **args) {
    if (args[0] == NULL) {
        return 1;
    }
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
    return 0;
}