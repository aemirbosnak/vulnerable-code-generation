//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 256

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordManager[MAX_PASSWORDS];
int passwordCount = 0;

void addPasswordEntry() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password storage is full!\n");
        return;
    }

    PasswordEntry entry;
    printf("Enter website: ");
    scanf("%s", entry.website);
    printf("Enter username: ");
    scanf("%s", entry.username);
    printf("Enter password: ");
    scanf("%s", entry.password);

    passwordManager[passwordCount] = entry;
    passwordCount++;
    printf("Password entry added successfully!\n");
}

void retrievePassword() {
    char website[MAX_LENGTH];
    printf("Enter website to retrieve password: ");
    scanf("%s", website);

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordManager[i].website, website) == 0) {
            printf("Website: %s\n", passwordManager[i].website);
            printf("Username: %s\n", passwordManager[i].username);
            printf("Password: %s\n", passwordManager[i].password);
            return;
        }
    }

    printf("No password found for this website!\n");
}

void displayAllPasswords() {
    if (passwordCount == 0) {
        printf("No passwords stored!\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Website: %s | Username: %s | Password: %s\n", 
               passwordManager[i].website, 
               passwordManager[i].username, 
               passwordManager[i].password);
    }
}

void clearPasswords() {
    passwordCount = 0;
    printf("All passwords cleared from memory!\n");
}

void menu() {
    printf("\nPassword Management System\n");
    printf("1. Add Password\n");
    printf("2. Retrieve Password\n");
    printf("3. Display All Passwords\n");
    printf("4. Clear All Passwords\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPasswordEntry();
                break;
            case 2:
                retrievePassword();
                break;
            case 3:
                displayAllPasswords();
                break;
            case 4:
                clearPasswords();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}