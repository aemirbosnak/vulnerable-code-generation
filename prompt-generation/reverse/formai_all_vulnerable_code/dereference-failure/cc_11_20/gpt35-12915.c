//FormAI DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_COMMANDS 3
#define BUFFER_SIZE 1024

int main(void)
{
    char *commands[NUM_COMMANDS] = {"ls", "echo hello world", "pwd"};
    int num_pipes = NUM_COMMANDS - 1;
    int pipefd[2*num_pipes];
    pid_t pid;
    int status;
    int i;

    /* setup pipes */
    for (i = 0; i < num_pipes; i++) {
        if (pipe(pipefd + i*2) < 0) {
            perror("pipe");
            exit(1);
        }
    }

    /* execute commands */
    for (i = 0; i < NUM_COMMANDS; i++) {
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            /* if not last command */
            if (i < NUM_COMMANDS - 1) {
                if (dup2(pipefd[i*2+1], STDOUT_FILENO) < 0) {
                    perror("dup2");
                    exit(1);
                }
            }

            /* if not first command */
            if (i > 0) {
                if (dup2(pipefd[(i-1)*2], STDIN_FILENO) < 0) {
                    perror("dup2");
                    exit(1);
                }
            }

            /* close all pipes */
            for (int j = 0; j < 2*num_pipes; j++) {
                close(pipefd[j]);
            }

            /* execute command */
            char *command = commands[i];
            char *args[32];
            int num_args = 0;
            char *token = strtok(command, " ");
            while (token != NULL) {
                args[num_args++] = token;
                token = strtok(NULL, " ");
            }
            args[num_args] = NULL;
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        }
    }

    /* close all pipes */
    for (i = 0; i < 2*num_pipes; i++) {
        close(pipefd[i]);
    }

    /* wait for children */
    for (i = 0; i < NUM_COMMANDS; i++) {
        wait(&status);
    }

    return 0;
}