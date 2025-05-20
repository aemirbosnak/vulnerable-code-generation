//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: multivariable
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

PasswordEntry passwordList[MAX_PASSWORDS];
int passwordCount = 0;

void displayInstructions() {
    printf("Password Manager Instructions:\n");
    printf("1. Add a new password entry\n");
    printf("2. Display all passwords\n");
    printf("3. Search for a password\n");
    printf("4. Delete a password entry\n");
    printf("5. Exit the program\n");
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password list is full. Cannot add more entries.\n");
        return;
    }

    PasswordEntry newEntry;

    printf("Enter Website: ");
    scanf("%s", newEntry.website);
    printf("Enter Username: ");
    scanf("%s", newEntry.username);
    printf("Enter Password: ");
    scanf("%s", newEntry.password);

    passwordList[passwordCount++] = newEntry;
    printf("Password entry added successfully!\n");
}

void displayPasswords() {
    if (passwordCount == 0) {
        printf("No passwords stored.\n");
        return;
    }

    for (int i = 0; i < passwordCount; ++i) {
        printf("Entry %d: Website: %s, Username: %s, Password: %s\n",
               i + 1, passwordList[i].website, passwordList[i].username, passwordList[i].password);
    }
}

void searchPassword() {
    char website[MAX_LENGTH];
    printf("Enter the website to search for: ");
    scanf("%s", website);

    for (int i = 0; i < passwordCount; ++i) {
        if (strcmp(passwordList[i].website, website) == 0) {
            printf("Found Entry: Website: %s, Username: %s, Password: %s\n", 
                   passwordList[i].website, passwordList[i].username, passwordList[i].password);
            return;
        }
    }
    printf("No entry found for the given website.\n");
}

void deletePassword() {
    char website[MAX_LENGTH];
    printf("Enter the website to delete: ");
    scanf("%s", website);

    for (int i = 0; i < passwordCount; ++i) {
        if (strcmp(passwordList[i].website, website) == 0) {
            for (int j = i; j < passwordCount - 1; ++j) {
                passwordList[j] = passwordList[j + 1];
            }
            passwordCount--;
            printf("Entry deleted successfully!\n");
            return;
        }
    }
    printf("No entry found for the given website.\n");
}

int main() {
    int choice;

    while (1) {
        displayInstructions();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                searchPassword();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}