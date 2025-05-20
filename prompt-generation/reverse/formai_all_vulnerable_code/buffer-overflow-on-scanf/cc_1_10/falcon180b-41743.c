//Falcon-180B DATASET v1.0 Category: Password management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_USERS 5
#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

struct user {
    char name[20];
    char password[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int num_passwords;
};

void create_user(struct user *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    user->num_passwords = 0;
}

void add_password(struct user *user, char *password) {
    if (user->num_passwords >= MAX_PASSWORDS) {
        printf("You have reached the maximum number of passwords.\n");
        return;
    }
    strcpy(user->password[user->num_passwords], password);
    user->num_passwords++;
}

int login(struct user users[MAX_USERS], int num_users, char *name, char *password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0 && strcmp(users[i].password[0], password) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    srand(time(NULL));
    int num_users = rand() % MAX_USERS + 1;
    struct user users[MAX_USERS];
    for (int i = 0; i < num_users; i++) {
        create_user(&users[i]);
    }
    char *passwords[MAX_PASSWORDS] = {"password1", "password2", "password3", "password4", "password5", "password6", "password7", "password8", "password9", "password10"};
    int num_passwords = rand() % MAX_PASSWORDS + 1;
    for (int i = 0; i < num_passwords; i++) {
        add_password(&users[i], passwords[i]);
    }
    int num_correct_logins = 0;
    while (1) {
        printf("Enter your name: ");
        char name[20];
        scanf("%s", name);
        int user_index = login(users, num_users, name, "password1");
        if (user_index!= -1) {
            printf("Welcome, %s!\n", users[user_index].name);
            num_correct_logins++;
        } else {
            printf("Incorrect name or password.\n");
        }
    }
    return 0;
}