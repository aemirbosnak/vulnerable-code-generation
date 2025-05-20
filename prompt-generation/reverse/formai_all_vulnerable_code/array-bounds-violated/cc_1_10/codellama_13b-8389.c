//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
/*
 * A Basic Unix-like Shell in C
 *
 * This program simulates a Unix-like shell, with basic functionality such as
 * command line editing, command history, and shell built-in commands.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 128

char* cmd_history[100];
int cmd_history_index = 0;

void print_prompt() {
    printf("$ ");
}

void clear_line() {
    printf("\033[2K");
}

void handle_command(char* cmd) {
    char* args[MAX_ARGS];
    int argc = 0;

    // Tokenize the command
    char* token = strtok(cmd, " ");
    while (token != NULL) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }

    // Check if the command is a built-in command
    if (strcmp(args[0], "cd") == 0) {
        if (argc == 1) {
            chdir(getenv("HOME"));
        } else if (argc == 2) {
            chdir(args[1]);
        }
    } else if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else {
        // Fork a child process to execute the command
        int pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            // Wait for the child process to exit
            wait(NULL);
        }
    }
}

void handle_history() {
    if (cmd_history_index > 0) {
        char* cmd = cmd_history[cmd_history_index - 1];
        printf("!%s\n", cmd);
    } else {
        printf("No history available.\n");
    }
}

int main() {
    // Print the prompt
    print_prompt();

    // Read a command from the user
    char cmd[MAX_CMD_LEN];
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Remove the newline character
    cmd[strlen(cmd) - 1] = '\0';

    // Check if the command is empty
    if (strlen(cmd) == 0) {
        return 0;
    }

    // Add the command to the history
    if (cmd_history_index < 100) {
        cmd_history[cmd_history_index++] = cmd;
    }

    // Handle the command
    handle_command(cmd);

    // Clear the line
    clear_line();

    // Print the prompt again
    print_prompt();

    return 0;
}