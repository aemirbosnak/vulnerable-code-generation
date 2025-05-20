//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 100 // maximum number of commands that can be piped
#define MAX_COMMAND_LENGTH 50 // maximum length of each command
#define MAX_INPUT_LENGTH 500 // maximum input length

void execute_command(char* command, int in_fd, int out_fd) {
    int pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // child process
        if (in_fd != 0) {
            dup2(in_fd, 0);
            close(in_fd);
        }
        if (out_fd != 1) {
            dup2(out_fd, 1);
            close(out_fd);
        }
        char* args[MAX_COMMAND_LENGTH];
        int i = 0;
        char* token = strtok(command, " ");
        while (token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // parent process
        wait(NULL);
    }
}

void execute_commands(char** commands, int num_commands) {
    int pipes[MAX_COMMANDS][2];
    for (int i = 0; i < num_commands; i++) {
        if (i < num_commands - 1) {
            if (pipe(pipes[i]) < 0) {
                perror("pipe");
                exit(EXIT_FAILURE);
            }
        }
        int in_fd = i == 0 ? 0 : pipes[i-1][0];
        int out_fd = i == num_commands - 1 ? 1 : pipes[i][1];
        execute_command(commands[i], in_fd, out_fd);
        if (i < num_commands - 1) {
            close(pipes[i][1]);
        }
    }
    for (int i = 0; i < num_commands - 1; i++) {
        close(pipes[i][0]);
    }
}

int main() {
    while (1) {
        // read user input
        char input[MAX_INPUT_LENGTH];
        printf("sh> ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strlen(input) - 1] = '\0'; // remove newline character

        // split input into commands
        char* commands[MAX_COMMANDS];
        int num_commands = 0;
        char* token = strtok(input, "|");
        while (token != NULL) {
            commands[num_commands] = token;
            num_commands++;
            token = strtok(NULL, "|");
        }

        execute_commands(commands, num_commands);
    }
    return 0;
}