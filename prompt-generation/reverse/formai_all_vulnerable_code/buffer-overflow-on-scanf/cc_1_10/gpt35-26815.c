//FormAI DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 15  // Maximum password length
#define NUM_PASSWORDS 3      // Maximum number of passwords to manage

// Structure to hold password information
typedef struct {
    char website[50];
    char username[50];
    char password[PASSWORD_LENGTH+1];
} Password;

// Function to add a password to the list
void addPassword(Password passwords[], int* numPasswords) {
    if (*numPasswords < NUM_PASSWORDS) {
        printf("Enter website: ");
        scanf("%s", passwords[*numPasswords].website);
        printf("Enter username: ");
        scanf("%s", passwords[*numPasswords].username);
        printf("Enter password (max 15 characters): ");
        scanf("%s", passwords[*numPasswords].password);
        (*numPasswords)++;
        printf("Password added.\n\n");
    } else {
        printf("Cannot add another password. Maximum number of passwords reached.\n\n");
    }
}

// Function to display all passwords
void displayPasswords(Password passwords[], int numPasswords) {
    if (numPasswords == 0) {
        printf("No passwords currently stored.\n\n");
    } else {
        printf("WEBSITE\t\tUSERNAME\t\tPASSWORD\n");
        printf("-----------------------------------------------------\n");
        for (int i = 0; i < numPasswords; i++) {
            printf("%s\t\t%s\t\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
        }
        printf("\n");
    }
}

// Function to search for a password by website name
void searchPassword(Password passwords[], int numPasswords) {
    char website[50];
    int found = 0;
    printf("Enter website to search for: ");
    scanf("%s", website);
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            printf("WEBSITE\t\tUSERNAME\t\tPASSWORD\n");
            printf("-----------------------------------------------------\n");
            printf("%s\t\t%s\t\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Password not found.\n\n");
    }
}

// Function to update an existing password
void updatePassword(Password passwords[], int numPasswords) {
    char website[50];
    int found = 0;
    printf("Enter website of password to update: ");
    scanf("%s", website);
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            printf("Enter new website (or press enter to keep current): ");
            scanf("%s", passwords[i].website);
            printf("Enter new username (or press enter to keep current): ");
            scanf("%s", passwords[i].username);
            printf("Enter new password (or press enter to keep current): ");
            scanf("%s", passwords[i].password);
            found = 1;
            printf("Password updated.\n\n");
            break;
        }
    }
    if (!found) {
        printf("Password not found.\n\n");
    }
}

// Function to remove an existing password
void removePassword(Password passwords[], int* numPasswords) {
    char website[50];
    int found = 0;
    printf("Enter website of password to remove: ");
    scanf("%s", website);
    for (int i = 0; i < *numPasswords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            for (int j = i; j < (*numPasswords)-1; j++) {
                passwords[j] = passwords[j+1];
            }
            (*numPasswords)--;
            found = 1;
            printf("Password removed.\n\n");
            break;
        }
    }
    if (!found) {
        printf("Password not found.\n\n");
    }
}

// Function to clear all passwords
void clearPasswords(Password passwords[], int* numPasswords) {
    *numPasswords = 0;
    printf("Passwords cleared.\n\n");
}

// Function to prompt user for menu selection
int menu() {
    int choice = 0;
    printf("1. Add password\n");
    printf("2. Display all passwords\n");
    printf("3. Search for password\n");
    printf("4. Update password\n");
    printf("5. Remove password\n");
    printf("6. Clear all passwords\n");
    printf("7. Quit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

int main() {
    Password passwords[NUM_PASSWORDS];
    int numPasswords = 0;
    int choice = 0;
    while (choice != 7) {
        choice = menu();
        switch (choice) {
            case 1:
                addPassword(passwords, &numPasswords);
                break;
            case 2:
                displayPasswords(passwords, numPasswords);
                break;
            case 3:
                searchPassword(passwords, numPasswords);
                break;
            case 4:
                updatePassword(passwords, numPasswords);
                break;
            case 5:
                removePassword(passwords, &numPasswords);
                break;
            case 6:
                clearPasswords(passwords, &numPasswords);
                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}