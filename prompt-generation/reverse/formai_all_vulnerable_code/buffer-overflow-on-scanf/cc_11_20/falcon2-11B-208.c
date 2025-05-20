//Falcon2-11B DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* username;
    char* password;
} user;

int main() {
    user users[5] = {
        {"user1", "password1"},
        {"user2", "password2"},
        {"user3", "password3"},
        {"user4", "password4"},
        {"user5", "password5"}
    };

    int num_users = sizeof(users) / sizeof(user);

    int choice;
    int user_index;
    char* username;
    char* password;

    printf("Welcome to the password manager!\n");
    printf("Please choose an option:\n");
    printf("1. Add a new user\n");
    printf("2. View all users\n");
    printf("3. Search for a user\n");
    printf("4. Change a user's password\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the username for the new user: ");
            scanf("%s", username);
            printf("Enter the password for the new user: ");
            scanf("%s", password);
            user_index = sizeof(users) / sizeof(user);
            users[user_index].username = username;
            users[user_index].password = password;
            break;
        case 2:
            printf("Username: ");
            scanf("%s", username);
            for (int i = 0; i < num_users; i++) {
                if (strcmp(users[i].username, username) == 0) {
                    printf("Username: %s\n", users[i].username);
                    printf("Password: %s\n", users[i].password);
                    break;
                }
            }
            break;
        case 3:
            printf("Username: ");
            scanf("%s", username);
            for (int i = 0; i < num_users; i++) {
                if (strcmp(users[i].username, username) == 0) {
                    printf("Username: %s\n", users[i].username);
                    printf("Password: %s\n", users[i].password);
                    break;
                }
            }
            break;
        case 4:
            printf("Enter the username for the user whose password you want to change: ");
            scanf("%s", username);
            for (int i = 0; i < num_users; i++) {
                if (strcmp(users[i].username, username) == 0) {
                    printf("Enter the new password for %s: ", username);
                    scanf("%s", password);
                    users[i].password = password;
                    break;
                }
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}