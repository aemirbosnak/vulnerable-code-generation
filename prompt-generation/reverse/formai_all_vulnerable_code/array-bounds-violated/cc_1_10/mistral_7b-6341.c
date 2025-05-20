//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_COMMANDS 50
#define MAX_NUM_ARGS 256

typedef struct Command {
    char args[MAX_NUM_ARGS][MAX_INPUT_SIZE];
    int num_args;
    pid_t pid;
    int status;
} Command;

Command commands[MAX_NUM_COMMANDS];
int num_commands = 0;

void sigint_handler(int sig) {
    for (int i = 0; i < num_commands; i++) {
        if (commands[i].pid > 0) {
            kill(commands[i].pid, SIGTERM);
            waitpid(commands[i].pid, &commands[i].status, 0);
        }
    }
    exit(0);
}

void print_prompt() {
    printf("%s%3d%s> ", "Calm Shell", num_commands + 1);
}

void execute_command(char *command) {
    char *args[MAX_NUM_ARGS];
    char *token;
    int num_args = 0;

    token = strtok(command, " ");
    while (token != NULL) {
        args[num_args] = token;
        num_args++;

        token = strtok(NULL, " ");
    }

    Command new_command;
    new_command.num_args = num_args;

    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) < 0) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid > 0) {
        new_command.pid = pid;
        commands[num_commands++] = new_command;
    } else {
        perror("Error forking process");
        exit(1);
    }
}

int main() {
    signal(SIGINT, sigint_handler);

    while (1) {
        print_prompt();
        char command[MAX_INPUT_SIZE];
        fgets(command, MAX_INPUT_SIZE, stdin);

        command[strlen(command) - 1] = '\0';
        execute_command(command);
    }

    return 0;
}