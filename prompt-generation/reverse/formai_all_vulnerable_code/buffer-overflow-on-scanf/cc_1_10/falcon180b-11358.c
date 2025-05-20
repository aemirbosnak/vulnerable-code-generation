//Falcon-180B DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_USER_NAME_LENGTH 50

typedef struct {
    char user_name[MAX_USER_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} user_data_t;

void add_user(user_data_t *user_data, int num_users) {
    printf("Enter user name: ");
    scanf("%s", user_data[num_users].user_name);

    printf("Enter password: ");
    scanf("%s", user_data[num_users].password);
}

int login(user_data_t *user_data, int num_users) {
    printf("Enter user name: ");
    char input_name[MAX_USER_NAME_LENGTH];
    scanf("%s", input_name);

    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(user_data[i].user_name, input_name) == 0) {
            printf("Enter password: ");
            char input_password[MAX_PASSWORD_LENGTH];
            scanf("%s", input_password);

            if (strcmp(user_data[i].password, input_password) == 0) {
                return i;
            }
        }
    }

    return -1;
}

int main() {
    int num_users;
    printf("Enter number of users: ");
    scanf("%d", &num_users);

    user_data_t *user_data = (user_data_t *) malloc(sizeof(user_data_t) * num_users);

    int i;
    for (i = 0; i < num_users; i++) {
        add_user(user_data, num_users);
    }

    int user_index = login(user_data, num_users);
    if (user_index!= -1) {
        printf("User %s logged in successfully!\n", user_data[user_index].user_name);
    } else {
        printf("Invalid user name or password.\n");
    }

    free(user_data);
    return 0;
}