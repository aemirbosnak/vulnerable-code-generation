//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void checkDiskUsage() {
    printf("\n--- Disk Usage ---\n");
    system("df -h");
}

void checkUptime() {
    printf("\n--- System Uptime ---\n");
    system("uptime");
}

void listActiveUsers() {
    printf("\n--- Active Users ---\n");
    system("who");
}

void memoryUsage() {
    printf("\n--- Memory Usage ---\n");
    system("free -h");
}

void displayMenu() {
    printf("\n--- System Administration Menu ---\n");
    printf("1. Check Disk Usage\n");
    printf("2. Check System Uptime\n");
    printf("3. List Active Users\n");
    printf("4. Check Memory Usage\n");
    printf("5. Exit\n");
    printf("\nPlease choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkDiskUsage();
                break;
            case 2:
                checkUptime();
                break;
            case 3:
                listActiveUsers();
                break;
            case 4:
                memoryUsage();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Wait for a moment before redisplaying the menu
        printf("\nPress Enter to continue...");
        while (getchar() != '\n'); // clear the input buffer
        getchar(); // wait for Enter key
    }

    return 0;
}