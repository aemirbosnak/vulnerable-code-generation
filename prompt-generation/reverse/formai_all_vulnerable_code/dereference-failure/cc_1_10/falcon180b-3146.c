//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
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
int execute_command(char **arguments);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        arguments = split_command(input);

        if (arguments[0] == NULL) {
            continue;
        }

        switch (fork()) {
            case -1:
                perror("fork");
                exit(1);
            case 0:
                execute_command(arguments);
                exit(0);
            default:
                wait(NULL);
        }
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));

    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        arguments[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

pid_t fork() {
    return fork();
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signum) {
    if (signum == SIGINT || signum == SIGQUIT || signum == SIGTERM) {
        printf("\nExiting...\n");
        exit(0);
    }
}