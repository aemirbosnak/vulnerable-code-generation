//FormAI DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 30

typedef struct {
    char username[30];
    char password[MAX_PASSWORD_LENGTH];
} user;

user users[MAX_USERS];
int num_users = 0;

void clearInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addUser() {
    if (num_users == MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    user new_user;

    printf("Enter a username (max 30 characters):\n");
    fgets(new_user.username, 30, stdin);

    int length = strlen(new_user.username);
    if (new_user.username[length - 1] == '\n')
        new_user.username[length - 1] = '\0';

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, new_user.username) == 0) {
            printf("Username already exists.\n");
            return;
        }
    }

    printf("Enter a password (max %d characters):\n", MAX_PASSWORD_LENGTH);
    fgets(new_user.password, MAX_PASSWORD_LENGTH, stdin);

    length = strlen(new_user.password);
    if (new_user.password[length - 1] == '\n')
        new_user.password[length - 1] = '\0';

    strcpy(users[num_users].username, new_user.username);
    strcpy(users[num_users].password, new_user.password);
    num_users++;
    printf("User added successfully.\n");
}

void authenticate() {
    if (num_users == 0) {
        printf("No users registered.\n");
        return;
    }

    char username[30];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a username:\n");
    fgets(username, 30, stdin);

    int length = strlen(username);
    if (username[length - 1] == '\n')
        username[length - 1] = '\0';
    
    int found = 0;
    int index = 0;
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            found = 1;
            index = i;
            break;
        }
    }

    if (!found) {
        printf("Invalid username.\n");
        return;
    }

    printf("Enter a password:\n");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    length = strlen(password);
    if (password[length - 1] == '\n')
        password[length - 1] = '\0';

    if (strcmp(users[index].password, password) == 0) {
        printf("Authentication successful.\n");
    } else {
        printf("Incorrect password.\n");
    }
}

int main() {
    printf("Welcome to Retro Password Manager!\n");

    while (1) {
        printf("Available Options:\n");
        printf("1. Add User\n");
        printf("2. Authenticate\n");
        printf("3. Exit\n");
        printf("Enter option number:\n");

        int option;
        scanf("%d", &option);
        clearInput();

        switch (option) {
            case 1:
                addUser();
                break;
            case 2:
                authenticate();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}