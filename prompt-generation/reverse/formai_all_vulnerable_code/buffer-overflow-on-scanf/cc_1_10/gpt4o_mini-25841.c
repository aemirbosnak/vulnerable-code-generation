//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

typedef struct {
    char site[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_PASSWORDS];
int entryCount = 0;

void loadPasswords();
void savePasswords();
void addPassword();
void viewPasswords();
void deletePassword();
void clearInputBuffer();

int main() {
    int choice;

    loadPasswords();
    
    do {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                printf("Exiting the Password Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void loadPasswords() {
    FILE *file = fopen("passwords.txt", "r");
    if (!file) {
        printf("No saved passwords found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%49s %49s %49s", 
           passwordList[entryCount].site, 
           passwordList[entryCount].username, 
           passwordList[entryCount].password) == 3) {
        entryCount++;
    }

    fclose(file);
}

void savePasswords() {
    FILE *file = fopen("passwords.txt", "w");
    if (!file) {
        printf("Error saving passwords.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s %s %s\n", 
                passwordList[i].site, 
                passwordList[i].username, 
                passwordList[i].password);
    }

    fclose(file);
}

void addPassword() {
    if (entryCount >= MAX_PASSWORDS) {
        printf("Password storage is full. Can't add more.\n");
        return;
    }

    printf("Enter site: ");
    fgets(passwordList[entryCount].site, MAX_LENGTH, stdin);
    passwordList[entryCount].site[strcspn(passwordList[entryCount].site, "\n")] = 0; // strip newline

    printf("Enter username: ");
    fgets(passwordList[entryCount].username, MAX_LENGTH, stdin);
    passwordList[entryCount].username[strcspn(passwordList[entryCount].username, "\n")] = 0; // strip newline

    printf("Enter password: ");
    fgets(passwordList[entryCount].password, MAX_LENGTH, stdin);
    passwordList[entryCount].password[strcspn(passwordList[entryCount].password, "\n")] = 0; // strip newline

    entryCount++;
    savePasswords();
    printf("Password added successfully!\n");
}

void viewPasswords() {
    if (entryCount == 0) {
        printf("No passwords saved yet.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Site: %s, Username: %s, Password: %s\n", 
                passwordList[i].site, 
                passwordList[i].username, 
                passwordList[i].password);
    }
}

void deletePassword() {
    if (entryCount == 0) {
        printf("No passwords to delete.\n");
        return;
    }

    char siteToDelete[MAX_LENGTH];
    printf("Enter the site of the password to delete: ");
    fgets(siteToDelete, MAX_LENGTH, stdin);
    siteToDelete[strcspn(siteToDelete, "\n")] = 0; // strip newline

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordList[i].site, siteToDelete) == 0) {
            // Shift remaining entries
            for (int j = i; j < entryCount - 1; j++) {
                passwordList[j] = passwordList[j + 1];
            }
            entryCount--;
            savePasswords();
            printf("Password for %s deleted successfully!\n", siteToDelete);
            return;
        }
    }
    printf("No password found for the site: %s\n", siteToDelete);
}

void clearInputBuffer() {
    while (getchar() != '\n'); // clear the input buffer
}