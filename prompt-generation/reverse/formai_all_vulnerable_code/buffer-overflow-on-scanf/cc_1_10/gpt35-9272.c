//FormAI DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

typedef struct User {
    char name[20];
    char password[20];
    int id;
} User;

User users[MAX_USERS];
int num_users = 0;

void add_user() {
    if (num_users >= MAX_USERS) {
        printf("Maximum number of users reached!\n");
        return;
    }

    User new_user;
    printf("Enter name: ");
    scanf("%s", new_user.name);
    printf("Enter password: ");
    scanf("%s", new_user.password);
    new_user.id = num_users;
    users[num_users++] = new_user;

    printf("User added successfully!\n");
}

void delete_user() {
    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);

    if (id < 0 || id >= num_users) {
        printf("Invalid user ID!\n");
        return;
    }

    for (int i = id; i < num_users - 1; i++) {
        users[i] = users[i+1];
    }

    num_users--;
    printf("User deleted successfully!\n");
}

void list_users() {
    printf("ID\tName\tPassword\n");
    for (int i = 0; i < num_users; i++) {
        printf("%d\t%s\t%s\n", users[i].id, users[i].name, users[i].password);
    }
}

int main() {
    while (1) {
        printf("\n");
        printf("1. Add user\n");
        printf("2. Delete user\n");
        printf("3. List users\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_user();
                break;
            case 2:
                delete_user();
                break;
            case 3:
                list_users();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}