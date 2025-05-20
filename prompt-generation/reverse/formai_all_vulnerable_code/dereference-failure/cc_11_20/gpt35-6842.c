//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 50
#define MAX_ARGS 10
#define BUFFER_SIZE 1024

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* commands[MAX_COMMANDS];
    char* args[MAX_ARGS];
    char buffer[BUFFER_SIZE];

    while (1) {
        printf("$ ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // remove newline character

        char* token = strtok(buffer, " ");
        int num_commands = 0;

        // break input into commands
        while (token != NULL) {
            commands[num_commands] = token;
            num_commands++;
            token = strtok(NULL, " ");
        }
        commands[num_commands] = NULL;

        if (num_commands == 0) {
            continue;
        }

        // check for exit command
        if (strcmp(commands[0], "exit") == 0) {
            break;
        }

        int fd[2];
        int i;
        pid_t pid;
        int status;

        for (i = 0; i < num_commands; i++) {
            char* arg = commands[i];
            args[0] = arg;
            int num_args = 1;

            // break command into arguments
            while (strcmp(arg, "|") != 0 && arg != NULL) {
                arg = commands[++i];
                args[num_args++] = arg;
            }
            args[num_args - 1] = NULL;

            pipe(fd);

            // fork child process
            if ((pid = fork()) < 0) {
                perror("fork error");
                exit(1);
            } else if (pid == 0) {
                // child process

                if (i < num_commands - 1) {  // if not last command
                    close(fd[0]);  // close read end of pipe
                    dup2(fd[1], STDOUT_FILENO);  // redirect output to pipe
                }

                close(fd[1]);  // close write end of pipe

                execvp(args[0], args);
                perror("execvp error");
                exit(1);
            }

            // parent process

            if (i < num_commands - 1) {  // if not last command
                close(fd[1]);  // close write end of pipe
                dup2(fd[0], STDIN_FILENO);  // redirect input to pipe
            }

            close(fd[0]);  // close read end of pipe

            // wait for child process to finish
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}