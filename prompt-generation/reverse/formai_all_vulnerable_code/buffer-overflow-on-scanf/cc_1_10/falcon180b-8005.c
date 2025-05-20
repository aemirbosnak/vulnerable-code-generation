//Falcon-180B DATASET v1.0 Category: Password management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    printf("Enter website:\n");
    scanf("%s", passwords[num_passwords].website);

    printf("Enter username:\n");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password:\n");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void view_passwords() {
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\n", passwords[i].website);
        printf("%s\n", passwords[i].username);
        printf("%s\n\n", passwords[i].password);
    }
}

void delete_password() {
    printf("Enter password to delete:\n");
    char password_to_delete[MAX_PASSWORD_LENGTH];
    scanf("%s", password_to_delete);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(password_to_delete, passwords[i].password) == 0) {
            memmove(&passwords[i], &passwords[i+1], sizeof(Password) * (num_passwords - i - 1));
            num_passwords--;
            printf("Password deleted.\n");
            return;
        }
    }

    printf("Password not found.\n");
}

int main() {
    char choice;

    while (1) {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Delete password\n");
        printf("4. Exit\n");
        printf("Enter choice:\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_password();
                break;
            case '2':
                view_passwords();
                break;
            case '3':
                delete_password();
                break;
            case '4':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}