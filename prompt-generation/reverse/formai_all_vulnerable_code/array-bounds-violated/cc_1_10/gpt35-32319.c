//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Maximum length of the command
#define MAX_HISTORY 10 // Maximum length of the history

int main(void) {
    char *args[MAX_LINE/2 + 1]; // List of arguments
    char history[MAX_HISTORY][MAX_LINE]; // List of history
    int history_count = -1; // Number of history
    int should_run = 1; // Flag to determine when to exit program

    while (should_run) {
        printf("osh>"); // Print shell prompt
        fflush(stdout);

        char input[MAX_LINE]; // User input
        fgets(input, MAX_LINE, stdin);

        if (strcmp(input, "exit\n") == 0) { // Exit program if user entered "exit"
            should_run = 0;
            break;
        }

        input[strlen(input) - 1] = '\0'; // Replace newline character with null terminator

        if (strlen(input) > 0) {
            history_count++;
            strncpy(history[history_count % MAX_HISTORY], input, MAX_LINE); // Add user input to history

            int i = 0;
            char *token = strtok(input, " "); // Tokenize user input by whitespace

            while (token != NULL) {
                args[i] = token;
                i++;
                token = strtok(NULL, " ");
            }

            args[i] = NULL; // Set last argument to NULL to ensure execvp() works

            if (strcmp(args[0], "history") == 0) { // Display history
                int j;
                int count = history_count < 10 ? history_count : MAX_HISTORY; // Determine number of history to display

                for (j = 0; j < count; j++) {
                    printf("%d. %s\n", j, history[j % MAX_HISTORY]);
                }
            } else {
                pid_t pid = fork(); // Create child process

                if (pid < 0) { // Failed to create child
                    printf("Fork failed\n");
                    exit(1);
                } else if (pid == 0) { // Child process
                    execvp(args[0], args); // Execute command
                    printf("%s: Command not found\n", args[0]);
                    exit(1);
                } else { // Parent process
                    wait(NULL); // Wait for child process to complete
                }
            }
        }
    }

    return 0;
}