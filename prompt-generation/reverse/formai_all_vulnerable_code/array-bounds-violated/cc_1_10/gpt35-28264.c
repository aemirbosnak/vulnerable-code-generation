//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024
#define MAX_ARGS 64

void execute_command(char* command) {
    char* argv[MAX_ARGS];
    char buffer[MAX_LENGTH];

    int argc = 0;
    int len = strlen(command);

    for (int i = 0; i < len; i++) {
        int j = 0;
        while (command[i] != ' ' && i < len) {
            buffer[j++] = command[i++];
        }
        buffer[j] = '\0';

        argv[argc] = malloc(strlen(buffer) + 1);
        strcpy(argv[argc], buffer);
        argc++;
    }

    int pid = fork();

    if (pid == 0) {
        // child process
        execvp(argv[0], argv);
        printf("Error: command not found.\n");
        exit(1);
    } else {
        // parent process
        int status;
        waitpid(pid, &status, 0);
    }

    for (int i = 0; i < argc; i++) {
        free(argv[i]);
    }
}

int main() {
    char command[MAX_LENGTH];

    while (1) {
        printf("$ ");
        fflush(stdout);

        if (fgets(command, MAX_LENGTH, stdin) == NULL) {
            // end of file, exit
            printf("\n");
            exit(0);
        }

        // remove trailing newline character
        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }

        execute_command(command);
    }

    return 0;
}