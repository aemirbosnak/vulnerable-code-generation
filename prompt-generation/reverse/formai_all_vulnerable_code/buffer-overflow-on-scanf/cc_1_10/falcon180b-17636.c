//Falcon-180B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USER 100
#define MAX_PASSWORD 32

typedef struct {
    char username[MAX_USER];
    char password[MAX_PASSWORD];
} user;

user users[MAX_USER];
int num_users = 0;

void add_user() {
    char username[MAX_USER];
    char password[MAX_PASSWORD];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);

    num_users++;
}

void remove_user() {
    char username[MAX_USER];

    printf("Enter username to remove: ");
    scanf("%s", username);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            memset(&users[i], 0, sizeof(user));
            printf("User %s removed.\n", username);
            return;
        }
    }

    printf("User not found.\n");
}

void list_users() {
    printf("Users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s\n", users[i].username);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add user\n");
        printf("2. Remove user\n");
        printf("3. List users\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                remove_user();
                break;
            case 3:
                list_users();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}