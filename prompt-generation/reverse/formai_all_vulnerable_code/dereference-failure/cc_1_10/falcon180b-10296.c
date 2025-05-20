//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));

    char *token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[count++] = token;
        if (count >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;
    return tokens;
}

int launch_shell(char **args) {
    pid_t pid;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: no command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        // parent process
        int status;
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args = NULL;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        launch_shell(args);

        free(args);
    }

    return 0;
}