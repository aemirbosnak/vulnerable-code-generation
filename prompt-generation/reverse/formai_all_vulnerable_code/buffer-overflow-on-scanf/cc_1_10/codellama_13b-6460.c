//Code Llama-13B DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_USERS 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    time_t last_login;
} user_t;

user_t users[MAX_USERS];
int num_users = 0;

void add_user(char *username, char *password) {
    if (num_users >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    users[num_users].last_login = time(NULL);
    num_users++;
}

void delete_user(char *username) {
    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            memmove(&users[i], &users[i + 1], (num_users - i - 1) * sizeof(user_t));
            num_users--;
            return;
        }
    }
}

void change_password(char *username, char *new_password) {
    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            strcpy(users[i].password, new_password);
            return;
        }
    }
}

int main() {
    char command[100];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];
    while (1) {
        printf("Enter a command (add, delete, change, or quit): ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            printf("Enter a username: ");
            scanf("%s", username);
            printf("Enter a password: ");
            scanf("%s", password);
            add_user(username, password);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter a username: ");
            scanf("%s", username);
            delete_user(username);
        } else if (strcmp(command, "change") == 0) {
            printf("Enter a username: ");
            scanf("%s", username);
            printf("Enter a new password: ");
            scanf("%s", new_password);
            change_password(username, new_password);
        } else if (strcmp(command, "quit") == 0) {
            break;
        }
    }
    return 0;
}