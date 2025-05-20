//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define PASSWORD_LENGTH 100
#define FILENAME "passwords.txt"

typedef struct {
    char website[50];
    char username[50];
    char password[PASSWORD_LENGTH];
} PasswordEntry;

void encrypt(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] += 3; // Simple Caesar cipher
    }
}

void decrypt(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] -= 3; // Simple Caesar cipher
    }
}

void loadPasswords(PasswordEntry *entries, int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        *count = 0;
        return;
    }
    
    while (fscanf(file, "%s %s %s", entries[*count].website, entries[*count].username, entries[*count].password) != EOF) {
        decrypt(entries[*count].password);
        (*count)++;
    }
    fclose(file);
}

void savePassword(const PasswordEntry *entry) {
    FILE *file = fopen(FILENAME, "a");
    if (file) {
        char encryptedPassword[PASSWORD_LENGTH];
        strcpy(encryptedPassword, entry->password);
        encrypt(encryptedPassword);
        fprintf(file, "%s %s %s\n", entry->website, entry->username, encryptedPassword);
        fclose(file);
    } else {
        printf("Error opening file for writing!\n");
    }
}

void listPasswords(const PasswordEntry *entries, int count) {
    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Website: %s, Username: %s, Password: %s\n", entries[i].website, entries[i].username, entries[i].password);
    }
}

void deletePassword(const char *website, PasswordEntry *entries, int *count) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            found = 1;
        }
        if (found && i < *count - 1) {
            entries[i] = entries[i + 1];
        }
    }
    if (found) {
        (*count)--;
        printf("Password for %s has been deleted.\n", website);
    } else {
        printf("No entry found for %s.\n", website);
    }
}

void displayMenu() {
    printf("\nPassword Management System\n");
    printf("1. Add Password\n");
    printf("2. List Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
}

int main() {
    PasswordEntry entries[MAX_ENTRIES];
    int count = 0;
    loadPasswords(entries, &count);

    while (1) {
        displayMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            PasswordEntry newEntry;
            printf("Enter website: ");
            scanf("%s", newEntry.website);
            printf("Enter username: ");
            scanf("%s", newEntry.username);
            printf("Enter password: ");
            scanf("%s", newEntry.password);
            savePassword(&newEntry);
            entries[count++] = newEntry; // Also add to in-memory list
            printf("Password saved successfully.\n");
        } else if (choice == 2) {
            listPasswords(entries, count);
        } else if (choice == 3) {
            char website[50];
            printf("Enter website to delete: ");
            scanf("%s", website);
            deletePassword(website, entries, &count);
        } else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}