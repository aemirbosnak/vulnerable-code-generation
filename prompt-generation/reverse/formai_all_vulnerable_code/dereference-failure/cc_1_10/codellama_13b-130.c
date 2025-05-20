//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
/*
 * A peaceful Unix-like shell example program
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 10

// A struct to represent a command and its arguments
struct command {
    char* cmd;
    char* args[MAX_ARGS];
};

// A function to execute a command
void execute_command(struct command* cmd) {
    char* args[MAX_ARGS];
    int i;

    // Copy the command and its arguments to a new array
    for (i = 0; i < MAX_ARGS; i++) {
        args[i] = cmd->args[i];
    }

    // Add a NULL terminator to the end of the array
    args[MAX_ARGS - 1] = NULL;

    // Execute the command
    execvp(cmd->cmd, args);
}

// A function to read a command from the user
struct command* read_command() {
    struct command* cmd = malloc(sizeof(struct command));
    char line[1024];
    char* token;
    int i = 0;

    // Read a line from the user
    fgets(line, 1024, stdin);

    // Tokenize the line into words
    token = strtok(line, " ");
    while (token != NULL) {
        cmd->args[i++] = token;
        token = strtok(NULL, " ");
    }

    // Add a NULL terminator to the end of the arguments array
    cmd->args[i] = NULL;

    // Return the command
    return cmd;
}

int main() {
    struct command* cmd;
    int status;

    while (1) {
        // Print the prompt
        printf("$ ");

        // Read a command from the user
        cmd = read_command();

        // Execute the command
        execute_command(cmd);

        // Wait for the command to finish
        wait(&status);

        // Free the command struct
        free(cmd);
    }

    return 0;
}