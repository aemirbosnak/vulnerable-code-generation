//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

typedef struct {
    char *command;
    char **arguments;
    int background;
} Command;

void execute_command(Command *command) {
    pid_t pid;
    int status;

    if (command->background) {
        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Error: Failed to fork process.\n");
            return;
        } else if (pid == 0) {
            execlp(command->command, command->command, NULL);
            fprintf(stderr, "Error: Failed to execute command.\n");
            exit(1);
        }
    } else {
        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Error: Failed to fork process.\n");
            return;
        } else if (pid == 0) {
            execlp(command->command, command->command, NULL);
            fprintf(stderr, "Error: Failed to execute command.\n");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    Command command;
    int argc;
    char **argv;

    srand(time(NULL));

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        argc = 0;
        argv = malloc(MAX_ARGUMENTS * sizeof(char *));

        char *token = strtok(input, " ");
        while (token!= NULL) {
            argv[argc++] = token;
            token = strtok(NULL, " ");

            if (argc >= MAX_ARGUMENTS) {
                fprintf(stderr, "Error: Too many arguments.\n");
                exit(1);
            }
        }
        argv[argc] = NULL;

        command.command = argv[0];
        command.arguments = argv;
        command.background = 0;

        execute_command(&command);

        free(argv);
    }

    return 0;
}