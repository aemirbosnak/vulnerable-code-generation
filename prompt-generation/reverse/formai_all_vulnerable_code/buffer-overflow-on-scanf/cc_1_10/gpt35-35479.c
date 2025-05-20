//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of any password
#define MAX_PASSWORD_LENGTH 20

// Declare a struct to store password information
typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordInfo;

// Declare a function to create a new password entry
void addPassword(PasswordInfo *passwords, int *numPasswords);

//Declare a function to print all password entries
void printPasswords(PasswordInfo *passwords, int numPasswords);

int main() {
    int choice, numPasswords = 0;
    PasswordInfo *passwords = malloc(sizeof(PasswordInfo));

    // Welcome menu
    printf("Welcome to Password Management System\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Quit\n");

    // Keep allowing choices until user selects Quit
    do {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword(passwords, &numPasswords);
                break;
            case 2:
                printPasswords(passwords, numPasswords);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}

void addPassword(PasswordInfo *passwords, int *numPasswords) {
    PasswordInfo newPass;

    // Get the username and password from user
    printf("\nEnter username: ");
    scanf("%s", newPass.username);
    printf("Enter password: ");
    scanf("%s", newPass.password);

    // Check if the password is already in the system
    for (int i = 0; i < *numPasswords; i++) {
        if (strcmp(passwords[i].username, newPass.username) == 0) {
            printf("\nPassword already exists for that username.\n");
            return;
        }
    }

    // Resize the array and add the new password
    *numPasswords += 1;
    passwords = realloc(passwords, (*numPasswords) * sizeof(PasswordInfo));
    passwords[*numPasswords-1] = newPass;

    printf("\nPassword added successfully.\n");
}

void printPasswords(PasswordInfo *passwords, int numPasswords) {
    if (numPasswords == 0) {
        printf("\nNo passwords stored.\n");
        return;
    }

    printf("\nUsername\t\tPassword\n");
    printf("--------------------------------\n");

    for (int i = 0; i < numPasswords; i++) {
        printf("%-20s\t%-20s\n", passwords[i].username, passwords[i].password);
    }
}