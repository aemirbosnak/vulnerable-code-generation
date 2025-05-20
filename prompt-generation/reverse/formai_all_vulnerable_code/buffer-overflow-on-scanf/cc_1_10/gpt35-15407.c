//FormAI DATASET v1.0 Category: System administration ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void printMenu() {
    printf("+==========================================+\n");
    printf("|             RETRO ADMIN PANEL            |\n");
    printf("+==========================================+\n");
    printf("| Options:                                 |\n");
    printf("|    1. Shutdown System                    |\n");
    printf("|    2. Restart System                     |\n");
    printf("|    3. Get System Information              |\n");
    printf("|    4. Exit Application                   |\n");
    printf("+==========================================+\n");
}

void shutdownSystem() {
    printf("Shutting down system...\n");
    system("shutdown -P now");
}

void restartSystem() {
    printf("Restarting system...\n");
    system("shutdown -r now");
}

void getSystemInformation() {
    printf("Getting system information...\n");
    system("uname -a");
}

int main() {
    bool running = true;
    while (running) {
        printMenu();

        // Get user input
        int choice;
        printf("Please select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                shutdownSystem();
                running = false;
                break;
            case 2:
                restartSystem();
                running = false;
                break;
            case 3:
                getSystemInformation();
                break;
            case 4:
                running = false;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    printf("Exiting application...\n");

    return 0;
}