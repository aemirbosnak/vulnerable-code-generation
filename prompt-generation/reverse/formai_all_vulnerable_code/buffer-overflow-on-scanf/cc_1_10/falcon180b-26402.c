//Falcon-180B DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    char input[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 2];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int length = 0;

    printf("Welcome to the Password Manager!\n");
    while (1) {
        printf("\nEnter a command:\n");
        printf("1. Add a new password\n");
        printf("2. Retrieve a password\n");
        printf("3. Exit\n");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password length (between 8 and %d): ", MAX_PASSWORD_LENGTH - 1);
            scanf("%d", &length);
            if (length < 8 || length > MAX_PASSWORD_LENGTH - 1) {
                printf("Invalid password length.\n");
            } else {
                generatePassword(password, length);
                strcpy(passwords[numPasswords].username, username);
                strcpy(passwords[numPasswords].password, password);
                numPasswords++;
                printf("Password added successfully.\n");
            }
        } else if (strcmp(input, "2") == 0) {
            printf("Enter username: ");
            scanf("%s", username);
            for (int i = 0; i < numPasswords; i++) {
                if (strcmp(passwords[i].username, username) == 0) {
                    printf("Password: %s\n", passwords[i].password);
                    break;
                }
            }
        } else if (strcmp(input, "3") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}