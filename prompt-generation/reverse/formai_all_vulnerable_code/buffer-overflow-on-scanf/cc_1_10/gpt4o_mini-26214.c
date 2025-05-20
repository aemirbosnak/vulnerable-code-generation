//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 100

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordDB[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword();
void viewPasswords();
void searchPassword();
void deletePassword();
void displayMenu();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        displayMenu();
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
                searchPassword();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=== Password Manager ===\n");
    printf("1. Add Password\n");
    printf("2. View All Passwords\n");
    printf("3. Search Password\n");
    printf("4. Delete Password\n");
    printf("5. Exit\n");
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password storage full! Cannot add more passwords.\n");
        return;
    }

    printf("Enter website: ");
    fgets(passwordDB[passwordCount].website, MAX_LENGTH, stdin);
    strtok(passwordDB[passwordCount].website, "\n");

    printf("Enter username: ");
    fgets(passwordDB[passwordCount].username, MAX_LENGTH, stdin);
    strtok(passwordDB[passwordCount].username, "\n");

    printf("Enter password: ");
    fgets(passwordDB[passwordCount].password, MAX_LENGTH, stdin);
    strtok(passwordDB[passwordCount].password, "\n");

    passwordCount++;
    printf("Password entry added successfully!\n");
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("No passwords stored yet.\n");
        return;
    }

    printf("\n=== Stored Passwords ===\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Website: %s\n", passwordDB[i].website);
        printf("Username: %s\n", passwordDB[i].username);
        printf("Password: %s\n\n", passwordDB[i].password);
    }
}

void searchPassword() {
    char website[MAX_LENGTH];
    printf("Enter website to search: ");
    fgets(website, MAX_LENGTH, stdin);
    strtok(website, "\n");

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordDB[i].website, website) == 0) {
            printf("Found password for %s:\n", website);
            printf("Username: %s\n", passwordDB[i].username);
            printf("Password: %s\n", passwordDB[i].password);
            return;
        }
    }

    printf("No passwords found for %s.\n", website);
}

void deletePassword() {
    char website[MAX_LENGTH];
    printf("Enter website to delete: ");
    fgets(website, MAX_LENGTH, stdin);
    strtok(website, "\n");

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordDB[i].website, website) == 0) {
            for (int j = i; j < passwordCount - 1; j++) {
                passwordDB[j] = passwordDB[j + 1];
            }
            passwordCount--;
            printf("Password entry for %s deleted successfully!\n", website);
            return;
        }
    }

    printf("No passwords found for %s to delete.\n", website);
}

void clearInputBuffer() {
    while(getchar() != '\n'); // clear the input buffer
}