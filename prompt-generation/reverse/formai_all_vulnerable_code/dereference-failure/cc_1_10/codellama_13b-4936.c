//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
/*
 * A simple Unix-like shell program in C
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE 80

int main(int argc, char **argv) {
    char line[MAX_LINE];
    char *args[MAX_ARGS];
    int arg_count;

    while (1) {
        printf("$ ");
        fgets(line, MAX_LINE, stdin);

        // Parse the input line into arguments
        arg_count = parse_line(line, args);

        // Check if the user wants to exit
        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        // Fork a child process
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(1);
            }
        } else if (pid < 0) {
            // Error forking the child process
            perror("fork");
            exit(1);
        } else {
            // Parent process
            wait(NULL);
        }
    }

    return 0;
}

int parse_line(char *line, char **args) {
    int arg_count = 0;
    char *token;

    token = strtok(line, " ");

    while (token != NULL) {
        args[arg_count] = token;
        arg_count++;

        if (arg_count >= MAX_ARGS) {
            break;
        }

        token = strtok(NULL, " ");
    }

    return arg_count;
}