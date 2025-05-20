//FormAI DATASET v1.0 Category: System administration ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMainMenu(void);
void displaySystemInfo(void);
void displayUserManagement(void);
void addUser(void);

// Global variables
int userCount = 0;

int main(void) {
    // Display main menu
    displayMainMenu();

    return 0;
}

void displayMainMenu(void) {
    int choice;

    do {
        printf("-------------------------------\n");
        printf("            Main Menu         \n");
        printf("-------------------------------\n");
        printf("1. System Information\n");
        printf("2. User Management\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displaySystemInfo();
                break;
            case 2:
                displayUserManagement();
                break;
            case 3:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);
}

void displaySystemInfo(void) {
    printf("-------------------------------\n");
    printf("        System Information\n");
    printf("-------------------------------\n");
    printf("Operating System: Linux\n");
    printf("Version: 5.4.0-41-generic\n");
    printf("Processor: Intel(R) Core(TM) i5-4460 CPU @ 3.20GHz\n");
    printf("Memory: 8 GB\n");
    printf("Disk Space: 500 GB\n");
}

void displayUserManagement(void) {
    int choice;

    do {
        printf("-------------------------------\n");
        printf("          User Management     \n");
        printf("-------------------------------\n");
        printf("1. Add User\n");
        printf("2. View Users\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addUser();
                break;
            case 2:
                // Placeholder for viewing users
                printf("Viewing Users is not part of this example program.\n");
                break;
            case 3:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);
}

void addUser(void) {
    char username[20];
    printf("Enter username: ");
    scanf("%s", username);

    userCount++;
    printf("User %s added successfully. Total users: %d\n", username, userCount);
}