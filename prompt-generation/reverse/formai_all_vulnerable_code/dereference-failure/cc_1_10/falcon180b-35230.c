//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\n\r\a"

char **split_string(char *str) {
    int count = 0;
    char **args = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(str, DELIM);
    while (token!= NULL) {
        args[count++] = token;
        if (count == MAX_ARGUMENTS) {
            printf("Too many arguments\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    args[count] = NULL;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
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
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Unix Shell\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        char **args = split_string(input);
        int result = execute_command(args);

        if (result == 1) {
            printf("Command not found\n");
        }
    }

    return 0;
}