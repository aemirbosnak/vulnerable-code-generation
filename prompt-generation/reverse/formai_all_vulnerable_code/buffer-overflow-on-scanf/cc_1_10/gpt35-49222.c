//FormAI DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximum password length
#define MAX_PASSWORD_LENGTH 50

// maximum number of passwords that can be stored
#define MAX_PASSWORDS 10

// structure to hold passwords
struct Password {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// function to print a password
void printPassword(struct Password pass) {
    printf("Website: %s\n", pass.website);
    printf("Username: %s\n", pass.username);
    printf("Password: %s\n", pass.password);
}

// function to add a new password
void addPassword(struct Password passwords[], int *numPasswords) {
    // check if maximum number of passwords have already been stored
    if (*numPasswords >= MAX_PASSWORDS) {
        printf("Sorry, you can only store up to %d passwords.\n", MAX_PASSWORDS);
        return;
    }
    
    struct Password newPass; // create a new password object
    
    // get user input for the website, username, and password
    printf("Enter the website: ");
    scanf("%s", newPass.website);
    printf("Enter the username: ");
    scanf("%s", newPass.username);
    printf("Enter the password: ");
    scanf("%s", newPass.password);

    passwords[*numPasswords] = newPass; // add the new password to the list
    (*numPasswords)++; // increment the number of stored passwords

    printf("Password stored successfully.\n\n");
}

// function to view all stored passwords
void viewPasswords(struct Password passwords[], int numPasswords) {
    // check if any passwords have been stored
    if (numPasswords == 0) {
        printf("No passwords have been stored.\n\n");
        return;
    }

    // loop through all stored passwords and print them
    printf("All stored passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("\nPassword %d:\n", i+1);
        printPassword(passwords[i]);
    }
    printf("\n");
}

int main() {
    struct Password passwords[MAX_PASSWORDS]; // array to hold stored passwords
    int numPasswords = 0; // counter for number of stored passwords
    int choice; // user menu choice

    // loop until user chooses to exit
    do {
        printf("--------Password Manager--------\n");
        printf("1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addPassword(passwords, &numPasswords);
                break;
            case 2:
                viewPasswords(passwords, numPasswords);
                break;
            case 3:
                printf("Goodbye!\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}