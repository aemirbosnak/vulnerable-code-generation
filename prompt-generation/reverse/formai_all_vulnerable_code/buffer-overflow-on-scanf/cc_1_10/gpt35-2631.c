//FormAI DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_MAX_LENGTH 20
#define MAX_USERS 50

typedef struct {
    char username[15];
    char password[PASSWORD_MAX_LENGTH + 1];
    int login_attempts;
} User;

User user_database[MAX_USERS];
int num_users = 0;

void sign_up();
void login();
void change_password();
void display_all_users();

int main() {
    int choice, i;
    do {
        printf("Welcome to Password Manager!\n");
        printf("1. Sign Up\n2. Login\n3. Change Password\n4. Display all users\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sign_up();
                break;
            case 2:
                login();
                break;
            case 3:
                change_password();
                break;
            case 4:
                display_all_users();
                break;
            case 5:
                printf("Thanks for using Password Manager.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void sign_up() {
    if (num_users == MAX_USERS) {
        printf("Sorry, the user database is full.\n");
        return;
    }

    char username[15], password[PASSWORD_MAX_LENGTH + 1];

    printf("Enter your desired username: ");
    scanf("%s", username);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(user_database[i].username, username) == 0) {
            printf("Sorry, that username is already taken.\n");
            return;
        }
    }

    printf("Enter your desired password (max %d characters): ", PASSWORD_MAX_LENGTH);
    scanf("%s", password);

    if (strlen(password) > PASSWORD_MAX_LENGTH) {
        printf("Sorry, your password is too long. Please choose a shorter password.\n");
        return;
    }

    User new_user;
    strcpy(new_user.username, username);
    strcpy(new_user.password, password);
    new_user.login_attempts = 0;

    user_database[num_users] = new_user;
    num_users++;

    printf("Congratulations, your account has been created successfully!\n");
}

void login() {
    char username[15], password[PASSWORD_MAX_LENGTH + 1];

    printf("Enter your username: ");
    scanf("%s", username);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(user_database[i].username, username) == 0) {
            printf("Enter your password: ");
            scanf("%s", password);

            if (strcmp(user_database[i].password, password) == 0) {
                printf("Welcome, %s!\n", user_database[i].username);
                user_database[i].login_attempts = 0;
                return;
            } else {
                user_database[i].login_attempts++;
                printf("Sorry, that password is incorrect. Please try again.\n");
                return;
            }
        }
    }

    printf("Sorry, that username is not found in our records.\n");
}

void change_password() {
    char username[15], old_password[PASSWORD_MAX_LENGTH + 1], new_password[PASSWORD_MAX_LENGTH + 1];

    printf("Enter your username: ");
    scanf("%s", username);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(user_database[i].username, username) == 0) {
            printf("Enter your old password: ");
            scanf("%s", old_password);

            if (strcmp(user_database[i].password, old_password) == 0) {
                printf("Enter your new password (max %d characters): ", PASSWORD_MAX_LENGTH);
                scanf("%s", new_password);

                if (strlen(new_password) > PASSWORD_MAX_LENGTH) {
                    printf("Sorry, your password is too long. Please choose a shorter password.\n");
                    return;
                }

                strcpy(user_database[i].password, new_password);
                printf("Your password has been changed successfully!\n");
                return;
            } else {
                printf("Sorry, that password is incorrect. Please try again.\n");
                return;
            }
        }
    }

    printf("Sorry, that username is not found in our records.\n");
}

void display_all_users() {
    printf("Username    Password    Failed Login Attempts\n");
    for (int i = 0; i < num_users; i++) {
        printf("%-11s %-11s %d\n", user_database[i].username, user_database[i].password, user_database[i].login_attempts);
    }
}