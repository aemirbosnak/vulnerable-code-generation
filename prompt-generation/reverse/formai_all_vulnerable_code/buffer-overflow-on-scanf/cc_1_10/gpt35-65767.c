//FormAI DATASET v1.0 Category: Password management ; Style: cheerful
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20 // Maximum length of password
#define MAX_NUM_PASSWORDS 50 // Maximum number of passwords allowed

// Function declarations
void addPassword();
void viewPasswords();
void searchPasswords();
void deletePassword();

// Global variables
char passwords[MAX_NUM_PASSWORDS][MAX_PASSWORD_LENGTH];
int numPasswords = 0;

// Main function
int main() {
    int choice;

    printf("****** Welcome to Password Manager ******\n\n");

    while (1) {
        // Print menu options
        printf("What would you like to do?\n");
        printf("1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Delete a password\n");
        printf("5. Exit\n");

        // Get user choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Call appropriate function based on user choice
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                searchPasswords();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                printf("\nGoodbye! Have a great day!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to add a password
void addPassword() {
    // Check if maximum number of passwords has been reached
    if (numPasswords == MAX_NUM_PASSWORDS) {
        printf("\nMaximum number of passwords reached! Please delete a password before adding a new one.\n");
        return;
    }

    char password[MAX_PASSWORD_LENGTH];
    printf("\nEnter the password (maximum 20 characters): ");
    scanf("%s", password);

    // Check if password already exists
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i], password) == 0) {
            printf("\nPassword already exists! Please try again.\n");
            return;
        }
    }

    // Add password to array
    strcpy(passwords[numPasswords], password);
    numPasswords++;

    printf("\nPassword added successfully!\n");
}

// Function to view all passwords
void viewPasswords() {
    // Check if there are any passwords
    if (numPasswords == 0) {
        printf("\nNo passwords to display! Please add a password.\n");
        return;
    }

    printf("\nAll Passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%d. %s\n", i + 1, passwords[i]);
    }
}

// Function to search for a password
void searchPasswords() {
    // Check if there are any passwords
    if (numPasswords == 0) {
        printf("\nNo passwords to search! Please add a password.\n");
        return;
    }

    char searchTerm[MAX_PASSWORD_LENGTH];
    printf("\nEnter search term (maximum 20 characters): ");
    scanf("%s", searchTerm);

    // Search for password
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i], searchTerm) == 0) {
            printf("\nPassword found at index %d!\n", i + 1);
            return;
        }
    }

    printf("\nPassword not found! Please try again.\n");
}

// Function to delete a password
void deletePassword() {
    // Check if there are any passwords
    if (numPasswords == 0) {
        printf("\nNo passwords to delete! Please add a password.\n");
        return;
    }

    int index;
    printf("\nEnter index of password to delete: ");
    scanf("%d", &index);

    // Check if index is valid
    if (index < 1 || index > numPasswords) {
        printf("\nInvalid index! Please try again.\n");
        return;
    }

    // Delete password from array
    for (int i = index - 1; i < numPasswords - 1; i++) {
        strcpy(passwords[i], passwords[i + 1]);
    }
    numPasswords--;

    printf("\nPassword deleted successfully!\n");
}