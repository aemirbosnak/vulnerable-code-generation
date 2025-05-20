//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, position = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (bufsize == position) {
            bufsize += 16;
            tokens = realloc(tokens, bufsize * sizeof(char *));
        }

        token = strtok(str, DELIM);
        tokens[position++] = token;
    }

    tokens[position] = NULL;
    return tokens;
}

int launch_shell(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Romeo: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_string(input);

    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            return 1;
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(void) {
    int status;

    while (1) {
        system("clear");
        printf("Juliet: ");
        launch_shell();
    }

    return 0;
}