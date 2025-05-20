//GEMINI-pro DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// This program demonstrates a whimsical system administration scenario.
// A benevolent AI assistant named "SysBot" helps a hapless administrator named "User" manage system tasks.

int main() {
    // Initialize variables
    char command[100];
    int status;

    // Introduce the characters
    printf("User: Hey SysBot, I'm having a rough day. Can you help me out with some system tasks?\n");
    printf("SysBot: Of course, User. What seems to be the problem?\n");

    // Loop through User's requests
    while (1) {
        // Prompt User for input
        printf("User: ");
        scanf("%s", command);

        // Exit if User enters "quit"
        if (strcmp(command, "quit") == 0) {
            printf("SysBot: Farewell, User. May your systems run smoothly!\n");
            exit(0);
        }

        // Check if User needs help
        if (strcmp(command, "help") == 0) {
            printf("SysBot: Here are some common commands I can assist you with:\n");
            printf("- 'ls': List files in a directory\n");
            printf("- 'mkdir': Create a new directory\n");
            printf("- 'cd': Change directory\n");
            printf("- 'ps': List running processes\n");
            printf("- 'kill': Terminate a running process\n");
            continue;
        }

        // Spawn a child process to execute the command
        pid_t child_pid = fork();
        if (child_pid == 0) {
            // Child process executes the command
            execlp(command, command, NULL);
            perror("Error executing command:");
            exit(1);
        } else {
            // Parent process waits for child to complete
            wait(&status);
            if (WIFEXITED(status)) {
                // Child exited normally
                printf("SysBot: Command '%s' completed with exit status %d\n", command, WEXITSTATUS(status));
            } else {
                // Child exited abnormally
                printf("SysBot: Command '%s' terminated abnormally\n", command);
            }
        }
    }

    return 0;
}