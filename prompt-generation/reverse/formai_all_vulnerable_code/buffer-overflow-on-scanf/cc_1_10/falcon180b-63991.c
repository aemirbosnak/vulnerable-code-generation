//Falcon-180B DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER 10
#define MAX_PASS 20

struct User {
    char username[MAX_USER];
    char password[MAX_PASS];
};

void addUser(struct User* users, int numUsers, char* username, char* password) {
    if (numUsers == MAX_USER) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }
    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    numUsers++;
}

int authenticateUser(struct User* users, int numUsers, char* username, char* password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    struct User users[MAX_USER];
    int numUsers = 0;

    char choice;
    while (1) {
        printf("1. Add user\n");
        printf("2. Authenticate user\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter username: ");
                char username[MAX_USER];
                scanf("%s", username);
                printf("Enter password: ");
                char password[MAX_PASS];
                scanf("%s", password);
                addUser(users, numUsers, username, password);
                break;
            case '2':
                printf("Enter username: ");
                char authUsername[MAX_USER];
                scanf("%s", authUsername);
                printf("Enter password: ");
                char authPassword[MAX_PASS];
                scanf("%s", authPassword);
                if (authenticateUser(users, numUsers, authUsername, authPassword)) {
                    printf("Authentication successful.\n");
                } else {
                    printf("Authentication failed.\n");
                }
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}