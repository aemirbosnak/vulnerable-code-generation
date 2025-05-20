//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASS 25

typedef struct User {
    char username[MAX_PASS];
    char password[MAX_PASS];
} User;

User users[MAX_USERS];
int user_count = 0;

void create_user(const char* username, const char* password) {
    if (user_count >= MAX_USERS) {
        printf("Max users limit reached!\n");
        return;
    }

    strcpy(users[user_count].username, username);
    strcpy(users[user_count].password, password);
    user_count++;
}

void delete_user(const char* username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            memmove(&users[i], &users[i+1], sizeof(User) * (user_count - i - 1));
            user_count--;
            return;
        }
    }

    printf("User not found!\n");
}

void print_users() {
    printf("User list:\n");
    for (int i = 0; i < user_count; i++) {
        printf("Username: %s, Password: %s\n", users[i].username, users[i].password);
    }
}

int main() {
    char command[MAX_PASS];
    int arg_count;

    while (1) {
        printf("> ");
        scanf("%s", command);
        sscanf(command, "%s%n", command, &arg_count);

        if (arg_count == 3) {
            if (strcmp(command, "create") == 0) {
                char username[MAX_PASS], password[MAX_PASS];
                scanf("%s%s", username, password);
                create_user(username, password);
            } else if (strcmp(command, "delete") == 0) {
                char username[MAX_PASS];
                scanf("%s", username);
                delete_user(username);
            } else if (strcmp(command, "list") == 0) {
                print_users();
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}