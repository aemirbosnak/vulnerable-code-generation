//Falcon-180B DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct {
    char username[50];
    char password[50];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Cannot add more passwords.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

void removePassword() {
    if (numPasswords == 0) {
        printf("Error: No passwords to remove.\n");
        return;
    }

    printf("Enter username to remove: ");
    char username[50];
    scanf("%s", username);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            strcpy(passwords[i].username, "");
            strcpy(passwords[i].password, "");
            printf("Password removed.\n");
            return;
        }
    }

    printf("Error: Password not found.\n");
}

void displayPasswords() {
    if (numPasswords == 0) {
        printf("Error: No passwords to display.\n");
        return;
    }

    printf("Username\t\tPassword\n");
    printf("---------------------------------\n");

    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    do {
        printf("Password Management System\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Display passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            removePassword();
            break;
        case 3:
            displayPasswords();
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Error: Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}