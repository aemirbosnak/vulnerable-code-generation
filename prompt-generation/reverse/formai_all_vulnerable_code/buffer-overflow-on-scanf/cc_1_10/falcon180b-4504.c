//Falcon-180B DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_USER_COUNT 100

typedef struct {
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
} User;

int main() {
    User users[MAX_USER_COUNT];
    int userCount = 0;
    char choice;

    do {
        printf("Welcome to the Password Manager!\n");
        printf("Please choose an option:\n");
        printf("1. Add user\n");
        printf("2. Remove user\n");
        printf("3. Change password\n");
        printf("4. View all users\n");
        printf("5. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (userCount >= MAX_USER_COUNT) {
                printf("Error: Maximum user count reached.\n");
            } else {
                printf("Enter username (up to 20 characters): ");
                scanf("%s", users[userCount].username);
                printf("Enter password (up to %d characters): ", MAX_PASSWORD_LENGTH);
                scanf("%s", users[userCount].password);
                userCount++;
            }
            break;

        case '2':
            printf("Enter username to remove: ");
            scanf("%s", users[userCount - 1].username);
            userCount--;
            break;

        case '3':
            printf("Enter username to change password: ");
            scanf("%s", users[userCount - 1].username);
            printf("Enter new password (up to %d characters): ", MAX_PASSWORD_LENGTH);
            scanf("%s", users[userCount - 1].password);
            break;

        case '4':
            printf("List of users:\n");
            for (int i = 0; i < userCount; i++) {
                printf("%s: %s\n", users[i].username, users[i].password);
            }
            break;

        case '5':
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= '5');

    return 0;
}