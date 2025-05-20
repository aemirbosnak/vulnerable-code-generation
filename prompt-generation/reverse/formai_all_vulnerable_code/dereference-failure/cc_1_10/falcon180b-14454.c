//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0

// Function to execute a command
void execute_command(char** command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(command[0], command) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid < 0) {
        // Error forking
        perror("Error forking");
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

// Function to parse input into command and arguments
void parse_input(char* input, char*** command) {
    char* token;
    int argc = 0;

    // Allocate memory for command array
    char** argv = malloc(MAX_COMMAND_LENGTH * sizeof(char*));
    if (argv == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Parse input into command and arguments
    token = strtok(input, DELIM);
    while (token!= NULL) {
        argv[argc] = token;
        argc++;
        if (argc >= MAX_COMMAND_LENGTH) {
            perror("Error: command too long");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    // Set command pointer to point to first element of argv
    *command = argv;
}

// Function to print prompt and read input
void read_input(char** command) {
    char input[MAX_COMMAND_LENGTH];

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Parse input into command and arguments
    parse_input(input, command);
}

// Main function
int main() {
    char** command = NULL;

    while (TRUE) {
        read_input(&command);
        execute_command(command);
    }

    return 0;
}