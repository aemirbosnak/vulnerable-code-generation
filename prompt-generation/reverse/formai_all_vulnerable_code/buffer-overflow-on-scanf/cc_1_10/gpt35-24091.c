//FormAI DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct for each password entry
typedef struct {
    char site[50];
    char username[50];
    char password[50];
} PasswordEntry;

// Function to print out an array of PasswordEntries
void printPasswords(PasswordEntry* passwords, int numPasswords) {
    printf("Site\tUsername\tPassword\n");
    printf("=======================================\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\t%s\n", passwords[i].site, passwords[i].username, passwords[i].password);
    }
    printf("\n");
}

// Function to add a new password to the array
void addPassword(PasswordEntry* passwords, int* numPasswords) {
    // Prompt the user for each piece of information
    printf("Enter site name: ");
    char site[50];
    scanf("%s", site);

    printf("Enter username: ");
    char username[50];
    scanf("%s", username);

    printf("Enter password: ");
    char password[50];
    scanf("%s", password);

    // Create the new PasswordEntry
    PasswordEntry newEntry;
    strcpy(newEntry.site, site);
    strcpy(newEntry.username, username);
    strcpy(newEntry.password, password);

    // Add the new entry to the array and increment the count
    passwords[*numPasswords] = newEntry;
    *numPasswords += 1;

    printf("Added new password!\n\n");
}

// Function to remove a password from the array
void removePassword(PasswordEntry* passwords, int* numPasswords) {
    // Prompt the user for the site name of the password to remove
    printf("Enter site name to remove: ");
    char siteToRemove[50];
    scanf("%s", siteToRemove);

    // Find the index of the password to remove
    int indexToRemove = -1;
    for (int i = 0; i < *numPasswords; i++) {
        if (strcmp(passwords[i].site, siteToRemove) == 0) {
            indexToRemove = i;
            break;
        }
    }

    // If the site was not found, print an error message
    if (indexToRemove == -1) {
        printf("Site not found!\n\n");
    } else {
        // Shift all of the passwords after the one to remove back one index
        for (int i = indexToRemove; i < *numPasswords - 1; i++) {
            passwords[i] = passwords[i + 1];
        }

        // Decrement the count
        *numPasswords -= 1;

        printf("Removed password!\n\n");
    }
}

int main() {
    // Initialize an array of PasswordEntries
    PasswordEntry passwords[10];
    int numPasswords = 0;

    // Loop to prompt the user for options
    while (1) {
        printf("Please choose an option:\n");
        printf("1 - Print passwords\n");
        printf("2 - Add password\n");
        printf("3 - Remove password\n");
        printf("0 - Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printPasswords(passwords, numPasswords);
                break;

            case 2:
                addPassword(passwords, &numPasswords);
                break;

            case 3:
                removePassword(passwords, &numPasswords);
                break;

            case 0:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }
}