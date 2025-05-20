//Falcon-180B DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

void createUser(User* user) {
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
}

void displayUser(User user) {
    printf("Username: %s\n", user.username);
    printf("Password: %s\n", user.password);
}

int main() {
    User users[MAX_USERS];
    int numUsers = 0;
    int userIndex;

    while (numUsers < MAX_USERS) {
        printf("Enter 1 to create a user, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (numUsers >= MAX_USERS) {
                printf("Maximum number of users reached.\n");
            } else {
                User* newUser = &users[numUsers];
                createUser(newUser);
                numUsers++;
            }
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    printf("User list:\n");

    for (userIndex = 0; userIndex < numUsers; userIndex++) {
        displayUser(users[userIndex]);
    }

    return 0;
}