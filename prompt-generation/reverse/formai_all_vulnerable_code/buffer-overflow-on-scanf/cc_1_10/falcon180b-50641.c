//Falcon-180B DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64
#define MAX_USERNAME_LENGTH 32

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    int i = 0;
    while (i < length) {
        password[i] = charset[rand() % strlen(charset)];
        i++;
    }
    password[i] = '\0';
}

void createAccount(Password *passwords, int numPasswords) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    generatePassword(password, 16);

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    printf("Account created successfully.\n");
}

void login(Password *passwords, int numPasswords, char *username, char *password) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (!strcmp(passwords[i].username, username) &&!strcmp(passwords[i].password, password)) {
            printf("Login successful.\n");
            return;
        }
    }
    printf("Login failed.\n");
}

void listAccounts(Password *passwords, int numPasswords) {
    int i;
    printf("Username\tPassword\n");
    for (i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    srand(time(NULL));

    while (numPasswords < MAX_PASSWORDS) {
        int choice;
        printf("\n1. Create account\n2. Login\n3. List accounts\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numPasswords >= MAX_PASSWORDS) {
                printf("Maximum number of accounts reached.\n");
                break;
            }
            createAccount(passwords, numPasswords);
            numPasswords++;
            break;
        case 2:
            printf("Enter username: ");
            char username[MAX_USERNAME_LENGTH];
            scanf("%s", username);

            printf("Enter password: ");
            char password[MAX_PASSWORD_LENGTH];
            scanf("%s", password);

            login(passwords, numPasswords, username, password);
            break;
        case 3:
            listAccounts(passwords, numPasswords);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}