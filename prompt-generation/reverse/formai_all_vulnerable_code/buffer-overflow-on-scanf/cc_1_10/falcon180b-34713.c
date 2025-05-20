//Falcon-180B DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void addPassword(struct Password passwords[], int numPasswords) {
    printf("Enter name for password: ");
    scanf("%s", passwords[numPasswords].name);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

void displayPasswords(struct Password passwords[], int numPasswords) {
    printf("\nPasswords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s - %s\n", passwords[i].name, passwords[i].password);
    }
}

void changePassword(struct Password passwords[], int numPasswords) {
    printf("\nEnter name of password to change: ");
    scanf("%s", passwords[numPasswords].name);

    printf("Enter new password: ");
    scanf("%s", passwords[numPasswords].password);
}

void deletePassword(struct Password passwords[], int numPasswords) {
    printf("\nEnter name of password to delete: ");
    scanf("%s", passwords[numPasswords].name);
}

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    printf("Welcome to Password Manager!\n");

    while (1) {
        printf("\nOptions:\n1. Add Password\n2. Display Passwords\n3. Change Password\n4. Delete Password\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword(passwords, numPasswords);
            break;

        case 2:
            displayPasswords(passwords, numPasswords);
            break;

        case 3:
            changePassword(passwords, numPasswords);
            break;

        case 4:
            deletePassword(passwords, numPasswords);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}