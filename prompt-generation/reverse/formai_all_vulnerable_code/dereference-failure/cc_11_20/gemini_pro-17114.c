//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

int main() {
    char line[MAX_LINE_LENGTH];
    char *args[MAX_ARGS];
    int num_args;
    pid_t pid;
    int status;

    while (1) {
        printf("curioshell$ ");
        fflush(stdout);

        // Read the user's input
        if (fgets(line, sizeof(line), stdin) == NULL) {
            perror("fgets");
            exit(1);
        }

        // Parse the user's input into arguments
        num_args = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            args[num_args++] = token;
            token = strtok(NULL, " ");
        }

        // Check for special commands
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            if (chdir(args[1]) == -1) {
                perror("chdir");
            }
        } else {
            // Fork a new process to execute the command
            pid = fork();
            if (pid == -1) {
                perror("fork");
                exit(1);
            } else if (pid == 0) {
                // Child process
                execvp(args[0], args);
                perror("execvp");
                exit(1);
            } else {
                // Parent process
                waitpid(pid, &status, 0);
                if (WIFEXITED(status)) {
                    printf("Exit status: %d\n", WEXITSTATUS(status));
                } else if (WIFSIGNALED(status)) {
                    printf("Terminated by signal: %d\n", WTERMSIG(status));
                }
            }
        }
    }

    return 0;
}