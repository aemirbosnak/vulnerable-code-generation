//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_LINE 1024
#define MAX_PROCESSES 10
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int count = 0;
    char **tokens = malloc(MAX_PROCESSES * sizeof(char*));
    char *token = strtok(line, DELIM);

    while (token!= NULL && count < MAX_PROCESSES) {
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int launch_process(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_sigint(int signum) {
    fprintf(stdout, "\nInterrupted.\n");
    exit(1);
}

int main() {
    char input[MAX_LINE];
    char **tokens;
    int bg = 0;

    signal(SIGINT, handle_sigint);

    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_LINE, stdin);

        tokens = split_line(input);

        if (tokens[0] == NULL) {
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0) {
            break;
        } else if (strcmp(tokens[0], "bg") == 0) {
            bg = 1;
        } else {
            launch_process(tokens);
        }
    }

    return 0;
}