//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024 // Maximum length of command allowed
#define MAX_COMMANDS 10 // Maximum no of commands allowed using pipe '|'

char hist[MAX_LENGTH][MAX_COMMANDS]; // History of commands with pipe separator

void clear_history() {
    memset(hist, 0, sizeof(hist));
}

// Helper function for splitting commands with pipe separator '|'
void split_commands(char *command, char **commands, int *num_commands) {
    char *command_token;

    *num_commands = 0;
    while ((command_token = strsep(&command, "|"))) {
        if (*num_commands >= MAX_COMMANDS) {
            printf("Max commands exceeded! Please use less pipe characters.\n");
            exit(1);
        }
        if (command_token[0] != '\0') {
            commands[*num_commands] = command_token;
            (*num_commands)++;
        }
    }
}

void execute_command(char *command) {
    int status;
    char *arguments[MAX_LENGTH/2 + 1];
    int num_args = 0;

    while (*command && (*command == ' ' || *command == '\t')) command++; // Remove any leading whitespaces or tabs

    if (*command == '\0') return; // Empty command

    // Divide command into arguments
    while (*command) {
        arguments[num_args] = command;
        num_args++;

        while (*command && *command != ' ' && *command != '\t') command++;

        if (*command) {
            *command++ = '\0';
            while (*command && (*command == ' ' || *command == '\t')) command++; // Remove any extra whitespaces or tabs between arguments
        }
    }
    arguments[num_args] = NULL;

    // Checking history command
    if (strcmp(arguments[0], "history") == 0) {
        for (int i = 0; i < MAX_LENGTH; i++) {
            if (hist[i][0] == 0) break;
            printf("%s\n", hist[i]);
        }
        return;
    }

    // Checking exclamation command
    if (arguments[0][0] == '!') {
        int index = atoi(&arguments[0][1]);
        strcpy(command, hist[index - 1]); // Repeat the command from history
        num_args = 0;

        while (*command) {
            arguments[num_args] = command;
            num_args++;

            while (*command && *command != ' ' && *command != '\t') command++;

            if (*command) {
                *command++ = '\0';
                while (*command && (*command == ' ' || *command == '\t')) command++;
            }
        }
        arguments[num_args] = NULL;
    }

    // Adding command into history
    for (int i = MAX_LENGTH - 1; i > 0; i--) {
        strcpy(hist[i], hist[i-1]);
    }
    strcpy(hist[0], command);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Failed to fork.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execvp(arguments[0], arguments) < 0) {
            printf("Invalid command.\n");
            exit(1);
        }
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

int main() {
    char command[MAX_LENGTH];
    char *commands[MAX_COMMANDS];
    int num_commands;
    clear_history(); // Clear history at the start of program

    while (1) {
        printf("> ");
        fflush(stdout); // Flush the output buffer

        // Read command from user input
        fgets(command, MAX_LENGTH, stdin);
        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }

        // Execute command(s)
        split_commands(command, commands, &num_commands);
        for (int i = 0; i < num_commands; i++) {
            execute_command(commands[i]);
        }
    }
    return 0;
}