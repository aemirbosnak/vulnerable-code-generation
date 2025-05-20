//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int bufsize = 0, words = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*string) {
        if (string[0] == '\"') {
            token = strtok_r(string, "\"", &string);
        } else if (string[0] == '\'') {
            token = strtok_r(string, "'", &string);
        } else {
            token = strtok_r(string, DELIM, &string);
        }

        if (token!= NULL) {
            tokens = realloc(tokens, (bufsize + 1) * sizeof(char *));
            tokens[i++] = token;
            bufsize++;
        }
    }

    tokens[i] = NULL;
    return tokens;
}

pid_t launch_shell(char **tokens) {
    pid_t pid;

    if (tokens[0] == NULL)
        return -1;

    if (strcmp(tokens[0], "exit") == 0) {
        return 0;
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1]!= NULL) {
            if (chdir(tokens[1])!= 0) {
                perror("chdir");
            }
        } else {
            fprintf(stderr, "Expected argument to \"cd\"\n");
        }
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                perror("execvp");
            }
        } else {
            wait(NULL);
        }
    }

    return pid;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;
    pid_t shell_pid;

    printf("Welcome to the Visionary Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        tokens = split_string(input);
        shell_pid = launch_shell(tokens);
    }

    return 0;
}