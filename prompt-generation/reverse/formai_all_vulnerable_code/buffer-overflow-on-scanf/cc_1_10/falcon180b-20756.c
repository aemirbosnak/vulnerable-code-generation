//Falcon-180B DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    char choice;
    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add a password\n");
        printf("2. Search for a password\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (numPasswords >= MAX_PASSWORDS) {
                printf("Password limit reached!\n");
            } else {
                printf("Enter username: ");
                scanf("%s", passwords[numPasswords].username);
                printf("Enter password: ");
                scanf("%s", passwords[numPasswords].password);
                numPasswords++;
            }
            break;
        case '2':
            printf("Enter username to search: ");
            char searchUsername[MAX_PASSWORD_LENGTH];
            scanf("%s", searchUsername);

            int found = 0;
            for (int i = 0; i < numPasswords; i++) {
                if (strcmp(passwords[i].username, searchUsername) == 0) {
                    printf("Password found: %s\n", passwords[i].password);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Password not found!\n");
            }
            break;
        case '3':
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}