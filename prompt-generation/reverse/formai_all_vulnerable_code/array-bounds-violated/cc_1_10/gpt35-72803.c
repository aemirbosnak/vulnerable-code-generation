//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG 64

int main() {
    char cmd[MAX_CMD_LEN], *args[MAX_ARG];
    int i, should_run = 1;

    while (should_run) {
        // prompt user for a command
        printf("myshell> ");
        fflush(stdout);

        // read user input
        fgets(cmd, MAX_CMD_LEN, stdin);

        // remove trailing newline character from user input
        if (cmd[strlen(cmd) - 1] == '\n') {
            cmd[strlen(cmd) - 1] = '\0';
        }

        // tokenize user input into arguments
        char *token = strtok(cmd, " ");
        for (i = 0; token != NULL; i++) {
            args[i] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        // check for exit command
        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
            continue;
        }

        // fork a child process
        pid_t pid = fork();

        if (pid < 0) {
            printf("Failed to fork child process.\n");
            exit(1);
        } else if (pid == 0) {
            // child process

            // execute the command
            if (execvp(args[0], args) < 0) {
                printf("Failed to execute command.\n");
                exit(1);
            }

        } else {
            // parent process

            // wait for child process to finish
            wait(NULL);
        }

    }

    return 0;
}