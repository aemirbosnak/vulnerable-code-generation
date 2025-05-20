//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    char **tokens = malloc(sizeof(char *));
    int buf_size = 0;
    char *token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[buf_size] = malloc(sizeof(char) * strlen(token) + 1);
        strcpy(tokens[buf_size], token);
        buf_size++;
        token = strtok(NULL, DELIM);
    }
    tokens[buf_size] = NULL;
    return tokens;
}

int launch_shell() {
    char input[MAX_COMMAND_LENGTH];
    printf("My Shell > ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    char **args = split_string(input);
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
    return 0;
}

int main() {
    while (1) {
        launch_shell();
    }
    return 0;
}