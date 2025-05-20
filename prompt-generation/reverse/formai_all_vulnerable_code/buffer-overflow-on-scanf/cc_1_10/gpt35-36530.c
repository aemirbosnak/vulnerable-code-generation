//FormAI DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 50

typedef struct {
    char username[20];
    char password[20];
} User;

void add_user(User users[], int* num_users) {
    if (*num_users < MAX_USERS) {
        User new_user;
        printf("Enter username: ");
        scanf("%s", new_user.username);
        printf("Enter password: ");
        scanf("%s", new_user.password);
        users[*num_users] = new_user;
        (*num_users)++;
        printf("User %s added successfully!\n", new_user.username);
    } else {
        printf("Max number of users reached. Cannot add more users.\n");
    }
}

void change_password(User users[], int num_users, char* username) {
    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Enter new password: ");
            scanf("%s", users[i].password);
            printf("Password updated successfully!\n");
            return;
        }
    }
    printf("User %s not found. Password not changed.\n", username);
}

int main() {
    User users[MAX_USERS];
    int num_users = 0;

    while (1) {
        printf("1. Add user\n");
        printf("2. Change password\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_user(users, &num_users);
                break;
            case 2:
                {
                    char username[20];
                    printf("Enter username: ");
                    scanf("%s", username);
                    change_password(users, num_users, username);
                }
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}