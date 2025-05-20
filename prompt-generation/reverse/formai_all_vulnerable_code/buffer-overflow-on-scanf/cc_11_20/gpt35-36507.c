//FormAI DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];

int main() {
    int option;
    int num_users = 0;

    while (1) {
        printf("\nPassword Management System\n");
        printf("1. Create User\n");
        printf("2. Change Password\n");
        printf("3. Delete User\n");
        printf("4. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        // Create User
        if (option == 1) {
            if (num_users < MAX_USERS) {
                printf("Enter username: ");
                scanf("%s", users[num_users].username);

                printf("Enter password: ");
                scanf("%s", users[num_users].password);

                num_users++;
                printf("User created successfully!\n");
            } else {
                printf("Maximum number of users reached.\n");
            }
        }

        // Change Password
        else if (option == 2) {
            char username[MAX_PASSWORD_LENGTH];
            char old_password[MAX_PASSWORD_LENGTH];
            char new_password[MAX_PASSWORD_LENGTH];

            printf("Enter username: ");
            scanf("%s", username);

            printf("Enter old password: ");
            scanf("%s", old_password);

            int user_index = -1;
            for (int i = 0; i < num_users; i++) {
                if (strcmp(users[i].username, username) == 0 &&
                    strcmp(users[i].password, old_password) == 0) {
                    user_index = i;
                    break;
                }
            }

            if (user_index != -1) {
                printf("Enter new password: ");
                scanf("%s", new_password);

                strcpy(users[user_index].password, new_password);

                printf("Password changed successfully!\n");
            } else {
                printf("Wrong username or password.\n");
            }
        }

        // Delete User
        else if (option == 3) {
            char username[MAX_PASSWORD_LENGTH];
            char password[MAX_PASSWORD_LENGTH];

            printf("Enter username: ");
            scanf("%s", username);

            printf("Enter password: ");
            scanf("%s", password);

            int user_index = -1;
            for (int i = 0; i < num_users; i++) {
                if (strcmp(users[i].username, username) == 0 &&
                    strcmp(users[i].password, password) == 0) {
                    user_index = i;
                    break;
                }
            }

            if (user_index != -1) {
                for (int i = user_index; i < num_users - 1; i++) {
                    strcpy(users[i].username, users[i + 1].username);
                    strcpy(users[i].password, users[i + 1].password);
                }

                num_users--;
                printf("User deleted successfully!\n");
            } else {
                printf("Wrong username or password.\n");
            }
        }

        // Exit
        else if (option == 4) {
            printf("Exiting...\n");
            exit(0);
        }
    }

    return 0;
}