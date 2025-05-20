//FormAI DATASET v1.0 Category: System administration ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototype
void displayMenu();
void updatePermissions(int *permissions);
void changePassword(char *password, int *attempts);

int main()
{
    // Initialize variables
    int permissions = 1;
    char password[10] = "rootpass";
    int attempts = 0;

    // Display welcome message
    printf("Welcome to the FutureSys Administration Program!\n");
    displayMenu();

    // Control loop for main program
    while (1) {
        // Get user choice
        int choice;
        printf("What would you like to do? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Display current permissions
                printf("Current permission level: %d\n", permissions);
                break;
            case 2:
                // Update permissions
                updatePermissions(&permissions);
                break;
            case 3:
                // Change password
                changePassword(password, &attempts);
                break;
            case 4:
                // Terminate program
                printf("Thank you for using FutureSys!\n");
                exit(0);
            default:
                // Invalid input
                printf("Invalid input. Please enter a choice from the menu.\n");
                displayMenu();
                break;
        }
    }

    return 0;
}

void displayMenu()
{
    // Display menu options
    printf("\n====== MENU ======\n");
    printf("1. Check permissions\n");
    printf("2. Update permissions\n");
    printf("3. Change password\n");
    printf("4. Exit program\n");
}

void updatePermissions(int *permissions)
{
    // Get new permissions level from user
    printf("Enter new permission level (1-3): ");
    int newLevel;
    scanf("%d", &newLevel);

    // Check validity of new permissions
    if (newLevel < 1 || newLevel > 3) {
        printf("Invalid input. Permission level must be between 1 and 3.\n");
        return;
    }

    // Update permissions
    *permissions = newLevel;
    printf("Permissions updated successfully.\n");
}

void changePassword(char *password, int *attempts)
{
    // Get old password from user
    char oldPassword[10];
    printf("Enter old password: ");
    scanf("%s", oldPassword);

    // Check if old password matches
    if (strcmp(oldPassword, password) != 0) {
        printf("Incorrect password.\n");
        (*attempts)++;

        // Lock system after 3 unsuccessful attempts
        if (*attempts >= 3) {
            printf("Too many unsuccessful attempts. System locked.\n");
            exit(0);
        }

        return;
    }

    // Get new password from user
    char newPassword[10];
    printf("Enter new password: ");
    scanf("%s", newPassword);

    // Update password
    strcpy(password, newPassword);
    printf("Password changed successfully.\n");
}