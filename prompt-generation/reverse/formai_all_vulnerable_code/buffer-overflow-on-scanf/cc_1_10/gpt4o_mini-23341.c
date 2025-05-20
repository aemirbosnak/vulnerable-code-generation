//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char website[256];
    char username[256];
    char password[PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry passwordManager[MAX_PASSWORDS];
int entryCount = 0;

// Function prototypes
void addEntry();
void viewEntries();
void deleteEntry();
void encryptPassword(char *password, const char *key);
void decryptPassword(char *password, const char *key);
void displayMenu();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
    return 0;
}

void displayMenu() {
    printf("\n=== Password Manager ===\n");
    printf("1. Add Password Entry\n");
    printf("2. View All Passwords\n");
    printf("3. Delete Password Entry\n");
    printf("4. Exit\n");
}

void addEntry() {
    if (entryCount >= MAX_PASSWORDS) {
        printf("Password manager is full, cannot add more entries.\n");
        return;
    }
    PasswordEntry newEntry;
    char key[16];
    
    printf("Enter website: ");
    getchar(); // Clear the newline character from the buffer
    fgets(newEntry.website, sizeof(newEntry.website), stdin);
    newEntry.website[strcspn(newEntry.website, "\n")] = 0; // Remove newline

    printf("Enter username: ");
    fgets(newEntry.username, sizeof(newEntry.username), stdin);
    newEntry.username[strcspn(newEntry.username, "\n")] = 0; // Remove newline

    printf("Enter password: ");
    fgets(newEntry.password, sizeof(newEntry.password), stdin);
    newEntry.password[strcspn(newEntry.password, "\n")] = 0; // Remove newline

    // Encrypt password before storing
    printf("Enter encryption key (max 15 characters): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline

    encryptPassword(newEntry.password, key);
    passwordManager[entryCount++] = newEntry;
    printf("Password entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No password entries available.\n");
        return;
    }
    printf("\n=== Stored Passwords ===\n");
    for (int i = 0; i < entryCount; i++) {
        char decryptedPassword[PASSWORD_LENGTH];
        strcpy(decryptedPassword, passwordManager[i].password);
        // Assume a static key for decryption, for simplicity
        decryptPassword(decryptedPassword, "default_key");
        printf("Website: %s\n", passwordManager[i].website);
        printf("Username: %s\n", passwordManager[i].username);
        printf("Password: %s\n", decryptedPassword);
        printf("-------------------------\n");
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No passwords to delete.\n");
        return;
    }
    char website[256];
    printf("Enter the website of the entry to delete: ");
    getchar(); // Clear the newline character from the buffer
    fgets(website, sizeof(website), stdin);
    website[strcspn(website, "\n")] = 0; // Remove newline

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordManager[i].website, website) == 0) {
            for (int j = i; j < entryCount - 1; j++) {
                passwordManager[j] = passwordManager[j + 1];
            }
            entryCount--;
            printf("Password entry deleted successfully!\n");
            return;
        }
    }
    printf("No entry found for the specified website.\n");
}

void encryptPassword(char *password, const char *key) {
    for (int i = 0; password[i] && key[i % strlen(key)]; i++) {
        password[i] = password[i] ^ key[i % strlen(key)];
    }
}

void decryptPassword(char *password, const char *key) {
    // Decryption is symmetric to encryption
    encryptPassword(password, key); 
}