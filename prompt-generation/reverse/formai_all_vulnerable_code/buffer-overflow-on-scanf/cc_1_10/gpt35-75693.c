//FormAI DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100 // Maximum number of passwords to store
#define MAX_LENGTH 50 // Maximum length of each password

// Function to print all password stored in the password database
void printPasswords(char passwords[][MAX_LENGTH], int numPasswords) {
    printf("Passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%d. %s\n", i+1, passwords[i]);
    }
}

int main() {
    char passwords[MAX_PASSWORDS][MAX_LENGTH]; // Array to store passwords
    int numPasswords = 0; // Number of passwords stored in the array

    // Welcome message
    printf("Welcome to the password manager!\n\n");

    // Main menu
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add a password\n");
        printf("2. Remove a password\n");
        printf("3. View all passwords\n");
        printf("4. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1: // Add a password
                if (numPasswords == MAX_PASSWORDS) {
                    printf("Error: Maximum number of passwords reached.\n\n");
                    break;
                }
                char password[MAX_LENGTH];
                printf("Enter the password you want to store: ");
                scanf("%s", password);
                strcpy(passwords[numPasswords], password);
                numPasswords++;
                printf("Password added.\n\n");
                break;

            case 2: // Remove a password
                if (numPasswords == 0) {
                    printf("Error: No passwords stored.\n\n");
                    break;
                }
                int passwordIndex;
                printf("Which password would you like to remove? Enter its number: ");
                scanf("%d", &passwordIndex);
                if (passwordIndex < 1 || passwordIndex > numPasswords) {
                    printf("Error: Invalid password number.\n\n");
                    break;
                }
                for (int i = passwordIndex-1; i < numPasswords-1; i++) {
                    strcpy(passwords[i], passwords[i+1]);
                }
                numPasswords--;
                printf("Password removed.\n\n");
                break;

            case 3: // View all passwords
                if (numPasswords == 0) {
                    printf("No passwords stored.\n\n");
                    break;
                }
                printPasswords(passwords, numPasswords);
                break;

            case 4: // Exit
                printf("Thank you for using the password manager.\n\n");
                exit(0);

            default: // Invalid choice
                printf("Error: Invalid choice.\n\n");
                break;
        }
    }
    return 0;
}