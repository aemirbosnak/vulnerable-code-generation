//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string, int *count) {
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    int i = 0;
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL && i < MAX_ARGUMENTS - 1) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    *count = i;
    return tokens;
}

int launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int count;

    printf("Welcome to the Basic Unix-like Shell!\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        args = split_string(input, &count);
        if (count == 0) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else {
            launch_shell(args);
        }
    }

    return 0;
}