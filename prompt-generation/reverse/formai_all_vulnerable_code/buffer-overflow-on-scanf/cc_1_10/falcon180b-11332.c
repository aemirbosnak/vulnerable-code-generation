//Falcon-180B DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char* password, int length) {
    const char* validChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+=[{]}\\|;:'\",<.>/?`~";
    int i = 0;
    for (i = 0; i < length; i++) {
        password[i] = validChars[rand() % strlen(validChars)];
    }
    password[i] = '\0';
}

int main() {
    int choice, length;
    char username[MAX_PASSWORD_LENGTH];
    Password passwords[MAX_PASSWORDS];

    printf("Welcome to the Password Manager!\n");
    printf("Please enter your username: ");
    scanf("%s", username);

    int numPasswords = 0;
    while (numPasswords < MAX_PASSWORDS) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new password\n");
        printf("2. View all passwords\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the length of the password: ");
                scanf("%d", &length);
                generatePassword(passwords[numPasswords].password, length);
                printf("Enter the username for this password: ");
                scanf("%s", passwords[numPasswords].username);
                numPasswords++;
                break;
            case 2:
                printf("\nPasswords:\n");
                for (int i = 0; i < numPasswords; i++) {
                    printf("Password %d: %s\n", i + 1, passwords[i].password);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}