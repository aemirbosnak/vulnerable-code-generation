//FormAI DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20
#define MASTER_PASSWORD "secret"

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char value[MAX_PASSWORD_LENGTH];
};

int password_count = 0;
struct Password password_list[MAX_PASSWORDS];

int auth_user() {
    char master_password[MAX_PASSWORD_LENGTH];

    printf("Enter Master Password: ");
    scanf("%s", master_password);

    return strcmp(master_password, MASTER_PASSWORD) == 0;
}

void print_passwords() {
    printf("Password List:\n");

    for (int i = 0; i < password_count; i++) {
        printf("%d.\t%s: %s\n", i + 1, password_list[i].name, password_list[i].value);
    }
}

void add_password() {
    printf("Enter password name: ");
    scanf("%s", password_list[password_count].name);

    printf("Enter password value: ");
    scanf("%s", password_list[password_count].value);

    password_count++;
}

void delete_password() {
    int index;

    printf("Enter password index: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= password_count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < password_count - 1; i++) {
        password_list[i] = password_list[i + 1];
    }

    password_count--;
    printf("Password successfully deleted.\n");
}

int main() {
    int selection;

    if (!auth_user()) {
        printf("Invalid master password.\n");
        exit(1);
    }

    printf("Welcome to the Password Manager!\n");

    while (1) {
        printf("\n");

        printf("1. Print Passwords\n");
        printf("2. Add Password\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");

        printf("Enter selection: ");
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                print_passwords();
                break;
            case 2:
                add_password();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid selection.\n");
                break;
        }
    }

    return 0;
}