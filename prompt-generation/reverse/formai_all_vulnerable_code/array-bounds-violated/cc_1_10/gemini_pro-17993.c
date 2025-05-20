//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE_SIZE 1024
#define MAX_ARGS 64

void parse_args(char *line, char **args) {
    int i = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

int main(int argc, char *argv[]) {
    char line[MAX_LINE_SIZE];
    char *args[MAX_ARGS];

    while (1) {
        printf("mysh> ");
        fflush(stdout);
        if (fgets(line, MAX_LINE_SIZE, stdin) == NULL) {
            break;
        }
        line[strlen(line) - 1] = '\0';
        parse_args(line, args);
        if (strcmp(args[0], "exit") == 0) {
            break;
        }
        pid_t pid = fork();
        if (pid == 0) {
            if (execvp(args[0], args) < 0) {
                perror("execvp");
                exit(1);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                printf("Child process exited with status %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("Child process terminated by signal %d\n", WTERMSIG(status));
            }
        }
    }

    return 0;
}