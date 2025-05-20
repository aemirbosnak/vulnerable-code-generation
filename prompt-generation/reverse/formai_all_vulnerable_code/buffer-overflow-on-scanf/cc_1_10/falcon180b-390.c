//Falcon-180B DATASET v1.0 Category: Password management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64
#define MAX_USER_LENGTH 32

typedef struct {
    char username[MAX_USER_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_entry;

password_entry passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void remove_password(char *username) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memset(&passwords[i], 0, sizeof(password_entry));
            num_passwords--;
            return;
        }
    }

    printf("Error: Password not found.\n");
}

void list_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("%s - %s\n", passwords[i].username, passwords[i].password);
    }
}

void main() {
    char choice;

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. List passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter username: ");
                scanf("%s", passwords[num_passwords].username);
                printf("Enter password: ");
                scanf("%s", passwords[num_passwords].password);
                break;

            case '2':
                printf("Enter username: ");
                scanf("%s", passwords[num_passwords].username);
                remove_password(passwords[num_passwords].username);
                break;

            case '3':
                list_passwords();
                break;

            case '4':
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}