//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split(char *line) {
    int count = 0;
    char *token = strtok(line, DELIM);
    char **tokens = malloc(MAX_LINE * sizeof(char*));
    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;
    return tokens;
}

int main_loop(char **args) {
    pid_t pid;
    int status;
    if (args[0] == NULL) {
        return 1;
    }
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "%s: Command not found\n", args[0]);
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }
    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_LINE];
    char **args;
    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);
        args = split(input);
        main_loop(args);
    }
    return 0;
}