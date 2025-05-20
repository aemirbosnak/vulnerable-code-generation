//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_PASS_LEN 20
#define MAX_USERS 100
#define MAX_LOGINS 10

typedef struct user_info {
    char name[MAX_NAME_LEN];
    char password[MAX_PASS_LEN];
    int login_count;
} UserInfo;

typedef struct login_info {
    UserInfo user;
    char login_time[50];
    char logout_time[50];
} LoginInfo;

int main() {
    // Define arrays to store user and login info
    UserInfo users[MAX_USERS];
    LoginInfo logins[MAX_LOGINS];

    // Prompt user to enter number of users and initialize user array
    int num_users;
    printf("Enter the number of users: ");
    scanf("%d", &num_users);

    for (int i = 0; i < num_users; i++) {
        printf("Enter name of user %d: ", i + 1);
        scanf("%s", users[i].name);
        printf("Enter password for user %d: ", i + 1);
        scanf("%s", users[i].password);
        users[i].login_count = 0;
    }

    // Prompt user to enter number of logins and initialize login array
    int num_logins;
    printf("Enter the number of logins: ");
    scanf("%d", &num_logins);

    for (int i = 0; i < num_logins; i++) {
        printf("Enter login time for login %d: ", i + 1);
        scanf("%s", logins[i].login_time);
        printf("Enter logout time for login %d: ", i + 1);
        scanf("%s", logins[i].logout_time);
    }

    // Print user and login info
    printf("User Information:\n");
    for (int i = 0; i < num_users; i++) {
        printf("Name: %s\n", users[i].name);
        printf("Password: %s\n", users[i].password);
        printf("Login count: %d\n", users[i].login_count);
    }

    printf("\nLogin Information:\n");
    for (int i = 0; i < num_logins; i++) {
        printf("Login time: %s\n", logins[i].login_time);
        printf("Logout time: %s\n", logins[i].logout_time);
    }

    return 0;
}