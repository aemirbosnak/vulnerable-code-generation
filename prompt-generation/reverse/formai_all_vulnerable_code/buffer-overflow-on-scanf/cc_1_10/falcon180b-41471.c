//Falcon-180B DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 50
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    char choice;
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Search password\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter website: ");
            scanf("%s", passwords[numPasswords].website);
            printf("Enter username: ");
            scanf("%s", passwords[numPasswords].username);
            printf("Enter password: ");
            scanf("%s", passwords[numPasswords].password);
            numPasswords++;
            break;
        case '2':
            printf("Enter website to search: ");
            scanf("%s", passwords[numPasswords - 1].website);
            if (strcmp(passwords[numPasswords - 1].website, "") == 0) {
                printf("Website not found.\n");
            } else {
                printf("Website: %s\n", passwords[numPasswords - 1].website);
                printf("Username: %s\n", passwords[numPasswords - 1].username);
                printf("Password: %s\n", passwords[numPasswords - 1].password);
            }
            break;
        case '3':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '3');

    return 0;
}