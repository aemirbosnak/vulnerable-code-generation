//Falcon-180B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void generatePassword(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

void addPassword() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter password length: ");
    scanf("%d", &length);

    generatePassword(password, length);

    printf("Password generated: %s\n", password);

    if (numPasswords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[numPasswords].password, password);
    passwords[numPasswords].length = length;
    numPasswords++;

    printf("Password added successfully.\n");
}

void viewPasswords() {
    if (numPasswords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%d. %s (%d characters)\n", i+1, passwords[i].password, passwords[i].length);
    }
}

void main() {
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
}