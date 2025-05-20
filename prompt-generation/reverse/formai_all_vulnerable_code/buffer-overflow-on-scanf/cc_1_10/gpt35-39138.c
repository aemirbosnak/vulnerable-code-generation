//FormAI DATASET v1.0 Category: System administration ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 32
#define MAX_USERS 10

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int num_users = 0;

void create_user();
bool login();

int main() {
    while (true) {
        printf("Choose an option:\n");
        printf("1. Create user\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                create_user();
                break;
            case 2:
                if (login()) {
                    printf("Success!\n");
                } else {
                    printf("Login failed.\n");
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}

void create_user() {
    if (num_users == MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[num_users].username);
    printf("Enter password: ");
    scanf("%s", users[num_users].password);
    num_users++;
}

bool login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    for (int i = 0; i < strlen(username); i++) {
        username[i] = tolower(username[i]);
    }
    printf("Enter password: ");
    scanf("%s", password);
    for (int i = 0; i < num_users; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return true;
        }
    }
    return false;
}