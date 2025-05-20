//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void listAvailableNetworks() {
    // Command to find available Wi-Fi networks
    const char *command = "sudo iwlist scanning | grep 'ESSID\\|Signal'";
    
    printf("Scanning for available wireless networks...\n");
    
    // Execute the command
    int result = system(command);
    
    if (result == -1) {
        // Handle the error when the command fails to execute
        perror("Error executing iwlist command");
    }
}

void displayMenu() {
    // Simple menu display
    printf("---------------------------------------------------\n");
    printf("                  Wi-Fi Network Scanner            \n");
    printf("---------------------------------------------------\n");
    printf("1. Scan for available networks\n");
    printf("2. Exit\n");
    printf("Please select an option (1-2): ");
}

int main() {
    int choice;

    while (1) {
        clearScreen();
        displayMenu();

        // Get user choice
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listAvailableNetworks();
                printf("\nPress Enter to continue...");
                while (getchar() != '\n'); // Clear buffer before waiting for Enter
                getchar(); // Wait for user to press Enter
                break;

            case 2:
                printf("Exiting the Wi-Fi Network Scanner. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option! Please choose again.\n");
                printf("Press Enter to continue...");
                while (getchar() != '\n'); // Clear buffer before waiting for Enter
                getchar(); // Wait for user to press Enter
                break;
        }
    }

    return 0;
}