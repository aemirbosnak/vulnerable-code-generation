//Falcon-180B DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);

    num_passwords++;

    printf("Password added successfully!\n");
}

void delete_password() {
    int i;
    char username[MAX_PASSWORD_LENGTH];

    printf("Enter username to delete: ");
    scanf("%s", username);

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            memmove(&passwords[i], &passwords[i + 1], sizeof(Password) * (num_passwords - i - 1));

            num_passwords--;

            printf("Password deleted successfully!\n");

            return;
        }
    }

    printf("Password not found.\n");
}

void search_password() {
    char username[MAX_PASSWORD_LENGTH];
    int i;

    printf("Enter username to search: ");
    scanf("%s", username);

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password: %s\n", passwords[i].password);

            return;
        }
    }

    printf("Password not found.\n");
}

int main() {
    int choice;
    char username[MAX_PASSWORD_LENGTH];

    system("clear");

    printf("Welcome to the password manager!\n");

    while (1) {
        printf("\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Search password\n");
        printf("4. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;

        case 2:
            delete_password();
            break;

        case 3:
            printf("Enter username to search: ");
            scanf("%s", username);

            search_password();

            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}