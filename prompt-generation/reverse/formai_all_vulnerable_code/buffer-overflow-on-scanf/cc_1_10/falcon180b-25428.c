//Falcon-180B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: password list is full.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void remove_password(char* username) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memset(passwords[i].username, 0, MAX_PASSWORD_LENGTH);
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);

            num_passwords--;

            return;
        }
    }

    printf("Error: password not found.\n");
}

void print_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

void main() {
    int choice;

    while (1) {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Print passwords\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter username: ");
            scanf("%s", passwords[num_passwords].username);

            printf("Enter password: ");
            scanf("%s", passwords[num_passwords].password);

            printf("Password added.\n");
            break;

        case 2:
            printf("Enter username: ");
            scanf("%s", passwords[num_passwords].username);

            remove_password(passwords[num_passwords].username);

            break;

        case 3:
            print_passwords();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
}