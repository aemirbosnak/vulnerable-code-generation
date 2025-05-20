//FormAI DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PW_LENGTH 20

struct user {
    char name[MAX_PW_LENGTH];
    char password[MAX_PW_LENGTH];
};

void setPassword(char *password) {
    printf("Enter a new password: ");
    scanf("%s", password);
}

void loginUser(struct user *users, int *num_users) {
    char name[MAX_PW_LENGTH];
    char password[MAX_PW_LENGTH];
    int i;

    printf("Enter your username: ");
    scanf("%s", name);
    printf("Enter your password: ");
    scanf("%s", password);

    for (i = 0; i < *num_users; i++) {
        if (!strcmp(users[i].name, name) && !strcmp(users[i].password, password)) {
            printf("Welcome, %s!\n", name);
            return;
        }
    }

    printf("Incorrect username/password combination.\n");
}

void newUser(struct user *users, int *num_users) {
    if (*num_users >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    printf("Enter a username: ");
    scanf("%s", users[*num_users].name);
    setPassword(users[*num_users].password);

    *num_users += 1;

    printf("Account created successfully.\n");
}

void changePassword(struct user *users, int *num_users) {
    char name[MAX_PW_LENGTH];
    char old_password[MAX_PW_LENGTH];
    char new_password[MAX_PW_LENGTH];
    int i;

    printf("Enter your username: ");
    scanf("%s", name);
    printf("Enter your current password: ");
    scanf("%s", old_password);

    for (i = 0; i < *num_users; i++) {
        if (!strcmp(users[i].name, name) && !strcmp(users[i].password, old_password)) {
            setPassword(new_password);
            strcpy(users[i].password, new_password);
            printf("Password changed successfully.\n");
            return;
        }
    }

    printf("Incorrect username/password combination.\n");
}

int main() {
    struct user users[MAX_USERS];
    int num_users = 0;
    char choice;

    while (1) {
        printf("\n");
        printf("1. Login\n");
        printf("2. New User\n");
        printf("3. Change Password\n");
        printf("4. Exit\n");
        printf("Enter a choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                loginUser(users, &num_users);
                break;
            case '2':
                newUser(users, &num_users);
                break;
            case '3':
                changePassword(users, &num_users);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}