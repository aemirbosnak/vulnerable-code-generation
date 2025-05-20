//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 80
#define MAX_NUM_COMMANDS 10
#define DELIM " "

int num_commands = 0;
char **commands;

void execute_command(char *command) {
    pid_t pid = fork();

    if (pid == 0) {
        system(command);
        exit(0);
    } else {
        waitpid(pid, NULL, 0);
    }
}

void add_command(char *command) {
    if (num_commands >= MAX_NUM_COMMANDS) {
        fprintf(stderr, "Error: Too many commands.\n");
        return;
    }

    commands[num_commands] = strdup(command);
    num_commands++;
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    commands = (char **)malloc(MAX_NUM_COMMANDS * sizeof(char *));

    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *token = strtok(input, DELIM);
        while (token!= NULL) {
            add_command(token);
            token = strtok(NULL, DELIM);
        }
    }

    return 0;
}