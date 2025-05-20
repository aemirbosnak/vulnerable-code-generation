//Falcon-180B DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void delete_password() {
    if (num_passwords == 0) {
        printf("Error: No passwords saved.\n");
        return;
    }

    printf("Enter username to delete: ");
    scanf("%s", passwords[num_passwords - 1].username);

    num_passwords--;
}

void edit_password() {
    if (num_passwords == 0) {
        printf("Error: No passwords saved.\n");
        return;
    }

    printf("Enter username to edit: ");
    scanf("%s", passwords[num_passwords - 1].username);

    printf("Enter new password: ");
    scanf("%s", passwords[num_passwords - 1].password);
}

void view_passwords() {
    if (num_passwords == 0) {
        printf("No passwords saved.\n");
        return;
    }

    printf("Username\t\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    printf("Welcome to Password Manager!\n");

    while (1) {
        printf("\n1. Add password\n2. Delete password\n3. Edit password\n4. View passwords\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            delete_password();
            break;
        case 3:
            edit_password();
            break;
        case 4:
            view_passwords();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}