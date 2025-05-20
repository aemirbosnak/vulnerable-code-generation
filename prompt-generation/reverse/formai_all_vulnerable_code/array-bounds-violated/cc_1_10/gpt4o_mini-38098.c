//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_LINE 1024
#define MAX_ARGS 128

void parse_input(char *input, char **args) {
    char *token;
    int position = 0;

    token = strtok(input, " \n");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
}

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if ((pid = fork()) == 0) {  // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {  // Error forking
        perror("shell");
    } else {  // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void execute_pipeline(char ***commands, int num_commands) {
    int pipefd[2 * (num_commands - 1)], i;

    for (i = 0; i < num_commands - 1; i++) {
        if (pipe(pipefd + i * 2) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < num_commands; i++) {
        pid_t pid = fork();
        if (pid == 0) {  // Child process
            if (i != 0) {  // Not the first command
                dup2(pipefd[(i - 1) * 2], STDIN_FILENO);
            }
            if (i != num_commands - 1) {  // Not the last command
                dup2(pipefd[i * 2 + 1], STDOUT_FILENO);
            }
            for (int j = 0; j < 2 * (num_commands - 1); j++) {
                close(pipefd[j]);
            }
            execvp(commands[i][0], commands[i]);
            perror("shell");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < 2 * (num_commands - 1); i++) {
        close(pipefd[i]);
    }

    for (i = 0; i < num_commands; i++) {
        wait(NULL);
    }
}

int main() {
    char input[MAX_LINE];
    char *args[MAX_ARGS];
    char *commands[MAX_ARGS][MAX_ARGS];
    int background;

    while (1) {
        printf("myshell> ");
        if (!fgets(input, MAX_LINE, stdin)) {
            break; // Exit on EOF
        }

        // Check for background process
        background = 0;
        if (input[strlen(input) - 2] == '&') {
            background = 1;
            input[strlen(input) - 2] = '\0'; // Remove '&'
        }

        parse_input(input, args);

        // Handle exit command
        if (args[0] == NULL) {
            continue; // Ignore empty input
        }
        if (strcmp(args[0], "exit") == 0) {
            break; // Exit shell
        }

        // Check for pipes
        char *cmd = strtok(input, "|");
        int command_count = 0;
        while (cmd != NULL) {
            parse_input(cmd, commands[command_count]);
            command_count++;
            cmd = strtok(NULL, "|");
        }

        // Execute pipeline if there are multiple commands
        if (command_count > 1) {
            execute_pipeline(commands, command_count);
        } else {
            execute_command(args);
        }

        // If running in background, don't wait
        if (background) {
            continue;
        }
    }

    return EXIT_SUCCESS;
}