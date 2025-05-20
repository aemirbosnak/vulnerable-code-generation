//GEMINI-pro DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    int status;
    char line[MAX_LINE_LENGTH];
    char *args[MAX_LINE_LENGTH];

    while (1) {
        printf("shell> ");
        fflush(stdout);

        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            break;
        }

        // Parse the line into arguments.
        int num_args = 0;
        args[num_args++] = strtok(line, " ");
        while ((args[num_args++] = strtok(NULL, " ")) != NULL) {
            ;
        }
        num_args--;

        // Check for built-in commands.
        if (strcmp(args[0], "exit") == 0) {
            break;
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
            // Fork a child process to execute the command.
            pid_t pid = fork();
            if (pid == 0) {
                // Child process.
                if (execvp(args[0], args) == -1) {
                    fprintf(stderr, "%s: command not found\n", args[0]);
                    exit(EXIT_FAILURE);
                }
            } else if (pid > 0) {
                // Parent process.
                waitpid(pid, &status, 0);
            } else {
                // Fork failed.
                fprintf(stderr, "fork: could not create child process\n");
            }
        }
    }

    return EXIT_SUCCESS;
}