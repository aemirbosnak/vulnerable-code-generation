//Falcon-180B DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100

typedef struct {
    char **arguments;
    int num_arguments;
} Command;

void execute_command(Command *command) {
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error forking process: %s\n", strerror(errno));
        exit(1);
    } else if (pid == 0) {
        if (execvp(command->arguments[0], command->arguments) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

void handle_signal(int signal_number) {
    switch (signal_number) {
        case SIGINT:
            fprintf(stdout, "Interrupted by user.\n");
            exit(1);
        case SIGTERM:
            fprintf(stdout, "Terminated.\n");
            exit(1);
        default:
            fprintf(stdout, "Received signal %d.\n", signal_number);
    }
}

int main() {
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    char input_buffer[MAX_COMMAND_LENGTH];
    Command command;

    while (1) {
        fprintf(stdout, "> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        if (strlen(input_buffer) == 0) {
            continue;
        }

        command.num_arguments = 0;
        char *token = strtok(input_buffer, " ");
        while (token!= NULL) {
            command.arguments[command.num_arguments] = token;
            command.num_arguments++;

            if (command.num_arguments >= MAX_ARGUMENTS) {
                fprintf(stderr, "Error: Too many arguments.\n");
                exit(1);
            }

            token = strtok(NULL, " ");
        }

        execute_command(&command);
    }

    return 0;
}