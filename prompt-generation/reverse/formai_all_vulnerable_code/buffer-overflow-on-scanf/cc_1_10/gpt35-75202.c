//FormAI DATASET v1.0 Category: Password management ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct user {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

int main() {
    User users[MAX_USERS];
    int user_count = 0;

    while (1) {
        printf("1. Create account\n2. Login\n3. Quit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            User user;
            printf("Enter username: ");
            scanf("%s", user.username);

            printf("Enter password: ");
            scanf("%s", user.password);

            users[user_count++] = user;
        } else if (choice == 2) {
            printf("Enter username: ");
            char username[MAX_PASSWORD_LENGTH];
            scanf("%s", username);

            printf("Enter password: ");
            char password[MAX_PASSWORD_LENGTH];
            scanf("%s", password);

            int i;
            for (i = 0; i < user_count; i++) {
                User user = users[i];
                if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
                    printf("Login successful!\n");
                    break;
                }
            }

            if (i == user_count) {
                printf("Invalid username/password combination.\n");
            }
        } else {
            printf("Goodbye!\n");
            exit(0);
        }
    }

    return 0;
}