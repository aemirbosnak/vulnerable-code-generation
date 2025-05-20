//Falcon-180B DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char* password, int length) {
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?\\";
    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    char choice;
    do {
        printf("Password Manager\n");
        printf("1. Add a new password\n");
        printf("2. View/Edit a password\n");
        printf("3. Delete a password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (numPasswords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter the username: ");
                    scanf(" %s", passwords[numPasswords].username);
                    generatePassword(passwords[numPasswords].password, MAX_PASSWORD_LENGTH);
                    numPasswords++;
                    printf("Password added successfully!\n");
                }
                break;
            case '2':
                printf("Enter the username: ");
                scanf(" %s", passwords[numPasswords - 1].username);
                printf("Enter the new password: ");
                scanf(" %s", passwords[numPasswords - 1].password);
                break;
            case '3':
                printf("Enter the username: ");
                scanf(" %s", passwords[numPasswords - 1].username);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}