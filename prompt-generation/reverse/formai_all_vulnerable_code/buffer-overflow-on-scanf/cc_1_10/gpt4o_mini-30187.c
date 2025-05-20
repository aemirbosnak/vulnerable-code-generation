//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 100

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Credential;

Credential passwordManager[MAX_PASSWORDS];
int count = 0;

void addPassword();
void viewPasswords();
void deletePassword();
void clearBuffer();

int main() {
    int choice;

    do {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        clearBuffer();

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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please choose a valid number.\n");
        }
    } while (choice != 4);

    return 0;
}

void addPassword() {
    if (count >= MAX_PASSWORDS) {
        printf("Password storage is full!\n");
        return;
    }

    printf("Enter Website: ");
    fgets(passwordManager[count].website, MAX_LENGTH, stdin);
    passwordManager[count].website[strcspn(passwordManager[count].website, "\n")] = 0; // Remove newline

    printf("Enter Username: ");
    fgets(passwordManager[count].username, MAX_LENGTH, stdin);
    passwordManager[count].username[strcspn(passwordManager[count].username, "\n")] = 0; // Remove newline

    printf("Enter Password: ");
    fgets(passwordManager[count].password, MAX_LENGTH, stdin);
    passwordManager[count].password[strcspn(passwordManager[count].password, "\n")] = 0; // Remove newline

    count++;
    printf("Password added successfully!\n");
}

void viewPasswords() {
    if (count == 0) {
        printf("No passwords stored yet.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Website: %s\n", passwordManager[i].website);
        printf("Username: %s\n", passwordManager[i].username);
        printf("Password: %s\n\n", passwordManager[i].password);
    }
}

void deletePassword() {
    if (count == 0) {
        printf("No passwords to delete.\n");
        return;
    }

    char website[MAX_LENGTH];
    printf("Enter the website for the password you want to delete: ");
    fgets(website, MAX_LENGTH, stdin);
    website[strcspn(website, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(passwordManager[i].website, website) == 0) {
            for (int j = i; j < count - 1; j++) {
                passwordManager[j] = passwordManager[j + 1];
            }
            count--;
            printf("Password for %s deleted successfully!\n", website);
            return;
        }
    }
    printf("No password found for the website: %s\n", website);
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}