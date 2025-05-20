//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL) {
        bufsize++;
        tokens = realloc(tokens, bufsize * sizeof(char*));
        tokens[i] = strdup(token);
        token = strtok(NULL, DELIM);
        i++;
    }
    tokens[i] = NULL;

    return tokens;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL)
        return 1;

    pid = fork();

    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, WUNTRACED);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;

    printf("Welcome to the Retro Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        tokens = split_string(input);
        execute_command(tokens);

        free(tokens);
    }

    return 0;
}