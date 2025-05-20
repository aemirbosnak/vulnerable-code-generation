//Falcon-180B DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

typedef struct {
    char username[20];
    char password[20];
} User;

void create_user(User *users, int *num_users) {
    printf("Enter username: ");
    scanf("%s", users[*num_users].username);
    printf("Enter password: ");
    scanf("%s", users[*num_users].password);
    (*num_users)++;
}

void login(User users[], int num_users, char *username, char *password) {
    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return;
        }
    }
    printf("Login failed.\n");
}

int main() {
    User users[MAX_USERS];
    int num_users = 0;

    while (num_users < MAX_USERS) {
        printf("1. Create user\n2. Login\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            create_user(users, &num_users);
            break;
        case 2:
            printf("Enter username: ");
            char username[20];
            scanf("%s", username);
            printf("Enter password: ");
            char password[20];
            scanf("%s", password);
            login(users, num_users, username, password);
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}