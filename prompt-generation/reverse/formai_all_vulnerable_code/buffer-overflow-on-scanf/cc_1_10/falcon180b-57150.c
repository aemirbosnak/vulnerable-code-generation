//Falcon-180B DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    int length = strlen(password);

    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return;
    }

    strcpy(passwords[numPasswords].password, password);
    passwords[numPasswords].length = length;

    numPasswords++;
}

void listPasswords() {
    printf("Passwords:\n");

    for (int i = 0; i < numPasswords; i++) {
        printf("%d. %s (%d characters)\n", i + 1, passwords[i].password, passwords[i].length);
    }
}

void main() {
    printf("Welcome to the password manager!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add password\n");
        printf("2. List passwords\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;

        case 2:
            listPasswords();
            break;

        case 3:
            printf("Goodbye!\n");
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }
}