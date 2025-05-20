//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

char **arguments;
int argument_count;

void execute_command(char *command) {
    pid_t pid;
    int status;

    arguments = malloc(sizeof(char *) * (MAX_ARGUMENTS + 1));
    argument_count = 0;

    char *token = strtok(command, " ");
    while (token!= NULL) {
        arguments[argument_count++] = token;
        if (argument_count >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, " ");
    }
    arguments[argument_count] = NULL;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        execvp(arguments[0], arguments);
        perror("execvp");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_signal(int signal_number) {
    if (signal_number == SIGINT) {
        printf("\nInterrupted\n");
    }
}

int main() {
    signal(SIGINT, handle_signal);

    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *command = strtok(input, "\n");
        if (command == NULL) {
            continue;
        }

        execute_command(command);
    }

    return 0;
}