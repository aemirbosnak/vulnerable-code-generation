//FormAI DATASET v1.0 Category: System administration ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char name[50];
    char password[50];
    int id;
};

void create_user(struct user *users, int *user_count) {
    printf("Enter username: ");
    scanf("%s", users[*user_count].name);
    printf("Enter password: ");
    scanf("%s", users[*user_count].password);
    users[*user_count].id = *user_count;
    *user_count += 1;
    printf("User created successfully!\n");
}

void delete_user(struct user *users, int *user_count) {
    int id = 0;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);
    if (id < 0 || id >= *user_count) {
        printf("Invalid ID. Try again.\n");
        return;
    }
    for (int i = id; i < *user_count - 1; i++) {
        strcpy(users[i].name, users[i + 1].name);
        strcpy(users[i].password, users[i + 1].password);
        users[i].id = i;
    }
    *user_count -= 1;
    printf("User deleted successfully!\n");
}

void print_users(struct user *users, int user_count) {
    printf("ID\tUsername\n");
    for (int i = 0; i < user_count; i++) {
        printf("%d\t%s\n", users[i].id, users[i].name);
    }
}

int main() {
    struct user users[100];
    int user_count = 0;
    int choice = 0;

    while (1) {
        printf("Choose an option:\n");
        printf("1. Create a user\n");
        printf("2. Delete a user\n");
        printf("3. Print all users\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_user(users, &user_count);
                break;
            case 2:
                delete_user(users, &user_count);
                break;
            case 3:
                print_users(users, user_count);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }
    return 0;
}