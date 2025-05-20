//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LINE_LENGTH 1024

typedef struct {
    char **args;
    int num_args;
} Command;

char **split_command_line(char *line) {
    char **args = malloc(sizeof(char *) * (strlen(line) + 1));
    int num_args = 0;
    char *token = strtok(line, " ");

    while (token!= NULL) {
        args[num_args] = token;
        num_args++;
        token = strtok(NULL, " ");
    }

    args[num_args] = NULL;
    return args;
}

void execute_command(Command *command) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Failed to fork\n");
        exit(1);
    } else if (pid == 0) {
        execvp(command->args[0], command->args);
        printf("Failed to execute command\n");
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
    }
}

void parse_command(char *line, Command *command) {
    char **args = split_command_line(line);
    command->args = args;
    command->num_args = strlen(line);
}

void run_shell() {
    char input[MAX_COMMAND_LINE_LENGTH];
    Command command;

    printf("Welcome to the Unix-like Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LINE_LENGTH, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        } else {
            parse_command(input, &command);
            execute_command(&command);
        }
    }
}

int main() {
    run_shell();
    return 0;
}