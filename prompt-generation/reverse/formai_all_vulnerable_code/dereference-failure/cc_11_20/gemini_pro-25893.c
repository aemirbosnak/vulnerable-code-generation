//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 10

int main(void) {
    char *args[MAX_ARGS];
    char line[1024];
    int status;

    while (1) {
        printf("$ ");
        fgets(line, sizeof(line), stdin);

        if (feof(stdin)) {
            printf("\n");
            exit(0);
        }

        // Parse the line into arguments
        int i = 0;
        char *token = strtok(line, " \n");
        while (token != NULL && i < MAX_ARGS) {
            args[i++] = token;
            token = strtok(NULL, " \n");
        }

        // Handle built-in commands
        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                printf("cd: no argument\n");
            } else {
                if (chdir(args[1]) != 0) {
                    perror("cd");
                }
            }
        } else if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else {
            // Fork a child process to execute the command
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                execvp(args[0], args);
                perror(args[0]);
                exit(1);
            } else if (pid > 0) {
                // Parent process
                wait(&status);
            } else {
                perror("fork");
            }
        }
    }

    return 0;
}