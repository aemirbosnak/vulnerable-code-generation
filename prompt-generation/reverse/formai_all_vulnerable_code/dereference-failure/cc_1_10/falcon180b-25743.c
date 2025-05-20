//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line);
pid_t launch_shell(char **args);
void loop(void);

int main(void) {
    char input[MAX_LINE];
    char *args[MAX_ARGS];
    pid_t pid;

    printf("Post-Apocalyptic Shell\n");
    printf("Type 'exit' to quit\n");

    while (fgets(input, MAX_LINE, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0';

        args[0] = strtok(input, DELIM);

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        pid = launch_shell(args);
        if (pid == -1) {
            printf("Error launching shell\n");
        }
    }

    return 0;
}

char **split_line(char *line) {
    int argc = 0;
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

pid_t launch_shell(char **args) {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    return pid;
}

void loop(void) {
    int status;
    waitpid(-1, &status, WNOHANG);
}