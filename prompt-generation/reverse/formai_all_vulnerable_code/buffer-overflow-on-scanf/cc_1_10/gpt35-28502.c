//FormAI DATASET v1.0 Category: Password management ; Style: complex
/* Password Manager */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of passwords that can be stored
#define MAX_PASSWORDS 100

// Structure to hold a single password and its associated username
typedef struct {
    char username[50];
    char password[50];
} Password;

// Global array to store all passwords
Password passwords[MAX_PASSWORDS];

// Keep track of how many passwords are currently stored
int numPasswordsStored = 0;

// Helper function to clear the input buffer
void clearInputBuffer() {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

// Helper function to print the menu
void printMenu() {
    printf("\n==== Password Manager ====\n");
    printf("1. View All Passwords\n");
    printf("2. Add New Password\n");
    printf("3. Delete Password\n");
    printf("4. Change Password\n");
    printf("5. Quit\n");
    printf("Enter Your Choice: ");
}

// Helper function to print a single password entry
void printPassword(Password password) {
    printf("Username: %s\n", password.username);
    printf("Password: %s\n", password.password);
}

// Function to view all stored passwords
void viewAllPasswords() {
    printf("\n==== All Passwords ====\n");
    if (numPasswordsStored == 0) {
        printf("There are no passwords stored.\n");
    } else {
        for (int i = 0; i < numPasswordsStored; i++) {
            printf("Password %d:\n", i + 1);
            printPassword(passwords[i]);
            printf("\n");
        }
    }
}

// Function to add a new password
void addNewPassword() {
    printf("\nEnter New Password Details:\n");
    printf("Username: ");
    char username[50];
    scanf("%s", username);
    clearInputBuffer();
    printf("Password: ");
    char password[50];
    scanf("%s", password);
    clearInputBuffer();
    if (numPasswordsStored < MAX_PASSWORDS) {
        Password newPassword;
        strncpy(newPassword.username, username, sizeof(newPassword.username));
        strncpy(newPassword.password, password, sizeof(newPassword.password));
        passwords[numPasswordsStored] = newPassword;
        numPasswordsStored++;
        printf("Password added successfully.\n");
    } else {
        printf("Cannot add new password. Maximum number of passwords reached.\n");
    }
}

// Function to delete a password
void deletePassword() {
    printf("\nEnter Password Number to Delete: ");
    int passwordNumberToDelete;
    scanf("%d", &passwordNumberToDelete);
    clearInputBuffer();
    if (passwordNumberToDelete >= 1 && passwordNumberToDelete <= numPasswordsStored) {
        // Shift all the passwords after the deleted one one position to the left
        for (int i = passwordNumberToDelete - 1; i < numPasswordsStored - 1; i++) {
            passwords[i] = passwords[i + 1];
        }
        numPasswordsStored--;
        printf("Password deleted successfully.\n");
    } else {
        printf("Invalid password number.\n");
    }
}

// Function to change a password
void changePassword() {
    printf("\nEnter Password Number to Change: ");
    int passwordNumberToChange;
    scanf("%d", &passwordNumberToChange);
    clearInputBuffer();
    if (passwordNumberToChange >= 1 && passwordNumberToChange <= numPasswordsStored) {
        printf("New Username: ");
        char newUsername[50];
        scanf("%s", newUsername);
        clearInputBuffer();
        printf("New Password: ");
        char newPassword[50];
        scanf("%s", newPassword);
        clearInputBuffer();
        strncpy(passwords[passwordNumberToChange - 1].username, newUsername, sizeof(passwords[passwordNumberToChange - 1].username));
        strncpy(passwords[passwordNumberToChange - 1].password, newPassword, sizeof(passwords[passwordNumberToChange - 1].password));
        printf("Password changed successfully.\n");
    } else {
        printf("Invalid password number.\n");
    }
}

int main() {
    // Main program loop
    while (1) {
        printMenu();
        int choice;
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice) {
            case 1:
                viewAllPasswords();
                break;
            case 2:
                addNewPassword();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                changePassword();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}