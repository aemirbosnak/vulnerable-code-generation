//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#define MAX_INPUT_SIZE 20
#define MAX_COMMANDS 3
#define MAX_COMMAND_LENGTH 50

int main() {
    char commands[MAX_COMMANDS][MAX_COMMAND_LENGTH];
    int cmd_index = 0;
    char input[MAX_INPUT_SIZE];
    int status;

    printf("Welcome to ApocalypseShell, the post-apocalyptic survival shell.\n");
    printf("Use only the following commands: LIST, EXEC, or QUIT.\n");
    printf("Type CTRL-D to exit.\n");

    while (1) {
        printf("ApocalypseShell> ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Split input into command and arguments
        char *token = strtok(input, " ");
        strcpy(commands[cmd_index], token);

        // Check for command termination
        if (strcmp(commands[cmd_index], "QUIT") == 0) {
            break;
        }

        // Increment command index
        cmd_index++;

        // Handle LIST and EXEC commands
        if (strcmp(commands[cmd_index - 1], "LIST") == 0 ||
            strcmp(commands[cmd_index - 1], "EXEC") == 0) {

            if (cmd_index >= MAX_COMMANDS) {
                printf("Error: Too many commands.\n");
                cmd_index--;
                continue;
            }

            strcpy(commands[cmd_index], "");
            memset(input, 0, MAX_INPUT_SIZE);
        }

        // Handle LIST command
        if (strcmp(commands[cmd_index - 1], "LIST") == 0) {
            printf("Commands:\n");
            for (int i = 0; i < cmd_index; i++) {
                printf("- %s\n", commands[i]);
            }
            cmd_index--;
        }

        // Handle EXEC command
        if (strcmp(commands[cmd_index - 1], "EXEC") == 0) {
            if (cmd_index < 2) {
                printf("Error: No command provided.\n");
                cmd_index--;
                continue;
            }

            pid_t pid = fork();

            if (pid == -1) {
                perror("Error: Fork failed.");
                cmd_index--;
                continue;
            } else if (pid > 0) {
                wait(&status);
            } else {
                char *args[2];
                args[0] = strtok(commands[cmd_index - 1], " ");
                args[1] = NULL;

                if (execvp(args[0], args) == -1) {
                    perror("Error: Command execution failed.");
                    _exit(1);
                }
            }

            cmd_index = 0;
        }
    }

    return 0;
}