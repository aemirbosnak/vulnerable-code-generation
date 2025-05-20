//Falcon-180B DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER 100
#define MAX_PASSWORD_LENGTH 50

struct user {
    char username[MAX_USER];
    char password[MAX_PASSWORD_LENGTH];
};

void create_user(struct user *user) {
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
}

void login(struct user *user, char *username, char *password) {
    if (strcmp(user->username, username) == 0 && strcmp(user->password, password) == 0) {
        printf("Login successful!\n");
    } else {
        printf("Login failed.\n");
    }
}

int main() {
    struct user user_list[MAX_USER];
    int num_users = 0;
    char choice;

    while (1) {
        printf("\nPassword Management System\n");
        printf("1. Create user\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter number of users: ");
                scanf("%d", &num_users);

                for (int i = 0; i < num_users; i++) {
                    create_user(&user_list[i]);
                }
                break;

            case '2':
                printf("Enter username: ");
                scanf("%s", user_list[0].username);
                printf("Enter password: ");
                scanf("%s", user_list[0].password);

                login(&user_list[0], user_list[0].username, user_list[0].password);
                break;

            case '3':
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}