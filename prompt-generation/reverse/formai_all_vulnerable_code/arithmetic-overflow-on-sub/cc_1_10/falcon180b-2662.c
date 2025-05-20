//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line);
int execute_command(char **args);

int main() {
    char input[MAX_LINE];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin))!= -1) {
        line[read - 1] = '\0';
        char **args = split_line(line);
        execute_command(args);
        free(line);
        line = NULL;
        len = 0;
    }

    return 0;
}

char **split_line(char *line) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        args = realloc(args, sizeof(char *) * ++argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}