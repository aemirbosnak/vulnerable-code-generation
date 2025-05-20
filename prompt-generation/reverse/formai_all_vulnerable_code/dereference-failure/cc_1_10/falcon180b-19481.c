//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, count * sizeof(char *));
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;
    return tokens;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) < 0) {
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        exit(1);
    }
    return pid;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL) {
        return 1;
    }

    if (strcmp(tokens[0], "exit") == 0) {
        return 0;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 1;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **tokens = NULL;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        tokens = split_string(input);
        if (execute_command(tokens) == 0) {
            break;
        }

        for (int i = 0; tokens[i]!= NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
        tokens = NULL;
    }

    return 0;
}