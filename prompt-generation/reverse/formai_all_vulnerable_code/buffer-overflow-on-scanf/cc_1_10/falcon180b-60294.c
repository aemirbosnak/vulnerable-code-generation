//Falcon-180B DATASET v1.0 Category: Password management ; Style: minimalist
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

void generatePassword(int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charsetLength = strlen(charset);
    int i;

    for (i = 0; i < length; i++) {
        passwords[numPasswords].password[i] = charset[rand() % charsetLength];
    }

    passwords[numPasswords].length = length;
    numPasswords++;
}

void printPasswords() {
    int i;

    for (i = 0; i < numPasswords; i++) {
        printf("Password %d: %s\n", i + 1, passwords[i].password);
    }
}

int main() {
    int choice, length;

    printf("Welcome to the Password Manager!\n");
    printf("1. Generate password\n");
    printf("2. Print passwords\n");
    printf("3. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter password length: ");
                scanf("%d", &length);
                generatePassword(length);
                break;
            case 2:
                printPasswords();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}