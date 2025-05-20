//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
/*
 * This is a basic Unix-like shell program in C.
 * It allows the user to enter commands and execute them.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 256

void run_command(char *cmd) {
    // Tokenize the command and store the tokens in an array
    char *tokens[MAX_CMD_LENGTH];
    int num_tokens = 0;
    char *token = strtok(cmd, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Fork a new process and execute the command
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(tokens[0], tokens);
        exit(1);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);
    } else {
        // Error
        fprintf(stderr, "Failed to fork process\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    char cmd[MAX_CMD_LENGTH];

    while (1) {
        // Prompt the user to enter a command
        printf("$ ");
        fgets(cmd, MAX_CMD_LENGTH, stdin);
        cmd[strlen(cmd) - 1] = '\0';

        // Run the command
        run_command(cmd);
    }

    return 0;
}