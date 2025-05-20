//Falcon-180B DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 32
#define USER_NAME_LENGTH 32

typedef struct {
    char user_name[USER_NAME_LENGTH];
    char password[PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void generatePassword(char *password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[PASSWORD_LENGTH - 1] = '\0';
}

int main() {
    char user_name[USER_NAME_LENGTH];
    char password[PASSWORD_LENGTH];
    char query[100];
    int choice;
    int i;
    int found = 0;

    printf("Welcome to the Password Management System!\n");
    printf("---------------------------------------------\n");

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add a new password\n");
        printf("2. Search for a password\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the user name: ");
            scanf("%s", user_name);

            printf("Enter the password: ");
            scanf("%s", password);

            generatePassword(password);

            strcpy(passwords[numPasswords].user_name, user_name);
            strcpy(passwords[numPasswords].password, password);
            numPasswords++;

            printf("Password added successfully!\n");
        }
        else if (choice == 2) {
            printf("Enter the user name to search for: ");
            scanf("%s", query);

            for (i = 0; i < numPasswords; i++) {
                if (strcmp(query, passwords[i].user_name) == 0) {
                    printf("Password found: %s\n", passwords[i].password);
                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                printf("Password not found.\n");
            }
        }
        else if (choice == 3) {
            exit(0);
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}