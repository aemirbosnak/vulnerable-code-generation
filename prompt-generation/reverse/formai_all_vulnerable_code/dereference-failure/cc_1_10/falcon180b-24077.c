//Falcon-180B DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_COMMANDS 50

typedef struct command_t {
    char* command;
    int fd[2];
    pid_t pid;
} command_t;

int main() {
    int num_commands = 0;
    command_t commands[MAX_NUM_COMMANDS];

    while (num_commands < MAX_NUM_COMMANDS) {
        printf("Enter a command (or type 'exit' to finish): ");
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        commands[num_commands].command = strdup(input);
        pipe(commands[num_commands].fd);

        pid_t pid = fork();

        if (pid == 0) {
            close(commands[num_commands].fd[0]);
            dup2(commands[num_commands].fd[1], STDOUT_FILENO);
            close(commands[num_commands].fd[1]);

            execlp("/bin/sh", "sh", "-c", commands[num_commands].command, NULL);
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            close(commands[num_commands].fd[1]);
            commands[num_commands].pid = pid;
            num_commands++;
        } else {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < num_commands; i++) {
        waitpid(commands[i].pid, NULL, 0);
        close(commands[i].fd[0]);
    }

    return 0;
}