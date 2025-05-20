//Falcon-180B DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USER 100
#define MAX_PASSWORD 20

struct user {
    char username[MAX_USER];
    char password[MAX_PASSWORD];
};

void createUser(struct user *user) {
    printf("Enter username: ");
    scanf("%s", user->username);

    printf("Enter password: ");
    scanf("%s", user->password);
}

int authenticateUser(struct user *user, char *username, char *password) {
    if (strcmp(user->username, username)!= 0) {
        return 0;
    }

    if (strcmp(user->password, password) == 0) {
        return 1;
    }

    return 0;
}

void changePassword(struct user *user) {
    printf("Enter new password: ");
    scanf("%s", user->password);
}

int main() {
    struct user user;

    int choice;
    char username[MAX_USER];
    char password[MAX_PASSWORD];

    do {
        printf("Enter 1 to create user\n");
        printf("Enter 2 to login\n");
        printf("Enter 3 to change password\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter username: ");
            scanf("%s", username);
            createUser(&user);
            printf("User %s created successfully\n", username);
            break;

        case 2:
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            if (authenticateUser(&user, username, password)) {
                printf("Login successful\n");
            } else {
                printf("Login failed\n");
            }
            break;

        case 3:
            printf("Enter username: ");
            scanf("%s", username);

            if (authenticateUser(&user, username, password)) {
                changePassword(&user);
                printf("Password changed successfully\n");
            } else {
                printf("Login failed\n");
            }
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}