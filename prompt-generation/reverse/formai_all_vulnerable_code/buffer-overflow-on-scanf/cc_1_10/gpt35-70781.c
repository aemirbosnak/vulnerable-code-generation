//FormAI DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Function to display the options menu
void displayMenu() {
    printf("Options Menu:\n");
    printf("1. View current system status.\n");
    printf("2. Restart system.\n");
    printf("3. View system logs.\n");
    printf("4. Shutdown system.\n");
    printf("5. Exit program.\n");
}

// Function to view current system status
void viewSystemStatus() {
    printf("CPU usage: 55%\n");
    printf("Memory usage: 75%\n");
    printf("Disk usage: 30%\n");
}

// Function to restart the system
void restartSystem() {
    system("shutdown /r /t 0");
}

// Function to view system logs
void viewSystemLogs() {
    printf("System logs:\n");
    printf("01/01/2022 - 12:00 - System started.\n");
    printf("01/01/2022 - 12:30 - File server restarted.\n");
}

// Function to shutdown the system
void shutdownSystem() {
    system("shutdown /s /t 0");
}

// Main function
int main() {
    int choice;

    printf("Welcome to the System Administration Program!\n\n");

    do {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                viewSystemStatus();
                break;

            case 2:
                printf("Restarting system...\n");
                restartSystem();
                break;

            case 3:
                viewSystemLogs();
                break;

            case 4:
                printf("Shutting down system...\n");
                shutdownSystem();
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}