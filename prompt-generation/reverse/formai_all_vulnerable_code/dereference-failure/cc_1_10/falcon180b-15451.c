//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            printf("Error: Too many arguments\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;
    return argv;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        char **args = split_command(input);
        pid_t pid = fork();

        if (pid == -1) {
            printf("Error: Fork failed\n");
            exit(1);
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                printf("Error: Command not found\n");
                exit(1);
            }
        } else {
            wait(NULL);
        }
    }
    return 0;
}