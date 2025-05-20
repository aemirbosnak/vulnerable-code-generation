//FormAI DATASET v1.0 Category: System administration ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to display menu
void displayMenu() {
    printf("========== MENU ==========\n");
    printf("1. Check disk space\n");
    printf("2. Check CPU usage\n");
    printf("3. Restart Apache server\n");
    printf("4. List all running processes\n");
    printf("5. Quit program\n");
    printf("==========================\n\n");
}

// function to check disk space
void checkDiskSpace() {
    system("df -h");
}

// function to check CPU usage
void checkCPUUsage() {
    system("top");
}

// function to restart Apache server
void restartApache() {
    system("sudo service apache2 restart");
}

// function to list all running processes
void listProcesses() {
    system("ps -ef");
}

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                checkDiskSpace();
                break;
            case 2:
                checkCPUUsage();
                break;
            case 3:
                restartApache();
                break;
            case 4:
                listProcesses();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
    } while (choice != 5);

    return 0;
}