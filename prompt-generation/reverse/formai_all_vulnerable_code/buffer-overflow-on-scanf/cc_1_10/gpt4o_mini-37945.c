//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 128
#define FILENAME "passwords.dat"

typedef struct {
    char service[50];
    char username[50];
    char password[PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry passwords[MAX_PASSWORDS];
int passwordCount = 0;

// Function to display the menu
void displayMenu() {
    printf("\n-- Password Manager --\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Update Password\n");
    printf("4. Delete Password\n");
    printf("5. Save Passwords\n");
    printf("6. Load Passwords\n");
    printf("0. Exit\n");
    printf("--------------------------\n");
    printf("Choose an option: ");
}

// Function to add a new password
void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password storage is full!\n");
        return;
    }

    PasswordEntry newEntry;

    printf("Enter service name: ");
    scanf("%s", newEntry.service);
    printf("Enter username: ");
    scanf("%s", newEntry.username);
    printf("Enter password: ");
    scanf("%s", newEntry.password);

    passwords[passwordCount++] = newEntry;
    printf("Password for %s added successfully!\n", newEntry.service);
}

// Function to view passwords
void viewPasswords() {
    printf("\nStored Passwords:\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("%d. Service: %s | Username: %s | Password: %s\n",
               i + 1, passwords[i].service, passwords[i].username, passwords[i].password);
    }
}

// Function to update a password
void updatePassword() {
    int index;
    printf("Enter the index of the password to update: ");
    scanf("%d", &index);

    if (index < 1 || index > passwordCount) {
        printf("Invalid index!\n");
        return;
    }

    PasswordEntry *entry = &passwords[index - 1];

    printf("Updating password for service: %s\n", entry->service);
    printf("Enter new password: ");
    scanf("%s", entry->password);
    printf("Password updated successfully!\n");
}

// Function to delete a password
void deletePassword() {
    int index;
    printf("Enter the index of the password to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > passwordCount) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < passwordCount - 1; i++) {
        passwords[i] = passwords[i + 1];
    }
    passwordCount--;
    printf("Password deleted successfully!\n");
}

// Function to save passwords to a file
void savePasswords() {
    FILE *file = fopen(FILENAME, "wb");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    fwrite(passwords, sizeof(PasswordEntry), passwordCount, file);
    fclose(file);
    printf("Passwords saved to %s successfully!\n", FILENAME);
}

// Function to load passwords from a file
void loadPasswords() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        printf("Error opening file for reading!\n");
        return;
    }
    passwordCount = fread(passwords, sizeof(PasswordEntry), MAX_PASSWORDS, file);
    fclose(file);
    printf("Passwords loaded from %s successfully!\n", FILENAME);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPassword(); break;
            case 2: viewPasswords(); break;
            case 3: updatePassword(); break;
            case 4: deletePassword(); break;
            case 5: savePasswords(); break;
            case 6: loadPasswords(); break;
            case 0: 
                printf("Exiting... Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}