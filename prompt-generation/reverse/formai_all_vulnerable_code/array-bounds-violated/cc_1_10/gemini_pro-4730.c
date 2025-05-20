//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Structure to store command and its arguments
typedef struct {
    char *command;
    char **args;
    int num_args;
} Command;

// Function to parse a command line
Command *parse_command(char *line) {
    Command *cmd = malloc(sizeof(Command));
    cmd->command = strtok(line, " ");
    cmd->args = malloc(sizeof(char *) * 10);
    int i = 0;
    while ((cmd->args[i] = strtok(NULL, " ")) != NULL) {
        i++;
    }
    cmd->num_args = i;
    return cmd;
}

// Function to execute a command
void execute_command(Command *cmd) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(cmd->command, cmd->args);
        perror("execvp");
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

// Main function
int main() {
    // Main loop
    while (1) {
        // Print prompt
        printf("$ ");

        // Get user input
        char line[1024];
        fgets(line, sizeof(line), stdin);

        // Remove newline character from input
        line[strlen(line) - 1] = '\0';

        // Parse command
        Command *cmd = parse_command(line);

        // Execute command
        execute_command(cmd);

        // Free memory
        free(cmd->args);
        free(cmd);
    }

    return 0;
}