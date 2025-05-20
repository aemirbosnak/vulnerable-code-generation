//FormAI DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERS 5

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int is_valid_password(char *password);
int is_valid_username(char *username);
void add_user(struct User *users, int *num_users);
void display_users(struct User *users, int num_users);
void change_password(struct User *users, int num_users, char *username);

int main() {
    struct User users[MAX_USERS];
    int num_users = 0;
    int choice;

    printf("Welcome to Password Management.\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add user\n");
        printf("2. Display users\n");
        printf("3. Change password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user(users, &num_users);
                break;
            case 2:
                display_users(users, num_users);
                break;
            case 3:
                printf("Enter the username to change password: ");
                char username[MAX_USERNAME_LENGTH];
                scanf("%s", username);
                change_password(users, num_users, username);
                break;
            case 4:
                printf("Exiting program.");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int is_valid_password(char *password) {
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;

    if (strlen(password) < 6 || strlen(password) > 12) {
        printf("Password length should be between 6 and 12 characters.\n");
        return 0;
    }

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        } else {
            printf("Password should only contain letters and digits.\n");
            return 0;
        }
    }

    if (!has_uppercase) {
        printf("Password should contain at least one uppercase letter.\n");
        return 0;
    }

    if (!has_lowercase) {
        printf("Password should contain at least one lowercase letter.\n");
        return 0;
    }

    if (!has_digit) {
        printf("Password should contain at least one digit.\n");
        return 0;
    }

    return 1;
}

int is_valid_username(char *username) {
    if (strlen(username) > 20) {
        printf("Username length should be less than or equal to 20 characters.\n");
        return 0;
    }

    return 1;
}

void add_user(struct User *users, int *num_users) {
    if (*num_users == MAX_USERS) {
        printf("Maximum number of users reached. Cannot add more users.\n");
        return;
    }

    struct User new_user;

    while (1) {
        printf("Enter username: ");
        scanf("%s", new_user.username);

        if (!is_valid_username(new_user.username)) {
            continue;
        }

        int exists = 0;
        for (int i = 0; i < *num_users; i++) {
            if (strcmp(users[i].username, new_user.username) == 0) {
                exists = 1;
                printf("Username already exists. Please try a different username.\n");
                break;
            }
        }

        if (!exists) {
            break;
        }
    }

    while (1) {
        printf("Enter password: ");
        scanf("%s", new_user.password);

        if (is_valid_password(new_user.password)) {
            break;
        }
    }

    users[*num_users] = new_user;
    (*num_users)++;
    printf("User added successfully!\n");
}

void display_users(struct User *users, int num_users) {
    printf("\nUsers:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%d. %s\n", i+1, users[i].username);
    }
}

void change_password(struct User *users, int num_users, char *username) {
    int found = 0;
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            found = 1;

            while (1) {
                printf("Enter new password: ");
                scanf("%s", users[i].password);

                if (is_valid_password(users[i].password)) {
                    break;
                }
            }

            printf("Password changed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("User with username %s not found.\n", username);
    }
}