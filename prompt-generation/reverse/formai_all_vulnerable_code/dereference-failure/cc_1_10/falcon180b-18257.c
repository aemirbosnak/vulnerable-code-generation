//Falcon-180B DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMANDS 100
#define BUFFER_SIZE 1024

typedef struct {
    char *command;
    pid_t pid;
    int status;
    int exit_code;
} command_t;

int main() {
    int num_commands = 0;
    command_t commands[MAX_COMMANDS];
    char input_buffer[BUFFER_SIZE];

    while (1) {
        printf("Enter a command (or type 'exit' to quit): ");
        fgets(input_buffer, BUFFER_SIZE, stdin);

        if (strcmp(input_buffer, "exit") == 0) {
            break;
        }

        if (num_commands >= MAX_COMMANDS) {
            printf("Error: Too many commands. Exiting.\n");
            return 1;
        }

        commands[num_commands].command = strdup(input_buffer);
        commands[num_commands].pid = fork();

        if (commands[num_commands].pid == -1) {
            printf("Error: Fork failed. Exiting.\n");
            return 1;
        } else if (commands[num_commands].pid == 0) {
            // Child process
            execlp(commands[num_commands].command, commands[num_commands].command, NULL);
            perror("Error: Exec failed");
            exit(1);
        } else {
            // Parent process
            int status;
            waitpid(commands[num_commands].pid, &status, WUNTRACED);

            if (WIFEXITED(status)) {
                commands[num_commands].exit_code = WEXITSTATUS(status);
            } else {
                commands[num_commands].exit_code = -1;
            }

            num_commands++;
        }
    }

    for (int i = 0; i < num_commands; i++) {
        if (commands[i].exit_code == -1) {
            printf("Error: Command '%s' terminated abnormally.\n", commands[i].command);
        } else {
            printf("Command '%s' completed with exit code %d.\n", commands[i].command, commands[i].exit_code);
        }
    }

    return 0;
}