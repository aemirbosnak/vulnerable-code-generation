//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024

char **split_command(char *command) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(command, " ");

    while (token!= NULL) {
        argv[argc] = strdup(token);
        argc++;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;

    return argv;
}

void execute_command(char **argv) {
    pid_t pid;
    int status;

    if (strcmp(argv[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(argv[0], "cd") == 0) {
        if (chdir(argv[1])!= 0) {
            fprintf(stderr, "Error: Directory not found.\n");
        }
    } else {
        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Error: Fork failed.\n");
            exit(1);
        } else if (pid == 0) {
            if (execvp(argv[0], argv) == -1) {
                fprintf(stderr, "Error: Command not found.\n");
                exit(1);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        argv = split_command(input);
        execute_command(argv);
        free(argv);
    }

    return 0;
}