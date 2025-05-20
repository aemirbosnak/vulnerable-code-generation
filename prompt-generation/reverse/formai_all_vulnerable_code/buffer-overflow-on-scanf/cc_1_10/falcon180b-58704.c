//Falcon-180B DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    char username[MAX_USERNAME_LENGTH];
    printf("Enter your username: ");
    scanf("%s", username);

    while (1) {
        int choice;
        printf("\nChoose an option:\n");
        printf("1. Add a new password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numPasswords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                char password[MAX_PASSWORD_LENGTH];
                printf("Enter a website or service name: ");
                scanf("%s", password);

                generatePassword(password, strlen(password));
                strcpy(passwords[numPasswords].password, password);
                strcpy(passwords[numPasswords].username, username);

                printf("Password generated and saved.\n");
                numPasswords++;
            }
            break;

        case 2:
            if (numPasswords == 0) {
                printf("No passwords saved.\n");
            } else {
                printf("\nPasswords:\n");
                for (int i = 0; i < numPasswords; i++) {
                    printf("%s - %s\n", passwords[i].username, passwords[i].password);
                }
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}