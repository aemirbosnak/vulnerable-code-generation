//Falcon-180B DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_USERS];
    char password[MAX_PASSWORD_LENGTH];
} user_t;

user_t users[MAX_USERS];
int num_users = 0;

void add_user() {
    printf("Enter a username: ");
    scanf("%s", users[num_users].username);

    printf("Enter a password: ");
    scanf("%s", users[num_users].password);

    num_users++;
}

void remove_user() {
    printf("Enter a username to remove: ");
    scanf("%s", users[num_users-1].username);

    num_users--;
}

void change_password() {
    printf("Enter a username: ");
    scanf("%s", users[num_users-1].username);

    printf("Enter a new password: ");
    scanf("%s", users[num_users-1].password);
}

void print_users() {
    printf("Username\tPassword\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s\t\t%s\n", users[i].username, users[i].password);
    }
}

int main() {
    printf("Welcome to the password manager!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add user\n");
        printf("2. Remove user\n");
        printf("3. Change password\n");
        printf("4. Print users\n");
        printf("0. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                remove_user();
                break;
            case 3:
                change_password();
                break;
            case 4:
                print_users();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}