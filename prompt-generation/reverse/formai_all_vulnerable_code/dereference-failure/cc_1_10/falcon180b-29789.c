//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMANDS 100
#define BUFFER_SIZE 1024

char **commands = NULL;
int num_commands = 0;

void execute_command(char **command) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(command[0], command) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

void read_input() {
    char input[BUFFER_SIZE];
    while (fgets(input, BUFFER_SIZE, stdin)!= NULL) {
        char *token = strtok(input, " ");
        char **new_commands = realloc(commands, sizeof(char *) * (num_commands + 1));

        if (new_commands == NULL) {
            perror("realloc");
            exit(1);
        }

        commands = new_commands;
        commands[num_commands] = malloc(strlen(token) + 1);

        if (commands[num_commands] == NULL) {
            perror("malloc");
            exit(1);
        }

        strcpy(commands[num_commands], token);
        num_commands++;
    }
}

void execute_commands() {
    for (int i = 0; i < num_commands; i++) {
        execute_command(commands[i]);
    }
}

int main() {
    commands = malloc(sizeof(char *) * MAX_COMMANDS);

    if (commands == NULL) {
        perror("malloc");
        exit(1);
    }

    num_commands = 0;

    while (1) {
        read_input();

        if (strcmp(commands[num_commands - 1], "exit") == 0) {
            break;
        }
    }

    execute_commands();

    free(commands);
    return 0;
}