//Falcon-180B DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

struct user {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct user users[MAX_USERS];
int num_users = 0;

void add_user() {
    char name[MAX_PASSWORD_LENGTH];
    printf("Enter the user's name: ");
    scanf("%s", name);

    int user_index = num_users;
    num_users++;

    strcpy(users[user_index].name, name);
    printf("Enter the user's password: ");
    scanf("%s", users[user_index].password);
}

void remove_user() {
    int user_index;
    printf("Enter the user index to remove: ");
    scanf("%d", &user_index);

    if (user_index < 0 || user_index >= num_users) {
        printf("Invalid user index.\n");
        return;
    }

    printf("User %s removed.\n", users[user_index].name);
    num_users--;
}

void list_users() {
    printf("Users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s\n", users[i].name);
    }
}

void login() {
    char name[MAX_PASSWORD_LENGTH];
    printf("Enter your name: ");
    scanf("%s", name);

    int user_index = -1;
    for (int i = 0; i < num_users; i++) {
        if (strcmp(name, users[i].name) == 0) {
            user_index = i;
            break;
        }
    }

    if (user_index == -1) {
        printf("User not found.\n");
        return;
    }

    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    if (strcmp(password, users[user_index].password)!= 0) {
        printf("Incorrect password.\n");
        return;
    }

    printf("Login successful.\n");
}

int main() {
    add_user();
    add_user();
    add_user();
    list_users();
    login();
    remove_user();
    list_users();

    return 0;
}