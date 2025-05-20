//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 256
#define HASH_LENGTH 64
#define FILENAME "passwords.txt"

// Structure to hold password information
typedef struct {
    char name[50];
    char password[HASH_LENGTH];
} PasswordEntry;

// Function prototypes
void addPassword(PasswordEntry *entries, int *count);
void viewPasswords(PasswordEntry *entries, int count);
void deletePassword(PasswordEntry *entries, int *count);
void savePasswords(PasswordEntry *entries, int count);
void loadPasswords(PasswordEntry *entries, int *count);
void hashPassword(const char *password, char *hashed);
void printHash(const char *label, const char *hash);

int main() {
    PasswordEntry entries[MAX_PASSWORDS];
    int count = 0;
    loadPasswords(entries, &count);
    
    int choice;
    do {
        printf("\n=== Password Manager ===\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character
        
        switch (choice) {
            case 1:
                addPassword(entries, &count);
                savePasswords(entries, count);
                break;
            case 2:
                viewPasswords(entries, count);
                break;
            case 3:
                deletePassword(entries, &count);
                savePasswords(entries, count);
                break;
            case 4:
                printf("Exiting... Thank you for using the password manager!\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void addPassword(PasswordEntry *entries, int *count) {
    if (*count >= MAX_PASSWORDS) {
        printf("Password storage is full. Cannot add more passwords.\n");
        return;
    }
    
    PasswordEntry newEntry;
    printf("Enter the name for the password: ");
    fgets(newEntry.name, sizeof(newEntry.name), stdin);
    newEntry.name[strcspn(newEntry.name, "\n")] = 0; // Remove newline

    printf("Enter the password: ");
    char password[PASSWORD_LENGTH];
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline
    
    hashPassword(password, newEntry.password);
    entries[*count] = newEntry;
    (*count)++;
    printf("Password for '%s' added successfully.\n", newEntry.name);
}

void viewPasswords(PasswordEntry *entries, int count) {
    if (count == 0) {
        printf("No passwords stored.\n");
        return;
    }
    
    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s | Password Hash: %s\n", entries[i].name, entries[i].password);
    }
}

void deletePassword(PasswordEntry *entries, int *count) {
    if (*count == 0) {
        printf("No passwords to delete.\n");
        return;
    }
    
    char name[50];
    printf("Enter the name of the password to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Deleting password for '%s'.\n", entries[i].name);
            for (int j = i; j < *count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            (*count)--;
            return;
        }
    }
    printf("Password for '%s' not found.\n", name);
}

void savePasswords(PasswordEntry *entries, int count) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error saving passwords.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s|%s\n", entries[i].name, entries[i].password);
    }
    
    fclose(file);
}

void loadPasswords(PasswordEntry *entries, int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        return; // File might not exist on first run
    }
    
    char line[300];
    while (fgets(line, sizeof(line), file) && *count < MAX_PASSWORDS) {
        char *token = strtok(line, "|");
        if (token) {
            strcpy(entries[*count].name, token);
            token = strtok(NULL, "|");
            if (token) {
                strcpy(entries[*count].password, token);
                entries[*count].password[strcspn(entries[*count].password, "\n")] = 0; // Remove newline
                (*count)++;
            }
        }
    }
    
    fclose(file);
}

void hashPassword(const char *password, char *hashed) {
    unsigned long hash = 5381;
    int c;

    while ((c = *password++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    sprintf(hashed, "%lu", hash); // Store the hash as a string
    printHash("Generated Hash", hashed);
}

void printHash(const char *label, const char *hash) {
    printf("%s: %s\n", label, hash);
}