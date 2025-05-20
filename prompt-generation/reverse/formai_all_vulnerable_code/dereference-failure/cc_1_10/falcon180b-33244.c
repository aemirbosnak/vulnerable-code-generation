//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str);
void execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input_buffer);

        if (args[0] == NULL) {
            continue;
        }

        pid = fork();

        if (pid == -1) {
            printf("Error forking process\n");
            continue;
        } else if (pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *str) {
    int argc = 0;
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token;

    token = strtok(str, DELIM);

    while (token!= NULL) {
        args[argc] = token;
        argc++;

        if (argc >= MAX_ARGUMENTS) {
            printf("Too many arguments\n");
            exit(1);
        }

        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;

    return args;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return;
    }

    pid = fork();

    if (pid == -1) {
        printf("Error forking process\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error executing command\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\nInterrupted\n");
    }
}