//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

int main() {
    char line[MAX_LINE_LENGTH];
    char *args[MAX_ARGS];
    int num_args;
    int status;
    pid_t pid;

    while (1) {
        printf("calm$ ");
        fflush(stdout);

        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            break;
        }

        line[strlen(line) - 1] = '\0';  // Remove newline character

        num_args = parse_args(line, args);

        if (num_args == 0) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        pid = fork();

        if (pid < 0) {
            perror("fork");
            continue;
        }

        if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        }

        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process terminated abnormally\n");
        }
    }

    return 0;
}

int parse_args(char *line, char **args) {
    int num_args = 0;
    char *token;

    token = strtok(line, " ");
    while (token != NULL) {
        args[num_args++] = token;
        token = strtok(NULL, " ");
    }

    return num_args;
}