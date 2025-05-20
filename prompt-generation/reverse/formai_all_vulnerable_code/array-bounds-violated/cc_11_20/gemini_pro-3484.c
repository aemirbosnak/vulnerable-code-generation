//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_ARGS 32
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    char *prompt = "myShell> ";
    char line[MAX_LINE_LENGTH];
    char *args[MAX_ARGS];
    int status;
    int bg_flag = 0;
    pid_t child_pid;

    while (1) {
        printf(prompt);
        fflush(stdout);

        // Read a line from the user.
        fgets(line, MAX_LINE_LENGTH, stdin);

        // Check for empty line.
        if (line[0] == '\n') continue;

        // Remove newline character from the end of the line.
        line[strlen(line) - 1] = '\0';

        // Parse the line into arguments.
        int arg_count = 0;
        args[arg_count++] = strtok(line, " ");
        while (args[arg_count - 1] != NULL) {
            args[arg_count++] = strtok(NULL, " ");
        }

        // Check for built-in commands.
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "cd: no argument provided\n");
            } else {
                if (chdir(args[1]) != 0) {
                    fprintf(stderr, "cd: %s: No such directory\n", args[1]);
                }
            }
        } else {
            // Fork a child process.
            child_pid = fork();
            if (child_pid == 0) {
                // Child process.
                execvp(args[0], args);
                fprintf(stderr, "%s: command not found\n", args[0]);
                exit(1);
            } else if (child_pid > 0) {
                // Parent process.
                if (bg_flag) {
                    printf("[%d] %s\n", child_pid, line);
                } else {
                    waitpid(child_pid, &status, 0);
                }
            } else {
                perror("fork");
                exit(1);
            }
        }
    }

    return 0;
}