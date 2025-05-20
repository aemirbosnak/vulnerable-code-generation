//Falcon-180B DATASET v1.0 Category: Password management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void generatePassword(int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    char password[MAX_PASSWORD_LENGTH];
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[i] = '\0';

    strcpy(passwords[numPasswords].password, password);
    passwords[numPasswords].length = length;
    numPasswords++;
}

int main() {
    int choice, length;
    char username[MAX_PASSWORD_LENGTH];

    printf("Welcome to the Password Management System!\n");
    printf("Please enter your username: ");
    scanf("%s", username);

    while (1) {
        printf("\n1. Generate password\n2. View passwords\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the length of the password: ");
                scanf("%d", &length);
                generatePassword(length);
                printf("\nPassword generated successfully!\n");
                break;
            case 2:
                printf("\nPasswords:\n");
                for (int i = 0; i < numPasswords; i++) {
                    printf("%d. %s (%d characters)\n", i+1, passwords[i].password, passwords[i].length);
                }
                break;
            case 3:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}