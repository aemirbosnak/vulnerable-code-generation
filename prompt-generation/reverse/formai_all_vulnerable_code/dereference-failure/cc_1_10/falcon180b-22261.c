//Falcon-180B DATASET v1.0 Category: System administration ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10

typedef struct {
    char **args;
    int num_args;
} Command;

void parse_command(char *command, Command *parsed_command) {
    char *token = strtok(command, " ");
    int num_args = 0;

    while (token!= NULL) {
        if (num_args >= MAX_ARGS) {
            printf("Error: Too many arguments\n");
            exit(1);
        }

        parsed_command->args[num_args] = token;
        num_args++;

        token = strtok(NULL, " ");
    }

    parsed_command->num_args = num_args;
}

int execute_command(Command *command) {
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == -1) {
        printf("Error: Fork failed\n");
        return 1;
    } else if (child_pid == 0) {
        execvp(command->args[0], command->args);
        printf("Error: Execvp failed\n");
        return 1;
    } else {
        waitpid(child_pid, &status, 0);
        return status;
    }
}

int main(int argc, char **argv) {
    char input_buffer[MAX_COMMAND_LENGTH];
    Command command;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        parse_command(input_buffer, &command);
        execute_command(&command);
    }

    return 0;
}