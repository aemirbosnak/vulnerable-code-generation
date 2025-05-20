//Falcon-180B DATASET v1.0 Category: System administration ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

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
        fprintf(stderr, "Error forking process\n");
        exit(1);
    } else if (pid == 0) {
        execvp(command->arguments[0], command->arguments);
        fprintf(stderr, "Error executing command\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

void parse_command(char *input, Command *command) {
    char *token;
    int i = 0;

    token = strtok(input, " ");
    while (token!= NULL) {
        if (i >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments\n");
            exit(1);
        }
        command->arguments[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    command->argument_count = i;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    Command command;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        parse_command(input, &command);
        execute_command(&command);
    }

    return 0;
}