//FormAI DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

struct Password {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

struct Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
    } else {
        struct Password password;
        printf("Enter website: ");
        scanf("%s", password.website);
        printf("Enter username: ");
        scanf("%s", password.username);
        printf("Enter password: ");
        scanf("%s", password.password);
        passwords[numPasswords++] = password;
        printf("Password added.\n");
    }
}

void viewPasswords() {
    if (numPasswords == 0) {
        printf("No passwords saved.\n");
    } else {
        for (int i = 0; i < numPasswords; i++) {
            printf("Website: %s\nUsername: %s\nPassword: %s\n",
                   passwords[i].website, passwords[i].username, passwords[i].password);
        }
    }
}

void searchPasswords() {
    char website[MAX_LENGTH];
    printf("Enter website to search for: ");
    scanf("%s", website);
    int found = 0;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
            found = 1;
        }
    }
    if (!found) {
        printf("No passwords found for website: %s\n", website);
    }
}

int main() {
    int choice;
    printf("Password Manager\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Search Passwords\n");
    printf("4. Exit\n");
    do {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                searchPasswords();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}