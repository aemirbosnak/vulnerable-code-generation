//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_COMMANDS 64
#define MAX_TOKEN_SIZE 64

typedef struct Command {
    char **args;
    int background;
} Command;

void parse_command(char *line, Command *cmd) {
    char *token, *save_ptr;
    int i = 0;

    cmd->background = 0;
    cmd->args = malloc(MAX_NUM_COMMANDS * sizeof(char *));

    token = strtok_r(line, " \t", &save_ptr);
    while (token != NULL) {
        cmd->args[i] = strdup(token);
        i++;

        if (i >= MAX_NUM_COMMANDS) {
            fprintf(stderr, "Error: too many commands in a line\n");
            break;
        }

        token = strtok_r(NULL, " \t", &save_ptr);
    }

    cmd->args[i] = NULL;
}

void execute_command(Command *cmd) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) { // Child process
        if (cmd->background) {
            setsid();
            // Redirect input, output and error to /dev/null
            // to run the command in the background
            // ...
        }

        // Change current directory to the home directory
        // of the current user before executing the command
        // ...

        if (execvp(cmd->args[0], cmd->args) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid > 0) { // Parent process
        if (!cmd->background) {
            waitpid(pid, &status, 0);
        }
    } else { // Error
        perror("Error forking process");
        exit(1);
    }
}

int main() {
    char line[MAX_INPUT_SIZE];
    Command cmd;

    while (1) {
        printf(">% ", getlogin());
        bzero(line, MAX_INPUT_SIZE);
        fgets(line, MAX_INPUT_SIZE, stdin);

        // Remove the newline character from the input
        line[strlen(line) - 1] = '\0';

        parse_command(line, &cmd);

        if (strcmp(cmd.args[0], "exit") == 0) {
            break;
        }

        cmd.background = (strcmp(cmd.args[0], "&") == 0) ? 1 : 0;
        execute_command(&cmd);

        free(cmd.args);
    }

    return 0;
}