//FormAI DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERNAME 20
#define MAX_PASSWORD 20

typedef struct {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
} User;

void create_account(User* users, int* num_users) {
    if (*num_users == 10) {
        printf("Maximum number of users reached.\n");
        return;
    }

    printf("Enter a username (max %d characters): ", MAX_USERNAME);
    scanf("%s", users[*num_users].username);
    printf("Enter a password (max %d characters): ", MAX_PASSWORD);
    scanf("%s", users[*num_users].password);
    *num_users += 1;
}

void change_password(User* users, int num_users, char* username) {
    bool success = false;
    char new_password[MAX_PASSWORD];
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Enter a new password (max %d characters): ", MAX_PASSWORD);
            scanf("%s", new_password);
            strcpy(users[i].password, new_password);
            printf("Password changed.\n");
            success = true;
            break;
        }
    }
    if (!success) {
        printf("Username not found.\n");
    }
}

int main() {
    User users[10];
    int num_users = 0;
    bool running = true;

    while (running) {
        printf("Select an option:\n");
        printf("1. Create an account\n");
        printf("2. Change a password\n");
        printf("3. Quit\n");
        printf("> ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(users, &num_users);
                break;
            case 2:
                printf("Enter a username: ");
                char username[MAX_USERNAME];
                scanf("%s", username);
                change_password(users, num_users, username);
                break;
            case 3:
                running = false;
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}