//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMANDS 100
#define TOKEN_SIZE 100

char *commands[MAX_COMMANDS];
int num_commands = 0;

void add_command(char *command) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Too many commands.\n");
        exit(1);
    }

    commands[num_commands++] = strdup(command);
}

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        printf("Error: Failed to fork.\n");
        exit(1);
    } else if (pid == 0) {
        char *argv[2];
        argv[0] = strdup("/bin/sh");
        argv[1] = strdup("-c");
        argv[2] = strdup(command);
        argv[3] = NULL;

        execvp("/bin/sh", argv);
        perror("execvp");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

void loop() {
    char input[TOKEN_SIZE];
    char token[TOKEN_SIZE];
    char *command;

    printf("> ");
    fgets(input, TOKEN_SIZE, stdin);

    command = strtok(input, "\n");
    while (command!= NULL) {
        add_command(command);
        command = strtok(NULL, "\n");
    }

    for (int i = 0; i < num_commands; i++) {
        execute_command(commands[i]);
    }
}

void signal_handler(int signal) {
    if (signal == SIGINT) {
        printf("\n");
    }
}

int main() {
    signal(SIGINT, signal_handler);

    loop();

    return 0;
}