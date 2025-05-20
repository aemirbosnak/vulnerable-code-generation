//Falcon2-11B DATASET v1.0 Category: Password management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERS 100

typedef struct user_data {
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
    int last_login_time;
    int num_login_attempts;
} user_data_t;

user_data_t users[MAX_USERS];
int num_users = 0;

void add_user(char username[], char password[], int last_login_time) {
    user_data_t new_user;
    strcpy(new_user.username, username);
    strcpy(new_user.password, password);
    new_user.last_login_time = last_login_time;
    new_user.num_login_attempts = 0;
    users[num_users++] = new_user;
}

void print_user_info(int user_index) {
    printf("Username: %s\n", users[user_index].username);
    printf("Password: *\n");
    printf("Last login time: %d\n", users[user_index].last_login_time);
    printf("Num login attempts: %d\n", users[user_index].num_login_attempts);
}

int main() {
    srand(time(NULL));

    char username[20];
    char password[MAX_PASSWORD_LENGTH];
    int last_login_time;

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    printf("Enter last login time: ");
    scanf("%d", &last_login_time);

    add_user(username, password, last_login_time);

    int user_index;
    for (user_index = 0; user_index < num_users; user_index++) {
        print_user_info(user_index);
    }

    return 0;
}