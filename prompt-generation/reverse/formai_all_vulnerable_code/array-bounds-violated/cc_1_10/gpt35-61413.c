//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_ARGS];
    pid_t pid;
    int status;

    while (1) {
        printf("shell> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }

        int i = 0;
        args[i] = strtok(command, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }
        args[i] = NULL;

        pid = fork();

        if (pid < 0) {
            perror("forking child process failed");
            exit(1);
        } else if (pid == 0) {
            // child process
            if (execvp(args[0], args) == -1) {
                perror("execvp failed");
                exit(1);
            }
        } else {
            // parent process
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return 0;
}