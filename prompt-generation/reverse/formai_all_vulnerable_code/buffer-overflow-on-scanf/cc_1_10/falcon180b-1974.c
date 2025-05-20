//Falcon-180B DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void view_passwords() {
    if (num_passwords == 0) {
        printf("No passwords saved.\n");
        return;
    }

    printf("Username\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void delete_password(char* username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memset(passwords[i].username, 0, MAX_USERNAME_LENGTH);
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);

            num_passwords--;
            printf("Password deleted.\n");
            return;
        }
    }

    printf("Password not found.\n");
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome to the password manager.\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Delete password\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            add_password(username, password);
            break;

        case 2:
            view_passwords();
            break;

        case 3:
            printf("Enter username to delete: ");
            scanf("%s", username);

            delete_password(username);
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}