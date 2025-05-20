//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int buf_size = strlen(str) + 1;
    char *buf = malloc(buf_size);
    strcpy(buf, str);
    char **tokens = malloc((MAX_COMMAND_LENGTH + 1) * sizeof(char*));
    int num_tokens = 0;
    char *token = strtok(buf, DELIM);
    while (token!= NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[num_tokens] = NULL;
    return tokens;
}

void execute_command(char **args) {
    pid_t pid;
    if (args[0] == NULL) {
        return;
    }
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\"\n");
        } else {
            if (chdir(args[1])!= 0) {
                perror("chdir");
            }
        }
    } else {
        pid = fork();
        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

void handle_sigint(int signum) {
    fprintf(stdout, "\nExiting...\n");
    exit(0);
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    signal(SIGINT, handle_sigint);
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);
        execute_command(args);
    }
    return 0;
}