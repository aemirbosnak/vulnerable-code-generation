//Falcon-180B DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10

typedef struct {
    char **args;
    int num_args;
    char input[MAX_COMMAND_LENGTH];
} Command;

int launch_shell() {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        execlp("sh", "sh", NULL);
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return 0;
    }
}

int execute_command(Command *command) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        int i;
        for (i = 0; i < command->num_args; i++) {
            dup2(command->args[i], i);
        }
        dup2(0, command->num_args);
        close(command->args[command->num_args]);
        execlp(command->args[0], command->args[0], NULL);
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return 0;
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    Command command;
    command.num_args = 0;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        char *token = strtok(input, " ");
        while (token!= NULL) {
            if (command.num_args >= MAX_ARGS) {
                printf("Too many arguments\n");
                break;
            }
            command.args[command.num_args] = token;
            command.num_args++;
            token = strtok(NULL, " ");
        }

        if (command.num_args == 0) {
            continue;
        }

        execute_command(&command);
        memset(&command, 0, sizeof(command));
    }

    return 0;
}