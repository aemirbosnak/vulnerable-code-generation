//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position == bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;

    return tokens;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL)
        return 1;

    if (strcmp(tokens[0], "exit") == 0) {
        return 0;
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1]!= NULL) {
            if (chdir(tokens[1])!= 0) {
                perror("Error");
            }
        } else {
            fprintf(stderr, "Expected argument to \"cd\"\n");
        }
    } else if (strcmp(tokens[0], "pwd") == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd))!= NULL) {
            printf("%s\n", cwd);
        } else {
            perror("Error");
        }
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid > 0) {
            waitpid(pid, &status, 0);
        } else {
            if (execvp(tokens[0], tokens) == -1) {
                perror("execvp");
            }
        }
    }

    return 1;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;
    int running = 1;

    while (running) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        tokens = split_string(input);
        execute_command(tokens);
    }

    return 0;
}