//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 50
#define FILENAME "passwords.txt"

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_ENTRIES];
int entryCount = 0;

void loadPasswords() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return; // No saved passwords
    }
    
    while (fscanf(file, "%s %s %s",
                  passwordList[entryCount].website,
                  passwordList[entryCount].username,
                  passwordList[entryCount].password) != EOF) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) {
            break; // Prevent overflow
        }
    }
    fclose(file);
}

void savePasswords() {
    FILE *file = fopen(FILENAME, "w");
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s %s %s\n",
                passwordList[i].website,
                passwordList[i].username,
                passwordList[i].password);
    }
    fclose(file);
}

void addPassword() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Password list is full!\n");
        return;
    }

    printf("Enter website: ");
    scanf("%s", passwordList[entryCount].website);
    printf("Enter username: ");
    scanf("%s", passwordList[entryCount].username);
    printf("Enter password: ");
    scanf("%s", passwordList[entryCount].password);
    
    entryCount++;
    printf("Password entry added successfully!\n");
}

void viewPasswords() {
    if (entryCount == 0) {
        printf("No passwords stored.\n");
        return;
    }
    
    printf("\nStored Passwords:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Website: %s, Username: %s, Password: %s\n", 
               passwordList[i].website, 
               passwordList[i].username, 
               passwordList[i].password);
    }
}

void deletePassword() {
    char website[MAX_LENGTH];
    printf("Enter website to delete: ");
    scanf("%s", website);
    
    int i, found = 0;
    for (i = 0; i < entryCount; i++) {
        if (strcmp(passwordList[i].website, website) == 0) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        for (int j = i; j < entryCount - 1; j++) {
            passwordList[j] = passwordList[j + 1];
        }
        entryCount--;
        printf("Password entry for %s deleted successfully!\n", website);
    } else {
        printf("No entry found for %s.\n", website);
    }
}

void displayMenu() {
    printf("\n=== Password Manager ===\n");
    printf("1. Add a password\n");
    printf("2. View all passwords\n");
    printf("3. Delete a password\n");
    printf("4. Exit\n");
    printf("========================\n");
    printf("Select an option: ");
}

int main() {
    loadPasswords();
    
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPassword();
                savePasswords();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                deletePassword();
                savePasswords();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}