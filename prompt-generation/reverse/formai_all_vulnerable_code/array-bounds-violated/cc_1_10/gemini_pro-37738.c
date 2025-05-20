//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_ARGS 64
#define MAX_LINE_LENGTH 1024

char **parse_args(char *line) {
    char **args = malloc(sizeof(char *) * MAX_ARGS);
    char *arg = strtok(line, " ");
    int i = 0;
    while (arg != NULL && i < MAX_ARGS) {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

int main() {
    char line[MAX_LINE_LENGTH];
    char **args;
    int status;

    while (1) {
        printf("> ");
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            break;
        }
        line[strlen(line) - 1] = '\0';  // Remove newline character

        args = parse_args(line);

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (chdir(args[1]) != 0) {
                perror("cd");
            }
        } else {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                execvp(args[0], args);
                perror("execvp");
                exit(1);
            } else {
                // Parent process
                waitpid(pid, &status, 0);
                if (WIFEXITED(status)) {
                    printf("Child process exited with status %d\n", WEXITSTATUS(status));
                } else if (WIFSIGNALED(status)) {
                    printf("Child process terminated by signal %d\n", WTERMSIG(status));
                } else {
                    printf("Child process exited abnormally\n");
                }
            }
        }

        free(args);
    }

    return 0;
}