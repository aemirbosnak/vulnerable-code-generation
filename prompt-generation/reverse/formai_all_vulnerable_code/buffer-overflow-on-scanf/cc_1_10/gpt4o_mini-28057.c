//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordStorage[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword();
void viewPasswords();
void findPassword();
void deletePassword();
void menu();

int main() {
    printf("Welcome to Sherlock's Password Management System.\n");
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add a new password\n");
        printf("2. View saved passwords\n");
        printf("3. Find a password\n");
        printf("4. Delete a password\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                findPassword();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                printf("Exiting the system. Until next time, Watson.\n");
                break;
            default:
                printf("Invalid choice, Watson! Please select again.\n");
        }
    } while (choice != 5);
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("The password storage is full, Watson! Cannot add more.\n");
        return;
    }

    PasswordEntry newEntry;
    printf("Enter website: ");
    scanf("%s", newEntry.website);
    printf("Enter username: ");
    scanf("%s", newEntry.username);
    printf("Enter password: ");
    scanf("%s", newEntry.password);

    passwordStorage[passwordCount] = newEntry;
    passwordCount++;
    printf("Password entered successfully! A fine addition indeed.\n");
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("No passwords saved, Watson!\n");
        return;
    }

    printf("\nList of saved passwords:\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Website: %s, Username: %s, Password: %s\n",
               passwordStorage[i].website,
               passwordStorage[i].username,
               passwordStorage[i].password);
    }
}

void findPassword() {
    char website[MAX_LENGTH];
    printf("Enter the website to find the password: ");
    scanf("%s", website);

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordStorage[i].website, website) == 0) {
            printf("Website: %s, Username: %s, Password: %s\n",
                   passwordStorage[i].website,
                   passwordStorage[i].username,
                   passwordStorage[i].password);
            return;
        }
    }
    printf("Ah, Watson! I could not find a password related to that website.\n");
}

void deletePassword() {
    char website[MAX_LENGTH];
    printf("Enter the website to delete the password: ");
    scanf("%s", website);

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordStorage[i].website, website) == 0) {
            for (int j = i; j < passwordCount - 1; j++) {
                passwordStorage[j] = passwordStorage[j + 1];
            }
            passwordCount--;
            printf("Password entry deleted successfully, Watson.\n");
            return;
        }
    }
    printf("Ah, even a razor-sharp mind cannot find a password for that website.\n");
}