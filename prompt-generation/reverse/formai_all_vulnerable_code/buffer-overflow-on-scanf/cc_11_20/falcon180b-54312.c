//Falcon-180B DATASET v1.0 Category: Password management ; Style: visionary
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
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    char choice;
    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. Delete Password\n");
        printf("3. Search Password\n");
        printf("4. Generate Password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter username: ");
                scanf("%s", passwords[numPasswords].username);
                printf("Enter password: ");
                scanf("%s", passwords[numPasswords].password);
                numPasswords++;
                break;
            case '2':
                printf("Enter username to delete: ");
                scanf("%s", passwords[numPasswords].username);
                for (int i = 0; i < numPasswords - 1; i++) {
                    if (strcmp(passwords[i].username, passwords[numPasswords].username) == 0) {
                        strcpy(passwords[i].username, passwords[numPasswords].username);
                        strcpy(passwords[i].password, passwords[numPasswords].password);
                        numPasswords--;
                        break;
                    }
                }
                break;
            case '3':
                printf("Enter username to search: ");
                scanf("%s", passwords[numPasswords].username);
                for (int i = 0; i < numPasswords; i++) {
                    if (strcmp(passwords[i].username, passwords[numPasswords].username) == 0) {
                        printf("Password for %s is %s\n", passwords[i].username, passwords[i].password);
                        break;
                    }
                }
                break;
            case '4':
                printf("Enter password length: ");
                int length;
                scanf("%d", &length);
                char password[MAX_PASSWORD_LENGTH];
                for (int i = 0; i < length; i++) {
                    password[i] = (char) (rand() % 26 + 'a');
                }
                password[length] = '\0';
                printf("Generated password: %s\n", password);
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}