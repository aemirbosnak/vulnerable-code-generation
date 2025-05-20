//Falcon-180B DATASET v1.0 Category: Password management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

int num_passwords = 0;
password_t passwords[MAX_PASSWORDS];

void add_password(char *name, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Too many passwords.\n");
        return;
    }

    strncpy(passwords[num_passwords].name, name, MAX_PASSWORD_LENGTH);
    strncpy(passwords[num_passwords].password, password, MAX_PASSWORD_LENGTH);

    num_passwords++;
}

void delete_password(char *name) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            memset(&passwords[i], 0, sizeof(password_t));
            num_passwords--;
            return;
        }
    }

    printf("Error: Password not found.\n");
}

void list_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("Name: %s\nPassword: %s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char choice;

    do {
        printf("Password Manager\n");
        printf("1. Add password\n2. Delete password\n3. List passwords\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter password: ");
            scanf("%s", password);
            add_password(name, password);
            break;
        case '2':
            printf("Enter name: ");
            scanf("%s", name);
            delete_password(name);
            break;
        case '3':
            list_passwords();
            break;
        case '4':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}