//Falcon-180B DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

void add_password(password_t passwords[], int num_passwords, char *username, char *password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("User already exists.\n");
            return;
        }
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void delete_password(password_t passwords[], int num_passwords, char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memmove(&passwords[i], &passwords[i+1], (num_passwords - i - 1) * sizeof(password_t));
            num_passwords--;
            break;
        }
    }
}

void view_passwords(password_t passwords[], int num_passwords) {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    char choice;
    do {
        printf("Enter 1 to add a password, 2 to delete a password, 3 to view all passwords, or any other key to exit.\n");
        scanf("%c", &choice);

        if (choice == '1') {
            char username[50];
            char password[MAX_PASSWORD_LENGTH];

            printf("Enter username: ");
            scanf("%s", username);

            printf("Enter password: ");
            scanf("%s", password);

            add_password(passwords, num_passwords, username, password);
        } else if (choice == '2') {
            char username[50];

            printf("Enter username to delete: ");
            scanf("%s", username);

            delete_password(passwords, num_passwords, username);
        } else if (choice == '3') {
            view_passwords(passwords, num_passwords);
        } else {
            printf("Exiting...\n");
        }
    } while (choice!= 'q');

    return 0;
}