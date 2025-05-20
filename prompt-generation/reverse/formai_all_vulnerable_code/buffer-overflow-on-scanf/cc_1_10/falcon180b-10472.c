//Falcon-180B DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
    int is_admin;
} user_t;

user_t users[MAX_USERS];
int num_users = 0;

void add_user(char *username, char *password, int is_admin) {
    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    users[num_users].is_admin = is_admin;
    num_users++;
}

int authenticate_user(char *username, char *password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    add_user("admin", "admin123", 1);
    add_user("user1", "user123", 0);
    add_user("user2", "user456", 0);

    int user_id;
    char username[50];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    user_id = authenticate_user(username, password);

    if (user_id == -1) {
        printf("Invalid credentials.\n");
    } else if (users[user_id].is_admin) {
        printf("Welcome, admin!\n");
    } else {
        printf("Welcome, user!\n");
    }

    return 0;
}