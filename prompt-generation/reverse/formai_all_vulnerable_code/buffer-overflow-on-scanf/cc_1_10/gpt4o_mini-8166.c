//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Credentials;

void encryptPassword(const char *password, char *encrypted) {
    for (int i = 0; password[i] != '\0'; i++) {
        encrypted[i] = password[i] + 3; // Simple encryption by shifting characters
    }
    encrypted[strlen(password)] = '\0'; // Null-terminate the encrypted string
}

void decryptPassword(const char *encrypted, char *decrypted) {
    for (int i = 0; encrypted[i] != '\0'; i++) {
        decrypted[i] = encrypted[i] - 3; // Reverse the encryption
    }
    decrypted[strlen(encrypted)] = '\0'; // Null-terminate the decrypted string
}

void addEntry(Credentials *creds, int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Maximum number of entries reached! Can't add more passwords.\n");
        return;
    }
    
    printf("Adding a new entry...\n");
    printf("Enter Username: ");
    scanf("%s", creds[*count].username);
    
    printf("Enter Password: ");
    char password[MAX_LENGTH];
    scanf("%s", password);
    
    encryptPassword(password, creds[*count].password);
    (*count)++;
    printf("Entry added successfully!\n\n");
}

void viewEntries(Credentials *creds, int count) {
    printf("Viewing all stored passwords:\n");
    for (int i = 0; i < count; i++) {
        char decrypted[MAX_LENGTH];
        decryptPassword(creds[i].password, decrypted);
        printf("Username: %s, Password: %s\n", creds[i].username, decrypted);
    }
    printf("\n");
}

void deleteEntry(Credentials *creds, int *count) {
    if (*count == 0) {
        printf("No entries to delete!\n");
        return;
    }
    
    printf("Enter the username of the entry to delete: ");
    char username[MAX_LENGTH];
    scanf("%s", username);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(creds[i].username, username) == 0) {
            // Shift the rest of the entries left
            for (int j = i; j < *count - 1; j++) {
                creds[j] = creds[j + 1];
            }
            (*count)--;
            printf("Entry deleted successfully!\n\n");
            return;
        }
    }
    printf("Entry not found!\n\n");
}

void showMenu() {
    printf("=== Welcome to the Password Manager ===\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
    printf("=======================================\n");
}

int main() {
    Credentials creds[MAX_ENTRIES];
    int count = 0;
    int choice;
    
    while (1) {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry(creds, &count);
                break;
            case 2:
                viewEntries(creds, count);
                break;
            case 3:
                deleteEntry(creds, &count);
                break;
            case 4:
                printf("Exiting the Password Manager. Stay secure!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }
    
    return 0;
}