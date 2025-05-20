//Falcon-180B DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

struct password {
    char service[32];
    char username[32];
    char password[64];
};

struct password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    printf("Enter service name: ");
    scanf("%s", passwords[num_passwords].service);

    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void display_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("Service: %s\n", passwords[i].service);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n\n", passwords[i].password);
    }
}

int main() {
    printf("Welcome to Password Manager!\n");
    printf("Enter 1 to add a password or 2 to display passwords.\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            display_passwords();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}