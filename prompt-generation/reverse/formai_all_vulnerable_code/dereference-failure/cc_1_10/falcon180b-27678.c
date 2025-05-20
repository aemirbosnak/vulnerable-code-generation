//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50

char **arguments;
int argument_count;

void sigint_handler(int signal) {
    printf("\nInterrupted by user.\n");
    exit(0);
}

int main() {
    signal(SIGINT, sigint_handler);

    printf("Welcome to the Peaceful Shell!\n");
    printf("Type 'help' for a list of commands.\n");

    while (1) {
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *command = strtok(input, " ");
        if (command == NULL) {
            continue;
        }

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("- exit\n");
            printf("- help\n");
        } else {
            argument_count = 0;
            arguments = malloc(MAX_ARGUMENTS * sizeof(char*));

            char *token = strtok(NULL, " ");
            while (token!= NULL && argument_count < MAX_ARGUMENTS) {
                arguments[argument_count++] = token;
                token = strtok(NULL, " ");
            }

            pid_t child_pid = fork();

            if (child_pid == 0) {
                execvp(command, arguments);
            } else {
                wait(NULL);
            }
        }
    }

    return 0;
}