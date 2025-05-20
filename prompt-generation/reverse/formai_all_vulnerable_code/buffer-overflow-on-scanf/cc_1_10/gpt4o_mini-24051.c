//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 256

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_PASSWORDS];
int passwordCount = 0;

void encryptDecrypt(char *input) {
    char key = 'K'; // Simple XOR key
    for (int i = 0; input[i] != '\0'; i++) {
        input[i] ^= key;
    }
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password list is full. Cannot add more passwords.\n");
        return;
    }

    PasswordEntry entry;
    printf("Enter service name: ");
    scanf("%s", entry.service);
    printf("Enter username: ");
    scanf("%s", entry.username);
    printf("Enter password: ");
    scanf("%s", entry.password);

    encryptDecrypt(entry.password); // Encrypt password
    passwordList[passwordCount++] = entry;
    printf("Password added successfully!\n");
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("No passwords to display.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < passwordCount; i++) {
        PasswordEntry entry = passwordList[i];
        char decryptedPassword[MAX_LENGTH];
        strcpy(decryptedPassword, entry.password);
        encryptDecrypt(decryptedPassword); // Decrypt password

        printf("Service: %s, Username: %s, Password: %s\n", entry.service, entry.username, decryptedPassword);
    }
}

void deletePassword() {
    if (passwordCount == 0) {
        printf("No passwords to delete.\n");
        return;
    }

    char serviceName[MAX_LENGTH];
    printf("Enter service name to delete: ");
    scanf("%s", serviceName);

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordList[i].service, serviceName) == 0) {
            // Shift entries to remove the deleted one
            for (int j = i; j < passwordCount - 1; j++) {
                passwordList[j] = passwordList[j + 1];
            }
            passwordCount--;
            printf("Password for %s deleted successfully!\n", serviceName);
            return;
        }
    }
    printf("Service not found!\n");
}

void displayMenu() {
    printf("\nPassword Management System\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}