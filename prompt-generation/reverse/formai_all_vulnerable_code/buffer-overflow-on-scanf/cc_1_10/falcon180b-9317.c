//Falcon-180B DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    time_t last_modified;
} Password;

void print_menu() {
    printf("Password Manager Menu:\n");
    printf("1. Add a password\n");
    printf("2. Edit a password\n");
    printf("3. Delete a password\n");
    printf("4. View all passwords\n");
    printf("5. Exit\n");
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char choice;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            if (num_passwords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                printf("Enter username: ");
                scanf(" %s", passwords[num_passwords].username);
                printf("Enter password: ");
                scanf(" %s", passwords[num_passwords].password);
                passwords[num_passwords].last_modified = time(NULL);
                num_passwords++;
            }
            break;

        case '2':
            if (num_passwords == 0) {
                printf("No passwords to edit.\n");
            } else {
                printf("Enter username of password to edit: ");
                scanf(" %s", passwords[0].username);
                printf("Enter new password: ");
                scanf(" %s", passwords[0].password);
                passwords[0].last_modified = time(NULL);
            }
            break;

        case '3':
            if (num_passwords == 0) {
                printf("No passwords to delete.\n");
            } else {
                printf("Enter username of password to delete: ");
                scanf(" %s", passwords[0].username);
                num_passwords--;
            }
            break;

        case '4':
            if (num_passwords == 0) {
                printf("No passwords to view.\n");
            } else {
                printf("Passwords:\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("Username: %s\nPassword: %s\nLast Modified: %s\n", passwords[i].username, passwords[i].password, ctime(&passwords[i].last_modified));
                }
            }
            break;

        case '5':
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}