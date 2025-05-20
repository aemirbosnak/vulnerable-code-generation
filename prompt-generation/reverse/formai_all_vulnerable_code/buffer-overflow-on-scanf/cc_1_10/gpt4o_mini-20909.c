//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 256

typedef struct {
    char site[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_PASSWORDS];
int totalPasswords = 0;

void addPassword();
void displayPasswords();
void removePassword();
void showMenu();
int findPasswordIndex(const char *site);

int main() {
    int choice;
    
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                removePassword();
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void showMenu() {
    printf("\n--- Password Manager ---\n");
    printf("1. Add Password\n");
    printf("2. Display Passwords\n");
    printf("3. Remove Password\n");
    printf("4. Exit\n");
}

void addPassword() {
    if (totalPasswords >= MAX_PASSWORDS) {
        printf("Password list is full. Cannot add more passwords.\n");
        return;
    }

    PasswordEntry entry;
    printf("Enter site name: ");
    fgets(entry.site, MAX_LENGTH, stdin);
    entry.site[strcspn(entry.site, "\n")] = 0; // Remove newline character
    
    printf("Enter username: ");
    fgets(entry.username, MAX_LENGTH, stdin);
    entry.username[strcspn(entry.username, "\n")] = 0; // Remove newline character
    
    printf("Enter password: ");
    fgets(entry.password, MAX_LENGTH, stdin);
    entry.password[strcspn(entry.password, "\n")] = 0; // Remove newline character
    
    passwordList[totalPasswords++] = entry;
    printf("Password entry added successfully.\n");
}

void displayPasswords() {
    if (totalPasswords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("\n--- Stored Passwords ---\n");
    for (int i = 0; i < totalPasswords; i++) {
        printf("Site: %s\n", passwordList[i].site);
        printf("Username: %s\n", passwordList[i].username);
        printf("Password: %s\n\n", passwordList[i].password);
    }
}

void removePassword() {
    if (totalPasswords == 0) {
        printf("No passwords to remove.\n");
        return;
    }

    char site[MAX_LENGTH];
    printf("Enter site name to remove: ");
    fgets(site, MAX_LENGTH, stdin);
    site[strcspn(site, "\n")] = 0; // Remove newline character

    int index = findPasswordIndex(site);
    if (index == -1) {
        printf("Password entry for site '%s' not found.\n", site);
        return;
    }

    for (int i = index; i < totalPasswords - 1; i++) {
        passwordList[i] = passwordList[i + 1]; // Shift entries left
    }
    totalPasswords--;
    printf("Password entry for site '%s' removed successfully.\n", site);
}

int findPasswordIndex(const char *site) {
    for (int i = 0; i < totalPasswords; i++) {
        if (strcmp(passwordList[i].site, site) == 0) {
            return i;
        }
    }
    return -1;
}