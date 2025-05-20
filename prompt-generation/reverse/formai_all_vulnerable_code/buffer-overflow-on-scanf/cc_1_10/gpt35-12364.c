//FormAI DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Required for string functions

#define MAX_ENTRIES 100 // Maximum number of password entries

// Struct to represent each password entry
typedef struct PasswordEntry {
    char description[50]; // Description of the password entry
    char username[20]; // Username associated with the entry
    char password[20]; // Encrypted password
} PasswordEntry;

PasswordEntry entries[MAX_ENTRIES]; // Array to store password entries
int numEntries = 0; // Number of current password entries

// Function to encrypt a password using XOR
char* encryptPassword(char* password) {
    int len = strlen(password);
    for (int i = 0; i < len; i++) {
        password[i] ^= 0x5F;
    }
    return password;
}

// Function to add a new password entry
void addEntry() {
    if (numEntries < MAX_ENTRIES) {
        PasswordEntry entry;
        printf("Description: ");
        scanf("%s", entry.description);
        printf("Username: ");
        scanf("%s", entry.username);
        printf("Password: ");
        scanf("%s", entry.password);
        encryptPassword(entry.password); // Encrypt the password before storing
        entries[numEntries] = entry;
        numEntries++;
        printf("Entry added successfully.\n");
    } else {
        printf("Max number of entries reached.\n");
    }
}

// Function to display all password entries
void viewEntries() {
    printf("List of Password Entries:\n");
    printf("| %-15s | %-15s | %-15s |\n", "Description", "Username", "Password");
    printf("+-----------------+-----------------+-----------------+\n");
    for (int i = 0; i < numEntries; i++) {
        PasswordEntry entry = entries[i];
        printf("| %-15s | %-15s | %-15s |\n", entry.description, entry.username, "******");
    }
}

// Function to modify an existing password entry
void modifyEntry() {
    printf("Enter the description of the entry to modify: ");
    char description[50];
    scanf("%s", description);
    PasswordEntry* entryToModify = NULL;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].description, description) == 0) {
            entryToModify = &entries[i];
            break;
        }
    }
    if (entryToModify != NULL) {
        printf("Enter new username (leave blank to keep existing): ");
        char username[20];
        scanf("%s", username);
        if (strlen(username) > 0) {
            strcpy(entryToModify->username, username);
        }
        printf("Enter new password (leave blank to keep existing): ");
        char password[20];
        scanf("%s", password);
        if (strlen(password) > 0) {
            encryptPassword(password);
            strcpy(entryToModify->password, password);
        }
        printf("Entry modified successfully.\n");
    } else {
        printf("Entry not found.\n");
    }
}

// Function to delete an existing password entry
void deleteEntry() {
    printf("Enter the description of the entry to delete: ");
    char description[50];
    scanf("%s", description);
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].description, description) == 0) {
            // Shift all entries after the deleted entry one position to the left
            for (int j = i; j < numEntries - 1; j++) {
                entries[j] = entries[j + 1];
            }
            numEntries--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

// Main function to display the menu options and handle user input
int main() {
    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add new entry\n");
        printf("2. View entries\n");
        printf("3. Modify existing entry\n");
        printf("4. Delete existing entry\n");
        printf("5. Exit\n");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                modifyEntry();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}