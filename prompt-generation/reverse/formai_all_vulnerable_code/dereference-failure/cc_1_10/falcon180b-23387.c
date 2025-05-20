//Falcon-180B DATASET v1.0 Category: System administration ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

typedef struct {
    char **args;
    int num_args;
} command_t;

void parse_command(char *input, command_t *command) {
    char *token;
    int i = 0;

    token = strtok(input, " ");
    while (token!= NULL) {
        command->args[i] = token;
        i++;

        if (i >= MAX_ARGUMENTS) {
            break;
        }

        token = strtok(NULL, " ");
    }

    command->num_args = i;
}

int launch_process(command_t *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to fork process.\n");
        return -1;
    } else if (pid == 0) {
        if (execvp(command->args[0], command->args) == -1) {
            fprintf(stderr, "Failed to execute command: %s\n", command->args[0]);
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char **argv) {
    command_t command;
    char input[MAX_COMMAND_LENGTH];
    int running = 1;

    while (running) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        parse_command(input, &command);

        launch_process(&command);
    }

    return 0;
}