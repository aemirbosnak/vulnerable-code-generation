//Falcon-180B DATASET v1.0 Category: Password management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

void generatePassword(Password* password) {
    const char symbols[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password->password[i] = symbols[rand() % (sizeof(symbols) - 1)];
    }

    password->length = MAX_PASSWORD_LENGTH;
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    int choice;

    do {
        printf("\nWelcome to the Post-Apocalyptic Password Manager!\n");
        printf("1. Generate a new password\n");
        printf("2. Store a password\n");
        printf("3. Retrieve a password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            generatePassword(&passwords[numPasswords]);
            printf("Your new password is: %s\n", passwords[numPasswords].password);
            numPasswords++;
            break;

        case 2:
            if (numPasswords >= MAX_PASSWORDS) {
                printf("Sorry, you have reached the maximum number of passwords.\n");
            } else {
                printf("Enter the password to store: ");
                scanf("%s", passwords[numPasswords].password);
                passwords[numPasswords].length = strlen(passwords[numPasswords].password);
                numPasswords++;
            }
            break;

        case 3:
            if (numPasswords == 0) {
                printf("You don't have any stored passwords.\n");
            } else {
                printf("Enter the index of the password to retrieve: ");
                scanf("%d", &choice);

                if (choice >= 0 && choice < numPasswords) {
                    printf("Your password is: %s\n", passwords[choice].password);
                } else {
                    printf("Invalid index.\n");
                }
            }
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}