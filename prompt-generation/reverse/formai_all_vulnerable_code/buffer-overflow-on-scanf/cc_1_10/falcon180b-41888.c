//Falcon-180B DATASET v1.0 Category: Password management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 25

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

void generatePassword(Password *password) {
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?";
    int i, j;

    for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password->password[i] = chars[rand() % strlen(chars)];
    }

    password->length = MAX_PASSWORD_LENGTH;
}

int main() {
    char choice;
    int i, j;
    Password passwords[MAX_PASSWORDS];

    printf("Welcome to the Password Manager!\n");

    do {
        printf("\n");
        printf("1. Generate new password\n");
        printf("2. Store password\n");
        printf("3. Retrieve password\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("\n");
                printf("Enter the length of the password (1-25): ");
                scanf("%d", &passwords[0].length);
                generatePassword(&passwords[0]);
                printf("\n");
                printf("Your new password is: %s\n", passwords[0].password);
                break;
            case '2':
                printf("\n");
                printf("Enter the length of the password (1-25): ");
                scanf("%d", &passwords[0].length);
                printf("\n");
                printf("Enter the password: ");
                scanf("%s", passwords[0].password);
                break;
            case '3':
                printf("\n");
                printf("Enter the ID of the password (1-10): ");
                scanf("%d", &i);
                printf("\n");
                printf("Your password is: %s\n", passwords[i-1].password);
                break;
            case '4':
                printf("\n");
                printf("Exiting...\n");
                break;
            default:
                printf("\n");
                printf("Invalid choice!\n");
        }

    } while (choice!= '4');

    return 0;
}