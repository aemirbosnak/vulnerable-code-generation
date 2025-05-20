//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

pid_t fork() {
    pid_t pid;

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command found.\n");
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 1;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args = NULL;

    printf("Welcome to the Artistic Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        execute_command(args);

        free(args);
    }

    return 0;
}