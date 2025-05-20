//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LINE_LENGTH 1024
#define MAX_ARGUMENTS 50

char **split_command_line(char *line);
int execute_command(char **args);
void handle_signal(int signal);

int main() {
    char input[MAX_COMMAND_LINE_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LINE_LENGTH, stdin);

        args = split_command_line(input);
        if (args[0] == NULL) {
            continue;
        }

        pid = fork();
        if (pid == -1) {
            printf("Error forking\n");
            exit(1);
        } else if (pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            wait(NULL);
        }
    }

    return 0;
}

char **split_command_line(char *line) {
    char *token;
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argc = 0;

    token = strtok(line, " ");
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        args[argc] = token;
        argc++;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        printf("Error forking\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error executing command\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signal) {
    printf("\nInterrupted by signal %d\n", signal);
}