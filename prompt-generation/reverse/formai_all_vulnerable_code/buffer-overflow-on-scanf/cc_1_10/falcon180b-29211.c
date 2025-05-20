//Falcon-180B DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char* username, char* password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void removePassword(char* username) {
    int i;

    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memset(passwords[i].username, 0, MAX_PASSWORD_LENGTH);
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);

            printf("Password removed.\n");
            return;
        }
    }

    printf("Password not found.\n");
}

void listPasswords() {
    int i;

    for (i = 0; i < numPasswords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

void main() {
    char choice;
    int usernameLength, passwordLength;

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add password\n2. Remove password\n3. List passwords\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter username (max %d characters): ", MAX_PASSWORD_LENGTH - 1);
                scanf("%s", passwords[numPasswords].username);

                printf("Enter password (max %d characters): ", MAX_PASSWORD_LENGTH - 1);
                scanf("%s", passwords[numPasswords].password);

                addPassword(passwords[numPasswords].username, passwords[numPasswords].password);
                break;

            case '2':
                printf("Enter username to remove: ");
                scanf("%s", passwords[numPasswords].username);

                removePassword(passwords[numPasswords].username);
                break;

            case '3':
                listPasswords();
                break;

            case '4':
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}