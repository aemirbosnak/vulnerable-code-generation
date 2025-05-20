//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;
    return tokens;
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
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **args = split_string(input);
    execute_command(args);

    return 0;
}