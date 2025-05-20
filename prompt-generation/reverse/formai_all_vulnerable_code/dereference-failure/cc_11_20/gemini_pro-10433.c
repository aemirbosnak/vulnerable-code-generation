//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    int argc;
    int status;
    pid_t pid;

    while (1) {
        printf("osh> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Parse the command into arguments.
        argc = 0;
        char *token = strtok(command, " ");
        while (token != NULL && argc < MAX_ARGS) {
            args[argc++] = token;
            token = strtok(NULL, " ");
        }
        args[argc] = NULL;

        // Check for built-in commands.
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            if (argc < 2) {
                printf("cd: missing operand\n");
            } else {
                if (chdir(args[1]) != 0) {
                    printf("cd: %s: No such directory\n", args[1]);
                }
            }
            continue;
        }

        // Fork a new process to execute the command.
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // Child process.
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            // Parent process.
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                printf("osh: exit status: %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("osh: killed by signal %d\n", WTERMSIG(status));
            }
        }
    }

    return 0;
}