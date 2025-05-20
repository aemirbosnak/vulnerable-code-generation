//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_USERS 100
#define PASSWORD_LENGTH 25

typedef struct {
    char name[50];
    char password[PASSWORD_LENGTH + 1];
} User;

User users[MAX_USERS];
int user_count = 0;

void create_user(char name[], char password[]) {
    if (user_count >= MAX_USERS) {
        printf("Max number of users reached!\n");
        return;
    }

    strcpy(users[user_count].name, name);
    strcpy(users[user_count].password, password);
    user_count++;
}

int authenticate_user(char name[], char password[]) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].name, name) == 0 && strcmp(users[i].password, password) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    int choice, userId;
    char name[50], password[PASSWORD_LENGTH];

    while (1) {
        printf("\n1. Create User\n2. Authenticate User\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter password: ");
                scanf("%s", password);
                create_user(name, password);
                break;

            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter password: ");
                scanf("%s", password);
                userId = authenticate_user(name, password);

                if (userId != -1) {
                    printf("Authentication successful! User ID: %d\n", userId);
                } else {
                    printf("Authentication failed!\n");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}