//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string, char delimiter);
void execute_command(char **arguments);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
            break;
        }

        arguments = split_string(input, DELIM);
        if (arguments[0] == NULL) {
            continue;
        }

        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            execute_command(arguments);
            exit(0);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *string, char delimiter) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(string, delimiter);

    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, delimiter);
    }
    tokens[count] = NULL;

    return tokens;
}

void execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\nExiting...\n");
        exit(0);
    }
}