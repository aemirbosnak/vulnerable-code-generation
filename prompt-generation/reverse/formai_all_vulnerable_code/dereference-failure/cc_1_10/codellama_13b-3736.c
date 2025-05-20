//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Define the prompt string
    char prompt[100] = "> ";

    // Define the command buffer
    char cmd[100];

    // Loop until the user enters the exit command
    while (1) {
        // Print the prompt
        printf("%s", prompt);

        // Read the command from the user
        fgets(cmd, 100, stdin);

        // Check if the command is empty
        if (strlen(cmd) == 0) {
            continue;
        }

        // Check if the command is "exit"
        if (strcmp(cmd, "exit") == 0) {
            break;
        }

        // Parse the command and arguments
        char *token = strtok(cmd, " ");
        char *cmd_name = token;
        char *cmd_args[10];
        int argc = 0;
        while (token != NULL) {
            cmd_args[argc++] = token;
            token = strtok(NULL, " ");
        }

        // Execute the command
        if (strcmp(cmd_name, "cd") == 0) {
            if (argc == 2) {
                chdir(cmd_args[1]);
            } else {
                printf("Usage: cd <directory>\n");
            }
        } else if (strcmp(cmd_name, "ls") == 0) {
            if (argc == 1) {
                system("ls -l");
            } else {
                printf("Usage: ls\n");
            }
        } else {
            printf("Unknown command: %s\n", cmd_name);
        }
    }

    // Exit the program
    printf("Bye!\n");
    return 0;
}