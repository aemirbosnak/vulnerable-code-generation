//Falcon-180B DATASET v1.0 Category: Password management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} user_t;

void add_user(user_t *users, int *num_users) {
    printf("Enter username: ");
    scanf("%s", users[*num_users].username);
    printf("Enter password: ");
    scanf("%s", users[*num_users].password);

    (*num_users)++;
}

void login(user_t *users, int num_users, char *username, char *password) {
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
    user_t users[MAX_USERS];
    int num_users = 0;

    while (num_users < MAX_USERS) {
        printf("1. Add user\n2. Login\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user(users, &num_users);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", users[0].username);
                printf("Enter password: ");
                scanf("%s", users[0].password);

                if (num_users > 1) {
                    printf("Enter username: ");
                    scanf("%s", users[1].username);
                    printf("Enter password: ");
                    scanf("%s", users[1].password);
                }

                login(users, num_users, users[0].username, users[0].password);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}