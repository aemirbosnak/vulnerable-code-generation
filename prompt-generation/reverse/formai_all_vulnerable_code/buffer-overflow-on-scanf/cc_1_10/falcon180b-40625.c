//Falcon-180B DATASET v1.0 Category: Password management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASS_LEN 20
#define MAX_USERS 100

struct user {
    char username[20];
    char password[MAX_PASS_LEN];
    int uid;
};

void create_user(struct user *user) {
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
    user->uid = rand();
}

int login(struct user users[], int num_users, char *username, char *password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return users[i].uid;
        }
    }
    return -1;
}

int main() {
    struct user users[MAX_USERS];
    int num_users = 0;
    int choice;
    char username[20];
    char password[MAX_PASS_LEN];

    srand(time(NULL));

    while (1) {
        printf("\n");
        printf("1. Create user\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_users >= MAX_USERS) {
                printf("Maximum number of users reached.\n");
            } else {
                struct user new_user;
                create_user(&new_user);
                strcpy(users[num_users].username, new_user.username);
                strcpy(users[num_users].password, new_user.password);
                num_users++;
            }
            break;

        case 2:
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            int user_id = login(users, num_users, username, password);

            if (user_id!= -1) {
                printf("Welcome, user %d!\n", user_id);
            } else {
                printf("Invalid username or password.\n");
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}