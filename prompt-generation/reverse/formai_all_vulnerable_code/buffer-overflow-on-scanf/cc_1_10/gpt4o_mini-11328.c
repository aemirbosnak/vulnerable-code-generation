//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 256
#define COMMAND_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

typedef struct {
    PasswordEntry entries[MAX_PASSWORDS];
    int count;
} PasswordManager;

void initializePasswordManager(PasswordManager *manager) {
    manager->count = 0;
}

void addPassword(PasswordManager *manager) {
    if (manager->count >= MAX_PASSWORDS) {
        printf("Error: Maximum password limit reached!\n");
        return;
    }

    PasswordEntry newEntry;
    printf("Enter a name for the password: ");
    scanf("%s", newEntry.name);
    printf("Enter the password: ");
    scanf("%s", newEntry.password);

    manager->entries[manager->count] = newEntry;
    manager->count++;
    printf("Password for %s added successfully.\n", newEntry.name);
}

void viewPasswords(PasswordManager *manager) {
    if (manager->count == 0) {
        printf("No passwords stored yet.\n");
        return;
    }

    printf("Stored Passwords:\n");
    for (int i = 0; i < manager->count; i++) {
        printf("%d. %s\n", i + 1, manager->entries[i].name);
    }
}

void deletePassword(PasswordManager *manager) {
    int index;
    printf("Enter the number of the password to delete: ");
    scanf("%d", &index);
    index--; // Adjust for zero-indexing

    if (index < 0 || index >= manager->count) {
        printf("Error: Invalid password number.\n");
        return;
    }

    for (int i = index; i < manager->count - 1; i++) {
        manager->entries[i] = manager->entries[i + 1];
    }
    manager->count--;
    printf("Password deleted successfully.\n");
}

void searchPassword(PasswordManager *manager) {
    char name[MAX_LENGTH];
    printf("Enter the name of the password to search: ");
    scanf("%s", name);

    for (int i = 0; i < manager->count; i++) {
        if (strcasecmp(manager->entries[i].name, name) == 0) {
            printf("Found password for %s: %s\n", name, manager->entries[i].password);
            return;
        }
    }
    printf("No password found for %s.\n", name);
}

void securelyClearTerminal() {
    printf("\033[H\033[J"); // ANSI escape code to clear terminal
    printf("Terminal Cleared! You are now in a secure environment.\n");
}

void displayMenu() {
    printf("\n--- Futuristic Password Manager ---\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Search Password\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    PasswordManager manager;
    initializePasswordManager(&manager);
    int choice;

    while (1) {
        securelyClearTerminal();
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword(&manager);
                break;
            case 2:
                viewPasswords(&manager);
                break;
            case 3:
                deletePassword(&manager);
                break;
            case 4:
                searchPassword(&manager);
                break;
            case 5:
                printf("Exiting the Password Manager. Stay Secure!\n");
                return 0;
            default:
                printf("Error: Invalid choice. Please select again.\n");
        }
        printf("Press Enter to continue...\n");
        getchar(); // Clear the newline before waiting for input
        getchar(); // Wait for user to press Enter
    }
    return 0;
}