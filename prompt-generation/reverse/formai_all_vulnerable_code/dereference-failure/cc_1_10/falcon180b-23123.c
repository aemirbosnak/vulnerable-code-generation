//Falcon-180B DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10
#define BUFFER_SIZE 1024

char **args = NULL;

void execute_command(char *command) {
    int i = 0;
    char **tokens = NULL;
    pid_t pid = 0;
    int status = 0;

    tokens = malloc(MAX_ARGS * sizeof(char*));
    if (tokens == NULL) {
        printf("Error: Out of memory\n");
        return;
    }

    tokens[0] = strdup(command);
    i++;

    while ((command = strtok(NULL, " "))!= NULL) {
        if (i >= MAX_ARGS) {
            printf("Error: Too many arguments\n");
            free(tokens[0]);
            free(tokens);
            return;
        }

        tokens[i] = strdup(command);
        i++;
    }

    pid = fork();

    if (pid == 0) {
        execvp(tokens[0], tokens);
        perror("Error");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    for (i = 0; tokens[i]!= NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

void signal_handler(int signal) {
    switch (signal) {
        case SIGINT:
        case SIGTERM:
            printf("\nExiting...\n");
            exit(0);
        default:
            break;
    }
}

int main() {
    char input_buffer[BUFFER_SIZE];
    char *command = NULL;
    size_t command_length = 0;

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    while (1) {
        memset(input_buffer, 0, BUFFER_SIZE);

        printf("> ");
        fgets(input_buffer, BUFFER_SIZE, stdin);

        command_length = strlen(input_buffer);

        if (command_length == 1 && input_buffer[0] == '\n') {
            continue;
        }

        command = malloc(command_length + 1);
        if (command == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }

        strncpy(command, input_buffer, command_length);
        command[command_length] = '\0';

        execute_command(command);
    }

    return 0;
}