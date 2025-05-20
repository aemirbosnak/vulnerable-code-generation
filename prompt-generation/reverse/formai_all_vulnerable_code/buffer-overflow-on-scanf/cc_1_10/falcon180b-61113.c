//Falcon-180B DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} user;

user users[MAX_USERS];
int num_users = 0;

void add_user() {
    printf("Enter username: ");
    scanf("%s", users[num_users].username);
    printf("Enter password: ");
    scanf("%s", users[num_users].password);
    num_users++;
}

void view_users() {
    printf("Username\tPassword\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s\t%s\n", users[i].username, users[i].password);
    }
}

void delete_user() {
    printf("Enter username to delete: ");
    scanf("%s", users[num_users].username);
    num_users--;
}

void change_password() {
    printf("Enter username: ");
    scanf("%s", users[num_users].username);
    printf("Enter new password: ");
    scanf("%s", users[num_users].password);
}

void main() {
    int choice;
    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add user\n2. View users\n3. Delete user\n4. Change password\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_user();
            break;
        case 2:
            view_users();
            break;
        case 3:
            delete_user();
            break;
        case 4:
            change_password();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}