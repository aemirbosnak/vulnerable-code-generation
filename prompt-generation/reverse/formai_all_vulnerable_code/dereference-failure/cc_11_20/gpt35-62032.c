//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    char line[BUFFER_SIZE];
    while (1) {
        // Print a prompt
        printf("> ");
        fflush(stdout);

        // Read a line of input
        if (!fgets(line, BUFFER_SIZE, stdin)) {
            break;
        }

        // Remove trailing newline
        line[strcspn(line, "\n")] = '\0';

        // Parse the command and arguments
        char *args[100];
        char *token;
        char *rest = line;
        int i = 0;
        while ((token = strtok_r(rest, " ", &rest))) {
            args[i++] = token;
        }
        args[i] = NULL;

        // Handle empty command line
        if (!args[0]) {
            continue;
        }

        // Implement built-in commands
        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (args[1]) {
                if (chdir(args[1]) != 0) {
                    perror("cd");
                }
            } else {
                chdir(getenv("HOME"));
            }
            continue;
        }

        // Fork a new process to execute the command
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("exec");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                printf("[PID %d] Exited with status %d\n", pid, WEXITSTATUS(status));
            } else {
                printf("[PID %d] Terminated abnormally\n", pid);
            }
        }
    }
    return 0;
}