//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: genious
// This is a Unix-like shell program that implements a small command-line interface

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Maximum length of command
#define MAX_ARGS 10 // Maximum number of command arguments

int main() {
    char *args[MAX_ARGS]; // Array of command arguments
    char command[MAX_LINE]; // Command string
    int should_run = 1, argc = 0;
  
    while (should_run) {
        printf("genius@unix:~$ "); // Print shell prompt
        fflush(stdout); // Flush output stream
        
        // Read command from input
        fgets(command, MAX_LINE, stdin);
        if (command[strlen(command)-1] == '\n') {
            command[strlen(command)-1] = '\0'; // Remove trailing newline character
        }
        
        if (strcmp(command, "exit") == 0) { // Handle exit command
            should_run = 0;
            continue;
        }
        
        // Parse command arguments
        argc = 0;
        args[argc] = strtok(command, " ");
        while (args[argc] != NULL && argc < MAX_ARGS) {
            argc++;
            args[argc] = strtok(NULL, " ");
        }
        
        // Execute command in child process
        pid_t pid = fork();
        if (pid < 0) { // Error: failed to fork
            fprintf(stderr, "Error: failed to fork\n");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // Child process
            execvp(args[0], args);
            fprintf(stderr, "Error: command not found\n");
            exit(EXIT_FAILURE);
        } else { // Parent process
            wait(NULL); // Wait for child process to complete
        }
    }
  
    return 0;
}