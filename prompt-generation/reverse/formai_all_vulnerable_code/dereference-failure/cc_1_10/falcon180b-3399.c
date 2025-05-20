//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define EXIT_FAILURE 1

char **split_string(char *str) {
    int buf_size = 0, words = 0;
    char **tokens = NULL;
    char *token;
    char delimiter[2] = { DELIM[0], '\0' };

    token = strtok(str, delimiter);
    while (token!= NULL) {
        buf_size++;
        words++;
        token = strtok(NULL, delimiter);
    }

    tokens = malloc(buf_size * sizeof(char *));
    if (tokens == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(str, delimiter);
    int i = 0;
    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, delimiter);
    }
    tokens[i] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("Fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Ada Lovelace Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);
        execute_command(args);
    }

    return 0;
}