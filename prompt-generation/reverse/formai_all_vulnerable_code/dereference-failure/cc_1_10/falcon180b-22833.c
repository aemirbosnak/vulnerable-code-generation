//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (strchr(DELIM, *str)) {
            *str = '\0';
            bufsize++;
        }
        str++;
    }

    tokens = malloc(sizeof(char *) * (bufsize + 1));

    str = strtok(str, DELIM);
    while (str!= NULL) {
        tokens[i] = strdup(str);
        str = strtok(NULL, DELIM);
        i++;
    }
    tokens[i] = NULL;

    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    return pid;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_string(input);

    pid = launch_shell(args);

    waitpid(pid, NULL, 0);

    return 0;
}