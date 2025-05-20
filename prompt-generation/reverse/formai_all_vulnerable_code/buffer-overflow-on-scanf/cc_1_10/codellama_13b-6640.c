//Code Llama-13B DATASET v1.0 Category: System administration ; Style: curious
// A curious system administration example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    char username[20];
    char password[20];
    char command[20];
    char output[100];

    // Prompt user for username and password
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if username and password are correct
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
        // If correct, prompt user for command
        printf("Enter a command: ");
        scanf("%s", command);

        // Execute command
        if (strcmp(command, "shutdown") == 0) {
            // Shutdown command
            printf("Shutting down system...\n");
            system("shutdown -s -t 0");
        } else if (strcmp(command, "restart") == 0) {
            // Restart command
            printf("Restarting system...\n");
            system("shutdown -r -t 0");
        } else if (strcmp(command, "logoff") == 0) {
            // Logoff command
            printf("Logging off...\n");
            system("logoff");
        } else if (strcmp(command, "help") == 0) {
            // Help command
            printf("Available commands:\n");
            printf("  shutdown: Shuts down the system.\n");
            printf("  restart: Restarts the system.\n");
            printf("  logoff: Logs off the current user.\n");
            printf("  help: Displays this help message.\n");
        } else {
            // Invalid command
            printf("Invalid command.\n");
        }
    } else {
        // Invalid username or password
        printf("Invalid username or password.\n");
    }

    return 0;
}