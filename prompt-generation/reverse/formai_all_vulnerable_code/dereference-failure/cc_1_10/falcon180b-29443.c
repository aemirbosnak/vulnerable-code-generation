//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (strchr(DELIM, *str)) {
            *str = '\0';
            token = strdup(str);
            bufsize += strlen(token) + 1;
            tokens = realloc(tokens, bufsize);
            tokens[i++] = token;
            str++;
        } else {
            str++;
        }
    }

    tokens[i] = NULL;
    return tokens;
}

int launch_shell(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Fork failed: %s\n", strerror(errno));
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        launch_shell(args);

        free(args[0]);
        free(args);
    }

    return 0;
}