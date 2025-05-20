//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_PIPE_LENGTH 10
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));

    char *token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[count++] = token;
        if (count >= MAX_ARGUMENTS) {
            printf("Error: Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        printf("Error: Command not found.\n");
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            printf("Error: Directory not specified.\n");
            return 1;
        }
        if (chdir(args[1])!= 0) {
            perror("chdir");
            return 1;
        }
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            if (execvp(args[0], args)!= 0) {
                perror("execvp");
                exit(1);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        execute_command(args);
    }

    return 0;
}