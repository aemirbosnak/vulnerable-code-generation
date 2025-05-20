//Falcon-180B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 100

typedef struct password_t {
    char* name;
    char* password;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char name[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];

    printf("Enter the name of the account: ");
    scanf("%s", name);

    printf("Enter the password: ");
    scanf("%s", password);

    if (num_passwords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    num_passwords++;
    passwords[num_passwords - 1].name = malloc(strlen(name) + 1);
    strcpy(passwords[num_passwords - 1].name, name);
    passwords[num_passwords - 1].password = malloc(strlen(password) + 1);
    strcpy(passwords[num_passwords - 1].password, password);

    printf("Password added successfully.\n");
}

void view_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("Name: %s\nPassword: %s\n\n", passwords[i].name, passwords[i].password);
    }
}

void search_password() {
    char name[MAX_PASSWORD_LEN];

    printf("Enter the name of the account: ");
    scanf("%s", name);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("Name: %s\nPassword: %s\n\n", passwords[i].name, passwords[i].password);
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add password\n2. View passwords\n3. Search password\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            view_passwords();
            break;
        case 3:
            search_password();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}