//Falcon-180B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char *password, int length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    printf("Welcome to the Sherlock Holmes Password Manager!\n");

    while (1) {
        printf("\n");
        printf("1. Add a new password\n");
        printf("2. Retrieve a password\n");
        printf("3. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numPasswords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                printf("Enter username: ");
                scanf("%s", passwords[numPasswords].username);
                generatePassword(passwords[numPasswords].password, rand() % MAX_PASSWORD_LENGTH + 8);
                printf("Password generated: %s\n", passwords[numPasswords].password);
                numPasswords++;
            }
            break;

        case 2:
            printf("Enter username: ");
            char username[MAX_USERNAME_LENGTH];
            scanf("%s", username);

            int found = 0;
            for (int i = 0; i < numPasswords; i++) {
                if (strcmp(username, passwords[i].username) == 0) {
                    printf("Password: %s\n", passwords[i].password);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("User not found.\n");
            }
            break;

        case 3:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}