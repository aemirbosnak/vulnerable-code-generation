//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 128
#define MAX_LINE_LENGTH 1024

char *args[MAX_ARGS];
char line[MAX_LINE_LENGTH];

int main() {
    while (1) {
        printf("myshell> ");
        fgets(line, MAX_LINE_LENGTH, stdin);
        line[strlen(line) - 1] = '\0';  // remove newline character

        // parse the line into arguments
        int num_args = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            args[num_args++] = token;
            token = strtok(NULL, " ");
        }
        args[num_args] = NULL;

        // check for built-in commands
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            if (num_args < 2) {
                fprintf(stderr, "cd: missing argument\n");
                continue;
            }
            if (chdir(args[1]) != 0) {
                fprintf(stderr, "cd: %s: no such directory\n", args[1]);
                continue;
            }
        } else {
            // fork and execute the command
            pid_t child_pid = fork();
            if (child_pid == 0) {
                // child process
                execvp(args[0], args);
                fprintf(stderr, "%s: command not found\n", args[0]);
                exit(1);
            } else {
                // parent process
                int status;
                waitpid(child_pid, &status, 0);
                if (WIFEXITED(status)) {
                    printf("exit status: %d\n", WEXITSTATUS(status));
                } else if (WIFSIGNALED(status)) {
                    printf("terminated by signal: %d\n", WTERMSIG(status));
                }
            }
        }
    }

    return 0;
}