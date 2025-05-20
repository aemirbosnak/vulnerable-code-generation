//FormAI DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 16

void execute_command(char* args[]) {
    // Fork a new process
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        execvp(args[0], args);
        // If execvp returns, it means there was an error
        perror("Execvp failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_ARGS] = {NULL};

    printf("Welcome to the single-threaded command prompt!\n");

    while (1) {
        // Read input from user
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strlen(command) - 1] = '\0';

        // Tokenize input into arguments
        char* token = strtok(command, " ");
        int arg_count = 0;
        while (token != NULL && arg_count < MAX_ARGS - 1) {
            args[arg_count] = token;
            token = strtok(NULL, " ");
            arg_count++;
        }
        args[arg_count] = NULL;

        // Execute command
        execute_command(args);
    }

    return 0;
}