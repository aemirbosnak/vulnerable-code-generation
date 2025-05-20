//FormAI DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

// Struct for storing password data
typedef struct {
    char website[50];
    char username[20];
    char password[PASSWORD_LENGTH];
} PasswordEntry;

// Global variables
PasswordEntry passwords[MAX_PASSWORDS];
int numPasswords = 0;

// Function prototypes
void addPassword();
void listPasswords();
void deletePassword();
void changePassword();

// Main function
int main() {
    int choice;

    // Loop until user chooses to exit
    while(1) {
        printf("\n--- Password Manager ---\n");
        printf("1. Add new password\n");
        printf("2. List passwords\n");
        printf("3. Delete password\n");
        printf("4. Change password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                listPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                changePassword();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

// Function to add a new password
void addPassword() {
    // Check if there are too many passwords already
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Password capacity has been reached.\n");
        return;
    }

    // Get user input for password data
    printf("Enter website: ");
    scanf("%s", passwords[numPasswords].website);
    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);
    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    // Increment number of passwords stored
    numPasswords++;
}

// Function to list all passwords
void listPasswords() {
    // Check if there are no passwords stored
    if (numPasswords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("Website\t\tUsername\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t\t%s\t\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

// Function to delete a password
void deletePassword() {
    // Check if there are no passwords stored
    if (numPasswords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    char website[50];
    printf("Enter website to delete: ");
    scanf("%s", website);

    // Find password and remove it
    int found = 0;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            for (int j = i; j < numPasswords-1; j++) {
                passwords[j] = passwords[j+1];
            }
            numPasswords--;
            printf("Password for %s deleted.\n", website);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Password for %s not found.\n", website);
    }
}

// Function to change a password
void changePassword() {
    // Check if there are no passwords stored
    if (numPasswords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    char website[50];
    printf("Enter website to change password: ");
    scanf("%s", website);

    // Find password and change it
    int found = 0;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            printf("Enter new password: ");
            scanf("%s", passwords[i].password);
            printf("Password for %s changed.\n", website);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Password for %s not found.\n", website);
    }
}