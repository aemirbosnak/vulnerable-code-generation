//Falcon-180B DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char username[MAX_USERS];
    char password[MAX_PASSWORD_LENGTH];
    time_t last_updated;
} User;

void initialize_user(User* user) {
    strcpy(user->username, "");
    strcpy(user->password, "");
    user->last_updated = 0;
}

int compare_users(User* user1, User* user2) {
    return strcmp(user1->username, user2->username);
}

void print_user(User* user) {
    printf("Username: %s\n", user->username);
    printf("Password: %s\n", user->password);
    printf("Last updated: %s", ctime(&user->last_updated));
}

int main() {
    User users[MAX_USERS];
    int num_users = 0;
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add user\n");
        printf("2. Edit user\n");
        printf("3. Delete user\n");
        printf("4. View all users\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter username: ");
            scanf("%s", users[num_users].username);
            initialize_user(&users[num_users]);
            num_users++;
            break;
        case 2:
            printf("Enter username of user to edit: ");
            scanf("%s", users[num_users].username);
            initialize_user(&users[num_users]);
            num_users++;
            break;
        case 3:
            printf("Enter username of user to delete: ");
            scanf("%s", users[num_users].username);
            num_users--;
            break;
        case 4:
            qsort(users, num_users, sizeof(User), compare_users);
            for (int i = 0; i < num_users; i++) {
                print_user(&users[i]);
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}