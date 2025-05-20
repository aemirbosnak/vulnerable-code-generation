//FormAI DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_SIZE 50
#define MAX_NUM_OF_PASSWORDS 10

// Structure for a single password entry
struct PasswordEntry {
    char website[50];
    char username[50];
    char password[MAX_PASSWORD_SIZE];
};

// Structure for the password manager
struct PasswordManager {
    struct PasswordEntry passwordEntries[MAX_NUM_OF_PASSWORDS];
    int numEntries;
};

// Function to add a new password entry
void addPasswordEntry(struct PasswordManager *pm) {
    if (pm->numEntries >= MAX_NUM_OF_PASSWORDS) {
        printf("Error: Maximum number of password entries reached.\n");
        return;
    }
    
    struct PasswordEntry newEntry;
    printf("Enter website: ");
    fgets(newEntry.website, sizeof(newEntry.website), stdin);
    newEntry.website[strlen(newEntry.website) - 1] = '\0'; // Remove '\n' character
    
    printf("Enter username: ");
    fgets(newEntry.username, sizeof(newEntry.username), stdin);
    newEntry.username[strlen(newEntry.username) - 1] = '\0'; // Remove '\n' character
    
    printf("Enter password: ");
    fgets(newEntry.password, sizeof(newEntry.password), stdin);
    newEntry.password[strlen(newEntry.password) - 1] = '\0'; // Remove '\n' character
    
    pm->passwordEntries[pm->numEntries++] = newEntry;
    
    printf("Password added successfully!\n");
}

// Function to find a password entry by website name
void findPasswordEntry(struct PasswordManager *pm) {
    char website[50];
    printf("Enter website: ");
    fgets(website, sizeof(website), stdin);
    website[strlen(website) - 1] = '\0'; // Remove '\n' character
    
    for (int i = 0; i < pm->numEntries; i++) {
        if (strcmp(pm->passwordEntries[i].website, website) == 0) {
            printf("Website: %s\n", pm->passwordEntries[i].website);
            printf("Username: %s\n", pm->passwordEntries[i].username);
            printf("Password: %s\n", pm->passwordEntries[i].password);
            return;
        }
    }
    
    printf("Error: Website not found.\n");
}

// Function to change a password
void changePassword(struct PasswordManager *pm) {
    char website[50];
    printf("Enter website: ");
    fgets(website, sizeof(website), stdin);
    website[strlen(website) - 1] = '\0'; // Remove '\n' character
    
    for (int i = 0; i < pm->numEntries; i++) {
        if (strcmp(pm->passwordEntries[i].website, website) == 0) {
            printf("Enter current password: ");
            char currentPassword[MAX_PASSWORD_SIZE];
            fgets(currentPassword, sizeof(currentPassword), stdin);
            currentPassword[strlen(currentPassword) - 1] = '\0'; // Remove '\n' character
            
            if (strcmp(pm->passwordEntries[i].password, currentPassword) == 0) {
                printf("Enter new password: ");
                fgets(pm->passwordEntries[i].password, sizeof(pm->passwordEntries[i].password), stdin);
                pm->passwordEntries[i].password[strlen(pm->passwordEntries[i].password) - 1] = '\0'; // Remove '\n' character
                
                printf("Password changed successfully!\n");
                return;
            } else {
                printf("Error: Incorrect password.\n");
                return;
            }
        }
    }
    
    printf("Error: Website not found.\n");
}

// Function to print all password entries
void printPasswordEntries(struct PasswordManager *pm) {
    printf("--------------------\n");
    printf("Current Passwords:\n");
    printf("--------------------\n");
    
    for (int i = 0; i < pm->numEntries; i++) {
        printf("Website: %s\n", pm->passwordEntries[i].website);
        printf("Username: %s\n", pm->passwordEntries[i].username);
        printf("Password: %s\n", pm->passwordEntries[i].password);
        printf("--------------------\n");
    }
}

// Function to clear all password entries
void clearPasswordEntries(struct PasswordManager *pm) {
    memset(pm, 0, sizeof(struct PasswordManager));
    printf("All password entries cleared successfully!\n");
}

// Main function
int main() {
    struct PasswordManager pm;
    pm.numEntries = 0;
    
    while (1) {
        printf("Enter choice:\n");
        printf("1. Add password entry\n");
        printf("2. Find password entry\n");
        printf("3. Change password\n");
        printf("4. Print all password entries\n");
        printf("5. Clear all password entries\n");
        printf("6. Exit\n");
        
        char input[10];
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0'; // Remove '\n' character
        
        if (strlen(input) != 1 || !isdigit(input[0])) {
            printf("Error: Invalid choice.\n");
            continue;
        }
        
        int choice = input[0] - '0';
        
        switch (choice) {
            case 1:
                addPasswordEntry(&pm);
                break;
            case 2:
                findPasswordEntry(&pm);
                break;
            case 3:
                changePassword(&pm);
                break;
            case 4:
                printPasswordEntries(&pm);
                break;
            case 5:
                clearPasswordEntries(&pm);
                break;
            case 6:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Error: Invalid choice.\n");
                break;
        }
    }
}