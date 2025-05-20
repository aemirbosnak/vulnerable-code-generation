//Falcon-180B DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

typedef struct {
    char **arguments;
    int argument_count;
} Command;

void execute_command(Command *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Failed to fork: %s\n", strerror(errno));
        return;
    } else if (pid == 0) {
        if (execvp(command->arguments[0], command->arguments) == -1) {
            fprintf(stderr, "Failed to execute command: %s\n", strerror(errno));
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void parse_command(char *input, Command *command) {
    char *token;
    int argument_count = 0;

    token = strtok(input, " ");
    while (token!= NULL && argument_count < MAX_ARGUMENTS) {
        command->arguments[argument_count] = token;
        argument_count++;
        token = strtok(NULL, " ");
    }
    command->argument_count = argument_count;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    Command command;

    printf("Enter a command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    parse_command(input, &command);
    execute_command(&command);

    return 0;
}