//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
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

int launch_shell() {
    char input[MAX_COMMAND_LENGTH];
    printf("shell> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **args = split_string(input);
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error");
            exit(1);
        }
    } else if (pid < 0) {
        perror("Error");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    for (int i = 0; args[i]!= NULL; i++) {
        free(args[i]);
    }
    free(args);

    return 0;
}

int main() {
    while (1) {
        launch_shell();
    }

    return 0;
}