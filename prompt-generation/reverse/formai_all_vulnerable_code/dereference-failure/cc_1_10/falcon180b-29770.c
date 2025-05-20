//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork();
void execute_command(char **arguments);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Unix-like Shell\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **arguments = split_command(input);
        execute_command(arguments);
    }
    return 0;
}

char **split_command(char *command) {
    char *token = strtok(command, DELIM);
    int count = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    while (token!= NULL && count < MAX_ARGUMENTS) {
        arguments[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    arguments[count] = NULL;
    return arguments;
}

pid_t fork() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

void execute_command(char **arguments) {
    pid_t pid = fork();
    if (pid == 0) {
        if (arguments[0] == NULL) {
            printf("Command not found\n");
            exit(1);
        }
        execvp(arguments[0], arguments);
        perror("execvp");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            printf("\nInterrupted by user\n");
            break;
        case SIGQUIT:
            printf("\nQuit by user\n");
            break;
        default:
            printf("\nUnknown signal\n");
    }
}