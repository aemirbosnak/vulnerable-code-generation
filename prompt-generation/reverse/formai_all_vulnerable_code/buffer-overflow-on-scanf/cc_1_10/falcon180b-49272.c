//Falcon-180B DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int is_valid;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    passwords[num_passwords].is_valid = 1;
    num_passwords++;
}

void delete_password() {
    printf("Enter username: ");
    char username[MAX_PASSWORD_LENGTH];
    scanf("%s", username);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            passwords[i].is_valid = 0;
            printf("Password deleted.\n");
            return;
        }
    }

    printf("Password not found.\n");
}

void list_passwords() {
    printf("Username\tPassword\tValid\n");
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (passwords[i].is_valid) {
            printf("%s\t\t%s\t\tYes\n", passwords[i].username, passwords[i].password);
        } else {
            printf("%s\t\t%s\t\tNo\n", passwords[i].username, passwords[i].password);
        }
    }
}

void main() {
    int choice;

    while (1) {
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. List passwords\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                delete_password();
                break;
            case 3:
                list_passwords();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}