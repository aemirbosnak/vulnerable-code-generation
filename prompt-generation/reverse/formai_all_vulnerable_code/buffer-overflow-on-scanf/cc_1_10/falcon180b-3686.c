//Falcon-180B DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASS_LENGTH 100
#define MAX_USERS 100

typedef struct {
    char username[50];
    char password[MAX_PASS_LENGTH];
} user_t;

user_t users[MAX_USERS];
int num_users = 0;

void add_user() {
    if (num_users >= MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", users[num_users].username);

    printf("Enter password: ");
    fgets(users[num_users].password, MAX_PASS_LENGTH, stdin);
    users[num_users].password[strcspn(users[num_users].password, "\n")] = '\0';

    num_users++;
}

void delete_user() {
    printf("Enter username to delete: ");
    scanf("%s", users[num_users - 1].username);

    num_users--;
}

void view_users() {
    printf("Username\t\tPassword\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s\t\t%s\n", users[i].username, users[i].password);
    }
}

int main() {
    printf("Welcome to the password manager!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add user\n");
        printf("2. Delete user\n");
        printf("3. View all users\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                delete_user();
                break;
            case 3:
                view_users();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}