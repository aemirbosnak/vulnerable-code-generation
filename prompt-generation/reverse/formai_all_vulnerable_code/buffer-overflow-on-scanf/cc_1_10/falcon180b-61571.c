//Falcon-180B DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER_COUNT 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_USER_COUNT];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USER_COUNT];
int userCount = 0;

void addUser() {
    printf("Enter username: ");
    scanf("%s", users[userCount].username);

    printf("Enter password: ");
    scanf("%s", users[userCount].password);

    userCount++;
}

void removeUser() {
    printf("Enter username to remove: ");
    char username[MAX_USER_COUNT];
    scanf("%s", username);

    int i;
    for (i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            userCount--;
            memmove(&users[i], &users[i + 1], sizeof(User) * (userCount - i));
            break;
        }
    }
}

void login() {
    printf("Enter username: ");
    char username[MAX_USER_COUNT];
    scanf("%s", username);

    int i;
    for (i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Enter password: ");
            char password[MAX_PASSWORD_LENGTH];
            scanf("%s", password);

            if (strcmp(users[i].password, password) == 0) {
                printf("Login successful!\n");
                return;
            } else {
                printf("Incorrect password.\n");
            }
        }
    }

    printf("User not found.\n");
}

int main() {
    int choice;

    do {
        printf("1. Add user\n");
        printf("2. Remove user\n");
        printf("3. Login\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addUser();
            break;
        case 2:
            removeUser();
            break;
        case 3:
            login();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}