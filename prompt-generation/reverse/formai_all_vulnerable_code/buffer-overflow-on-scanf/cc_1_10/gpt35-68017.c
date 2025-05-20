//FormAI DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20
#define MAX_USERS 100

typedef struct User
{
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} User;

User userList[MAX_USERS];
int numUsers = 0;

void addNewUser(char *username, char *password);
bool authenticateUser(char *username, char *password);
void changePassword(char *username, char *oldPassword, char *newPassword);

int main()
{
    bool running = true;

    printf("Welcome to the Password Manager\n");

    while (running)
    {
        printf("\nMenu:\n");
        printf("1. Create new user\n");
        printf("2. Authenticate user\n");
        printf("3. Change password\n");
        printf("4. Exit\n");

        int option;
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
            {
                char username[MAX_USERNAME_LEN];
                char password[MAX_PASSWORD_LEN];

                printf("\nEnter username: ");
                scanf("%s", username);

                printf("Enter password: ");
                scanf("%s", password);

                addNewUser(username, password);

                printf("\nNew user created\n");
                break;
            }

            case 2:
            {
                char username[MAX_USERNAME_LEN];
                char password[MAX_PASSWORD_LEN];

                printf("\nEnter username: ");
                scanf("%s", username);

                printf("Enter password: ");
                scanf("%s", password);

                bool authenticated = authenticateUser(username, password);

                if (authenticated)
                {
                    printf("\nUser authenticated\n");
                }
                else
                {
                    printf("\nInvalid username or password\n");
                }

                break;
            }

            case 3:
            {
                char username[MAX_USERNAME_LEN];
                char oldPassword[MAX_PASSWORD_LEN];
                char newPassword[MAX_PASSWORD_LEN];

                printf("\nEnter username: ");
                scanf("%s", username);

                printf("Enter current password: ");
                scanf("%s", oldPassword);

                printf("Enter new password: ");
                scanf("%s", newPassword);

                changePassword(username, oldPassword, newPassword);

                printf("\nPassword changed\n");
                break;
            }

            case 4:
            {
                running = false;
                break;
            }

            default:
            {
                printf("\nInvalid option\n");
                break;
            }
        }
    }

    printf("\nExiting...\n");
    return 0;
}

void addNewUser(char *username, char *password)
{
    User newUser;

    strcpy(newUser.username, username);
    strcpy(newUser.password, password);

    userList[numUsers] = newUser;
    numUsers++;
}

bool authenticateUser(char *username, char *password)
{
    for (int i = 0; i < numUsers; i++)
    {
        User user = userList[i];

        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0)
        {
            return true;
        }
    }

    return false;
}

void changePassword(char *username, char *oldPassword, char *newPassword)
{
    for (int i = 0; i < numUsers; i++)
    {
        User *user = &userList[i];

        if (strcmp(user->username, username) == 0 && strcmp(user->password, oldPassword) == 0)
        {
            strcpy(user->password, newPassword);
            break;
        }
    }
}