//Falcon-180B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void generatePassword(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0';
}

void addPassword() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter password length (1-100): ");
    scanf("%d", &length);

    if (length < 1 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length.\n");
        return;
    }

    generatePassword(password, length);
    strcpy(passwords[numPasswords].password, password);
    passwords[numPasswords].length = length;

    numPasswords++;
    printf("Password added.\n");
}

void listPasswords() {
    int i;

    printf("Passwords:\n");
    for (i = 0; i < numPasswords; i++) {
        printf("%d. %s (%d characters)\n", i + 1, passwords[i].password, passwords[i].length);
    }
}

void main() {
    int choice;

    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. List passwords\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            listPasswords();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);
}