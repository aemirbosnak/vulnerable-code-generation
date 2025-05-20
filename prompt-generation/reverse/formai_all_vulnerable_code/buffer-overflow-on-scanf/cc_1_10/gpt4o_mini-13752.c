//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 256
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char password[PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password storage is full. Cannot add more passwords.\n");
        return;
    }

    PasswordEntry entry;

    printf("Enter title for the password: ");
    scanf("%s", entry.title);

    printf("Enter password: ");
    scanf("%s", entry.password);

    passwordList[passwordCount++] = entry;
    printf("Password added successfully.\n");
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Title: %s, Password: %s\n", passwordList[i].title, passwordList[i].password);
    }
}

void deletePassword() {
    char title[TITLE_LENGTH];
    printf("Enter title of the password to delete: ");
    scanf("%s", title);

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordList[i].title, title) == 0) {
            for (int j = i; j < passwordCount - 1; j++) {
                passwordList[j] = passwordList[j + 1];
            }
            passwordCount--;
            printf("Password for '%s' deleted successfully.\n", title);
            return;
        }
    }
    printf("No password found for the title '%s'.\n", title);
}

void clearConsole() {
    // Clear the console screen
    printf("\033[H\033[J");
}

int main() {
    int choice;

    do {
        clearConsole();
        printf("Password Manager\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
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
                printf("Exiting the Password Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }

        // Pause before showing the menu again
        if (choice != 4) {
            printf("Press Enter to continue...");
            while (getchar() != '\n'); // Clear the buffer
            getchar(); // Wait for Enter key
        }
    } while (choice != 4);

    return 0;
}