//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define DELIM " \t\r\n\a"

char **split_string(char *string, char delimiter) {
    int count = 0;
    char **tokens = malloc(sizeof(char *) * (MAX_ARGUMENTS + 1));
    char *token = strtok(string, delimiter);
    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, delimiter);
    }
    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;
    if (args[0] == NULL) {
        fprintf(stderr, "Error: Command not found.\n");
        return 1;
    }
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: Command not found.\n");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }
    return 0;
}

void signal_handler(int signal) {
    switch (signal) {
        case SIGINT:
            fprintf(stdout, "\nExiting...\n");
            exit(EXIT_SUCCESS);
        default:
            fprintf(stderr, "Error: Invalid signal.\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args = NULL;
    signal(SIGINT, signal_handler);
    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input, '\n');
        if (args[0] == NULL) {
            continue;
        }
        execute_command(args);
    }
    return 0;
}