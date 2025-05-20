//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\n\r\a"

char **split_string(char *string) {
    int bufsize = 0, words = 0;
    char **tokens = NULL;
    char *token;
    char delim[2] = {DELIM[0], '\0'};

    token = strtok(string, delim);
    while (token!= NULL) {
        words++;
        bufsize += strlen(token) + 1;
        token = strtok(NULL, delim);
    }

    tokens = malloc((words + 1) * sizeof(char *));
    if (tokens == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }

    bufsize -= words;
    tokens[words] = NULL;
    token = strtok(string, delim);
    for (int i = 0; i < words; i++) {
        tokens[i] = malloc((token - string) + 1);
        if (tokens[i] == NULL) {
            fprintf(stderr, "Memory error\n");
            exit(1);
        }
        strncpy(tokens[i], string, token - string);
        tokens[i][token - string] = '\0';
        string = token + 1;
        token = strtok(NULL, delim);
    }

    return tokens;
}

int launch_shell() {
    char input[MAX_COMMAND_LENGTH];
    printf("mysh> ");
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