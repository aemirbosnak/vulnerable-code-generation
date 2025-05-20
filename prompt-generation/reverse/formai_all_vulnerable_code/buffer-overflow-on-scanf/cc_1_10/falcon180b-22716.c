//Falcon-180B DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Password limit reached.\n");
        return;
    }

    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    int length = strlen(password);
    if (length > MAX_PASSWORD_LENGTH) {
        printf("Error: Password is too long.\n");
        return;
    }

    strcpy(passwords[numPasswords].password, password);
    passwords[numPasswords].length = length;
    numPasswords++;

    printf("Password added successfully.\n");
}

void displayPasswords() {
    if (numPasswords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%d. ", i+1);
        for (int j = 0; j < passwords[i].length; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void main() {
    printf("Password Management System\n");

    while (1) {
        printf("1. Add Password\n");
        printf("2. Display Passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

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
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}