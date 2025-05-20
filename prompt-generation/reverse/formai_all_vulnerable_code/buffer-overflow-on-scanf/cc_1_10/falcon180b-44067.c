//Falcon-180B DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    char choice;

    while (1) {
        printf("Password Manager\n");
        printf("A - Add a password\n");
        printf("S - Search for a password\n");
        printf("D - Delete a password\n");
        printf("Q - Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'A':
                if (numPasswords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                    break;
                }
                printf("Enter username: ");
                scanf("%s", passwords[numPasswords].username);
                printf("Enter password: ");
                scanf("%s", passwords[numPasswords].password);
                numPasswords++;
                break;
            case 'S':
                printf("Enter username to search for: ");
                scanf("%s", passwords[0].username);
                break;
            case 'D':
                printf("Enter username to delete: ");
                scanf("%s", passwords[0].username);
                break;
            case 'Q':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}