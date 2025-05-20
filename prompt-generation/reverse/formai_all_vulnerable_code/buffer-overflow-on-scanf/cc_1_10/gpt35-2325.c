//FormAI DATASET v1.0 Category: Password management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 30
#define MAX_PASSWORDS 10

// Define the password struct
typedef struct {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

// Define the array that will store the passwords
Password passwords[MAX_PASSWORDS];

// Define a variable to keep track of the number of passwords
int numPasswords = 0;

// Function to add a new password
void addPassword() {
    // Make sure we don't exceed the maximum number of passwords
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    Password newPwd;

    // Get input from the user
    printf("Enter website: ");
    fgets(newPwd.website, MAX_PASSWORD_LENGTH, stdin);
    printf("Enter username: ");
    fgets(newPwd.username, MAX_PASSWORD_LENGTH, stdin);

    // Generate a new random password
    char newPassword[MAX_PASSWORD_LENGTH];
    srand(time(NULL));
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        newPassword[i] = rand() % 94 + 33; // Random ASCII character between 33 and 126
    }
    newPassword[MAX_PASSWORD_LENGTH - 1] = '\0'; // Make sure it ends with a null character

    // Copy the new password to the struct
    strncpy(newPwd.password, newPassword, MAX_PASSWORD_LENGTH);

    // Add the new password to the array
    passwords[numPasswords] = newPwd;
    numPasswords++;

    printf("Password added successfully.\n");
}

// Function to print all passwords
void printPasswords() {
    // If we don't have any passwords, print a message and return
    if (numPasswords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Website                   Username                  Password\n");
    printf("===========================================================\n");
    for (int i = 0; i < numPasswords; i++) {
        Password pwd = passwords[i];
        printf("%-25s %-25s %s\n", pwd.website, pwd.username, pwd.password);
    }
}

int main() {
    char choice;

    // Main menu loop
    while (1) {
        printf("\n");
        printf("1. Add password\n");
        printf("2. Print passwords\n");
        printf("3. Exit program\n");
        printf("Enter your choice: ");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addPassword();
                break;
            case '2':
                printPasswords();
                break;
            case '3':
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}