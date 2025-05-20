//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

int main()
{
    char input[MAX_COMMAND_LENGTH]; // Buffer for user input
    char* args[MAX_ARGS]; // Array of pointers to arguments to be passed to execvp()
    
    while (1) { // Loop until user exits
        printf("$ "); // Print shell prompt
        fgets(input, MAX_COMMAND_LENGTH, stdin); // Read user input
        
        // Replace newline character with NULL terminator
        input[strcspn(input, "\n")] = '\0';
        
        // Tokenize input into arguments
        args[0] = strtok(input, " ");
        for (int i = 1; i < MAX_ARGS && args[i-1] != NULL; i++) {
            args[i] = strtok(NULL, " ");
        }
        
        // Clear remaining args array if necessary
        if (args[MAX_ARGS-1] != NULL) {
            for (int i = MAX_ARGS-1; i >= 0; i--) {
                if (args[i] == NULL) { // Found end of argument list
                    break;
                }
                args[i] = NULL; // Clear argument pointer
            }
        }
        
        // Exit shell if user types "exit"
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }
        
        pid_t pid = fork(); // Create child process
        
        if (pid < 0) { // Fork error
            printf("Error: Unable to fork process\n");
            exit(1);
        } else if (pid == 0) { // Child process
            execvp(args[0], args); // Try to run command
            printf("Error: Unknown command '%s'\n", args[0]); // Command not found
            exit(1);
        } else { // Parent process
            int status;
            waitpid(pid, &status, 0); // Wait for child to finish
            if (WIFEXITED(status)) { // Check if child terminated normally
                int exit_code = WEXITSTATUS(status); // Get exit code of child
                if (exit_code != 0) { // Command failed
                    printf("Error: Command exited with status code %d\n", exit_code);
                }
            }
        }
    }
    return 0; // Should never reach here
}