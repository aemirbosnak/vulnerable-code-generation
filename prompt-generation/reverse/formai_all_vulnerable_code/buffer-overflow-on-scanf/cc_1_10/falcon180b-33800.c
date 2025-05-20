//Falcon-180B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 16

typedef struct {
    char username[32];
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
}

void removePassword() {
    if (numPasswords == 0) {
        printf("No passwords to remove.\n");
        return;
    }

    printf("Enter username to remove: ");
    scanf("%s", passwords[0].username);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, passwords[0].username) == 0) {
            for (int j = i; j < numPasswords - 1; j++) {
                strcpy(passwords[j].username, passwords[j + 1].username);
                strcpy(passwords[j].password, passwords[j + 1].password);
            }

            numPasswords--;
            printf("Password removed.\n");
            return;
        }
    }

    printf("Username not found.\n");
}

void viewPasswords() {
    printf("Username\tPassword\n");

    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void main() {
    printf("Welcome to the password manager.\n");

    while (1) {
        printf("\n1. Add password\n2. Remove password\n3. View passwords\n4. Exit\n");
        int choice;
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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}