//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 512
#define MAX_LINE 2048

int main() {
    char line[MAX_LINE];
    char *args[MAX_ARGS];
    int argc;
    int status;

    while (1) {
        printf("$ ");
        fgets(line, MAX_LINE, stdin);

        // Parse the line into arguments
        argc = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            args[argc++] = token;
            token = strtok(NULL, " ");
        }

        // Check for built-in commands
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            if (argc < 2) {
                fprintf(stderr, "cd: Missing argument\n");
                continue;
            }
            if (chdir(args[1]) != 0) {
                perror("cd");
            }
            continue;
        }

        // Fork a child process
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        }

        // Child process
        if (pid == 0) {
            // Replace the child's memory space with the new program
            execvp(args[0], args);

            // If execvp fails, print an error message and exit
            perror(args[0]);
            exit(1);
        }

        // Parent process
        else {
            // Wait for the child process to complete
            waitpid(pid, &status, 0);

            // Check the child's exit status
            if (WIFEXITED(status)) {
                printf("Child exited with status %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("Child terminated by signal %d\n", WTERMSIG(status));
            }
        }
    }

    return 0;
}