//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

// Function to parse the command line and execute the command
int execute_command(char *command) {
    char *argv[100]; // Array to store the command arguments
    int argc = 0; // Number of arguments
    char *token; // Tokenizer

    // Parse the command line into arguments
    token = strtok(command, " ");
    while (token != NULL) {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL; // Null-terminate the array of arguments

    // Execute the command using execvp()
    if (execvp(argv[0], argv) == -1) {
        perror("Error executing command");
        return 1;
    }

    return 0;
}

// Main function
int main() {
    char command[100]; // Buffer to store the command

    // Read the command from the user
    printf("Enter a command: ");
    fgets(command, sizeof(command), stdin);

    // Remove the newline character from the command
    command[strlen(command) - 1] = '\0';

    // Execute the command
    if (strcmp(command, "exit") == 0) {
        exit(0); // Exit the shell
    } else {
        execute_command(command); // Execute the command
    }

    return 0;
}