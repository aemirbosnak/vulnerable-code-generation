//Falcon-180B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

struct password {
    char *service;
    char *username;
    char *password;
};

int num_passwords = 0;
struct password passwords[MAX_PASSWORDS];

void add_password() {
    char service[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter service name: ");
    scanf("%s", service);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    passwords[num_passwords].service = strdup(service);
    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);

    num_passwords++;
}

void remove_password() {
    int i;
    char service[MAX_PASSWORD_LENGTH];

    printf("Enter service name to remove: ");
    scanf("%s", service);

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].service, service) == 0) {
            free(passwords[i].service);
            free(passwords[i].username);
            free(passwords[i].password);

            memmove(&passwords[i], &passwords[i+1], (num_passwords - i - 1) * sizeof(struct password));

            num_passwords--;
            break;
        }
    }
}

void list_passwords() {
    int i;

    printf("Service\tUsername\tPassword\n");
    for (i = 0; i < num_passwords; i++) {
        printf("%s\t%s\t%s\n", passwords[i].service, passwords[i].username, passwords[i].password);
    }
}

void main() {
    int choice;

    printf("Password Manager\n");
    printf("1. Add password\n");
    printf("2. Remove password\n");
    printf("3. List passwords\n");
    printf("4. Exit\n");

    do {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                remove_password();
                break;
            case 3:
                list_passwords();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
}