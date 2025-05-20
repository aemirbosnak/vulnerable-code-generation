//Falcon-180B DATASET v1.0 Category: Password management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER 100
#define MAX_PASSWORD 50

typedef struct {
    char username[MAX_USER];
    char password[MAX_PASSWORD];
} user_t;

void add_user(user_t *user, int num_users)
{
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
}

void login(user_t *user, int num_users)
{
    char username[MAX_USER];
    char password[MAX_PASSWORD];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(user[i].username, username) == 0 && strcmp(user[i].password, password) == 0) {
            printf("Login successful!\n");
            return;
        }
    }

    printf("Login failed.\n");
}

int main()
{
    int num_users;
    printf("Enter number of users: ");
    scanf("%d", &num_users);

    user_t *user = (user_t *)malloc(num_users * sizeof(user_t));

    int i;
    for (i = 0; i < num_users; i++) {
        add_user(&user[i], num_users);
    }

    while (1) {
        int choice;
        printf("\n1. Login\n2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            login(user, num_users);
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    free(user);
    return 0;
}