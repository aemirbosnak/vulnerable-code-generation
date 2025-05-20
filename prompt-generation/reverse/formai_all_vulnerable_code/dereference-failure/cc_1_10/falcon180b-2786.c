//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024

// Function to split a string into an array of strings
char **split_string(char *str, int *count) {
    char **tokens = malloc(sizeof(char*));
    int i = 0;
    char *token = strtok(str, " ");
    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    *count = i;
    return tokens;
}

// Function to execute a command
void execute_command(char **tokens) {
    pid_t pid;
    int status;
    if (tokens[0] == NULL) {
        return;
    }
    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1] == NULL) {
            fprintf(stderr, "Usage: cd <directory>\n");
        } else {
            if (chdir(tokens[1]) == -1) {
                perror("chdir");
            }
        }
    } else {
        pid = fork();
        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                perror("execvp");
            }
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

// Function to handle SIGINT signal
void handle_sigint(int signum) {
    fprintf(stdout, "\n");
}

// Main function
int main() {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;
    int count;
    signal(SIGINT, handle_sigint);
    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        tokens = split_string(input, &count);
        if (count == 0) {
            continue;
        }
        execute_command(tokens);
    }
    return 0;
}