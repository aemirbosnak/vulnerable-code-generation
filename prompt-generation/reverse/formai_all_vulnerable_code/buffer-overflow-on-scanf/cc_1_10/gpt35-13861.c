//FormAI DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_USERS 10
#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50

struct User {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
};

void create_user(struct User* users, int* num_users) {
    if ((*num_users) < MAX_USERS) {
        struct User* user = &users[(*num_users)];
        printf("Enter username: ");
        scanf("%s", user->username);
        printf("Enter password: ");
        scanf("%s", user->password);
        (*num_users)++;
        printf("User %s created\n", user->username);
    } else {
        printf("Exceeded maximum number of users\n");
    }
}

void delete_user(struct User* users, int* num_users) {
    printf("Enter username to delete: ");
    char delete_username[MAX_USERNAME_LEN];
    scanf("%s", delete_username);
    for (int i = 0; i < (*num_users); i++) {
        struct User* user = &users[i];
        if (strcmp(user->username, delete_username) == 0) {
            // Shift all subsequent users to remove deleted user from array
            for (int j = i; j < (*num_users) - 1; j++) {
                users[j] = users[j+1];
            }
            memset(&users[(*num_users) - 1], 0, sizeof(struct User));
            (*num_users)--;
            printf("User %s deleted\n", delete_username);
            return;
        }
    }
    printf("User %s not found\n", delete_username);
}

void list_users(struct User* users, int num_users) {
    printf("Total users: %d\n", num_users);
    for (int i = 0; i < num_users; i++) {
        printf("%s\n", users[i].username);
    }
}

int main() {
    struct User users[MAX_USERS];
    int num_users = 0;
    int option = 0;
    do {
        printf("\nUser account management\n");
        printf("1. Create user\n");
        printf("2. Delete user\n");
        printf("3. List users\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                create_user(users, &num_users);
                break;
            case 2:
                delete_user(users, &num_users);
                break;
            case 3:
                list_users(users, num_users);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 4);
    return 0;
}