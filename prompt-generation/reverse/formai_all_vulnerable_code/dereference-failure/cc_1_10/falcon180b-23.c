//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
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
pid_t fork(void);
int execute_command(char **arguments);
void handle_signal(int signal);

int main(void) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t child_pid;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    printf("Enter commands, type 'exit' to quit:\n");

    while (fgets(input_buffer, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        if (strcmp(input_buffer, "exit\n") == 0) {
            break;
        }

        arguments = split_string(input_buffer, DELIM);
        child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
        } else if (child_pid > 0) {
            waitpid(child_pid, NULL, 0);
        } else {
            execute_command(arguments);
            exit(0);
        }
    }

    return 0;
}

char **split_string(char *string, char delimiter) {
    char **tokens;
    int count = 0;
    char *token;

    tokens = malloc(sizeof(char *) * MAX_ARGUMENTS);

    token = strtok(string, delimiter);
    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, delimiter);
    }
    tokens[count] = NULL;

    return tokens;
}

pid_t fork(void) {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

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

    return 0;
}

void handle_signal(int signal) {
    switch (signal) {
        case SIGINT:
        case SIGQUIT:
        case SIGTERM:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            break;
    }
}