//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **split_string(char *str);
int execute_command(char **args);
void handle_signal(int signum);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;
    int status;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    printf("Welcome to the Unix-like Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if (args[0] == NULL)
            continue;

        pid = fork();

        if (pid == -1) {
            printf("Error: Failed to fork.\n");
            continue;
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("Error");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split_string(char *str) {
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argc = 0;
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[argc] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return 1;

    pid = fork();

    if (pid == -1) {
        printf("Error: Failed to fork.\n");
        return 1;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("Error");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signum) {
    printf("\n");
    exit(0);
}