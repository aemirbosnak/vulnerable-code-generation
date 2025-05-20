//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork();
int execute_command(char **arguments);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;

    printf("Unix-like Shell\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        arguments = split_command(input);

        if (arguments[0] == NULL)
            continue;

        pid = fork();

        if (pid == 0) {
            execute_command(arguments);
            exit(0);
        } else if (pid < 0) {
            printf("Error forking\n");
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        arguments[argc] = token;
        argc++;
        if (argc >= MAX_ARGUMENTS) {
            printf("Too many arguments\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

pid_t fork() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        printf("Error forking\n");
        exit(1);
    }

    return pid;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL)
        return 1;

    pid = fork();

    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            printf("Error executing command\n");
            exit(1);
        }
    } else if (pid < 0) {
        printf("Error forking\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            printf("\nInterrupted\n");
            break;
        case SIGQUIT:
            printf("\nQuit\n");
            break;
        case SIGTERM:
            printf("\nTerminated\n");
            break;
        default:
            printf("Received signal %d\n", signum);
            break;
    }
}