//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to display a welcome message
void displayWelcome() {
    printf("******************************************\n");
    printf("*          Linux System Admin Tool      *\n");
    printf("******************************************\n");
}

// Function to check disk usage
void checkDiskUsage() {
    printf("\nChecking disk usage...\n");
    system("df -h");
}

// Function to list users
void listUsers() {
    printf("\nCurrent system users:\n");
    system("cat /etc/passwd | cut -d: -f1");
}

// Function to check memory usage
void checkMemoryUsage() {
    printf("\nChecking memory usage...\n");
    system("free -h");
}

// Function to display the menu
void displayMenu() {
    printf("\nPlease choose an option:\n");
    printf("1. Check Disk Usage\n");
    printf("2. List Users\n");
    printf("3. Check Memory Usage\n");
    printf("4. Exit\n");
}

// Function to handle the user's choice
void handleChoice(int choice) {
    switch (choice) {
        case 1:
            checkDiskUsage();
            break;
        case 2:
            listUsers();
            break;
        case 3:
            checkMemoryUsage();
            break;
        case 4:
            printf("Exiting the program. Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice! Please select again.\n");
            break;
    }
}

// Main function
int main() {
    int choice;

    displayWelcome();

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        handleChoice(choice);
    }

    return 0;
}