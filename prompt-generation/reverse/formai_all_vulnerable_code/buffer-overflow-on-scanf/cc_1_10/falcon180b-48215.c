//Falcon-180B DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

typedef struct {
    char username[50];
    char password[PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
    printf("Password added successfully.\n");
}

void displayPasswords() {
    printf("Passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s - %s\n", passwords[i].username, passwords[i].password);
    }
}

void searchPassword() {
    printf("Enter username to search: ");
    char username[50];
    scanf("%s", username);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }

    printf("User not found.\n");
}

int main() {
    printf("Password Manager\n");

    while (1) {
        printf("1. Add password\n");
        printf("2. Display passwords\n");
        printf("3. Search password\n");
        printf("4. Exit\n");

        int choice;
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
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}