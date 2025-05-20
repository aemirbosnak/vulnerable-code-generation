//Falcon-180B DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    strcat(password, "\0");
    strcat(username, "\0");

    if (num_passwords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;

    printf("Password added successfully.\n");
}

void remove_password() {
    char username[MAX_USERNAME_LENGTH];

    printf("Enter username to remove: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);

    strcat(username, "\0");

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password removed successfully.\n");
            memset(passwords[i].username, 0, MAX_USERNAME_LENGTH);
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);
            num_passwords--;
            return;
        }
    }

    printf("Password not found.\n");
}

void display_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

void main() {
    int choice;

    while (1) {
        printf("\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Display passwords\n");
        printf("4. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            remove_password();
            break;
        case 3:
            display_passwords();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}