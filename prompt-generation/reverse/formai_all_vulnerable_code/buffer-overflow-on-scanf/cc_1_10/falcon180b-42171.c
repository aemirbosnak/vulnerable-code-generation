//Falcon-180B DATASET v1.0 Category: Password management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Sorry, you have reached the maximum number of passwords.\n");
        return;
    }

    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    passwords[numPasswords].username = strdup(username);
    passwords[numPasswords].password = strdup(password);

    numPasswords++;

    printf("Password added successfully.\n");
}

void removePassword() {
    if (numPasswords == 0) {
        printf("No passwords to remove.\n");
        return;
    }

    int index;
    printf("Enter index of password to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= numPasswords) {
        printf("Invalid index.\n");
        return;
    }

    free(passwords[index].username);
    free(passwords[index].password);

    for (int i = index; i < numPasswords - 1; i++) {
        passwords[i] = passwords[i + 1];
    }

    numPasswords--;

    printf("Password removed successfully.\n");
}

void viewPasswords() {
    if (numPasswords == 0) {
        printf("No passwords to view.\n");
        return;
    }

    for (int i = 0; i < numPasswords; i++) {
        printf("%d. %s: %s\n", i + 1, passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    do {
        printf("Password Management Program\n");
        printf("1. Add a password\n");
        printf("2. Remove a password\n");
        printf("3. View all passwords\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            removePassword();
            break;
        case 3:
            viewPasswords();
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}