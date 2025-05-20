//FormAI DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LENGTH 20 // Maximum Password Length
#define MAX_USERNAME_LENGTH 20 // Maximum Username Length
#define MAX_ENTRIES 100 // Maximum Entries

// Password Structure
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASS_LENGTH];
} Password;

// Keep track of the number of entries added
int entryCount = 0;

// Global Password array to store all entries
Password passwordEntries[MAX_ENTRIES];

// Function to add a new password entry
void addPasswordEntry() {
    // Verify that adding a new entry won't exceed the maximum
    if (entryCount < MAX_ENTRIES) {
        Password newEntry;

        printf("Enter the username (20 characters max): ");
        scanf("%s", newEntry.username);

        printf("Enter the password (20 characters max): ");
        scanf("%s", newEntry.password);

        passwordEntries[entryCount++] = newEntry;

        printf("Password Entry added successfully!\n");
    } else {
        printf("Maximum number of entries reached, cannot add another entry.\n");
    }
}

// Function to display all password entries
void displayPasswordEntries() {
    if (entryCount > 0) {
        printf("Here are all of your saved Passwords:\n");
        for (int i = 0; i < entryCount; i++) {
            printf("Username: %s, Password: %s\n", passwordEntries[i].username, passwordEntries[i].password);
        }
    } else {
        printf("No saved Passwords to display.\n");
    }
}

// Function to find a password entry by username
void findPasswordEntry() {
    char searchUsername[MAX_USERNAME_LENGTH];

    printf("Enter the username to find: ");
    scanf("%s", searchUsername);

    int foundEntry = 0;

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordEntries[i].username, searchUsername) == 0) {
            printf("Username: %s, Password: %s\n", passwordEntries[i].username, passwordEntries[i].password);
            foundEntry = 1;
        }
    }

    if (!foundEntry) {
        printf("No password entry found for that username.\n");
    }
}

int main()
{
    int choice;
    while (1) {
        
        printf("1. Add Password Entry\n");
        printf("2. Display all Password Entries\n");
        printf("3. Find Password Entry\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPasswordEntry();
                break;
            case 2:
                displayPasswordEntries();
                break;
            case 3:
                findPasswordEntry();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}