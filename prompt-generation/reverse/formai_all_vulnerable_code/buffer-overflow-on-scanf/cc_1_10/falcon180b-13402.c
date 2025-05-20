//Falcon-180B DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    char choice;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int i;

    printf("Welcome to the Password Manager!\n");
    printf("Please enter your username: ");
    scanf("%s", username);

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add a new password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        printf("Please enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("Please enter the website or service: ");
            scanf("%s", username);
            printf("Please enter the password: ");
            scanf("%s", password);
            strcpy(passwords[numPasswords].username, username);
            strcpy(passwords[numPasswords].password, password);
            numPasswords++;
            break;
        case '2':
            if (numPasswords == 0) {
                printf("You do not have any passwords saved.\n");
            } else {
                printf("Your passwords:\n");
                for (i = 0; i < numPasswords; i++) {
                    printf("%s: %s\n", passwords[i].username, passwords[i].password);
                }
            }
            break;
        case '3':
            printf("Thank you for using the Password Manager!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}