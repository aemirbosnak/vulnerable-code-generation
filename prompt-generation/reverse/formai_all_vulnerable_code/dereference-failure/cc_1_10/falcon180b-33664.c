//Falcon-180B DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    char choice;
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    do {
        printf("Welcome to the Password Management System!\n");
        printf("Please choose an option:\n");
        printf("1. Add a password\n");
        printf("2. Remove a password\n");
        printf("3. Search for a password\n");
        printf("4. Exit\n");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                // Add a password
                printf("Enter a username: ");
                scanf(" %s", passwords[numPasswords].username);
                printf("Enter a password: ");
                scanf(" %s", passwords[numPasswords].password);
                numPasswords++;
                break;

            case '2':
                // Remove a password
                printf("Enter a username to remove: ");
                scanf(" %s", passwords[numPasswords-1].username);
                numPasswords--;
                break;

            case '3':
                // Search for a password
                printf("Enter a username to search for: ");
                scanf(" %s", passwords[numPasswords-1].username);
                if(strcmp(passwords[numPasswords-1].username, "admin") == 0) {
                    printf("Sorry, you cannot search for admin passwords.\n");
                } else {
                    printf("Password found: %s\n", passwords[numPasswords-1].password);
                }
                break;

            case '4':
                // Exit
                printf("Goodbye!\n");
                break;

            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while(choice!= '4');

    return 0;
}