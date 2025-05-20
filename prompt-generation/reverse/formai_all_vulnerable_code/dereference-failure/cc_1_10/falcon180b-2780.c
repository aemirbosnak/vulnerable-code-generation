//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t launch_process(char **args);
void handle_signal(int signum);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("Welcome to the Basic Unix-like Shell!\n");
    printf("Enter commands followed by Enter.\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        memset(input, 0, MAX_COMMAND_LENGTH);
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        args = split_command(input);

        if (args[0] == NULL) {
            printf("Invalid command.\n");
            continue;
        }

        pid = launch_process(args);

        if (pid == -1) {
            printf("Failed to launch process.\n");
        }

        waitpid(pid, NULL, 0);
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = malloc(sizeof(char *) * MAX_COMMAND_LENGTH);
    char *token;

    token = strtok(command, DELIM);

    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;

    return args;
}

pid_t launch_process(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Failed to execute %s.\n", args[0]);
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        printf("Failed to fork.\n");
        return -1;
    } else {
        waitpid(pid, &status, 0);
    }

    return pid;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            printf("Interrupted by user.\n");
            exit(EXIT_FAILURE);
        case SIGTERM:
            printf("Terminated.\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Received unknown signal %d.\n", signum);
            exit(EXIT_FAILURE);
    }
}