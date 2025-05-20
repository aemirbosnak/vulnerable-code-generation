//FormAI DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20

struct User {
    char username[MAX_USERNAME_LEN + 1];
    char password[MAX_PASSWORD_LEN + 1];
};

bool validate_username(char *username) {
    size_t len = strlen(username);
    if (len < 6 || len > MAX_USERNAME_LEN) {
        printf("Username should be between 6 and %d characters long.\n", MAX_USERNAME_LEN);
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (!isalnum(username[i])) {
            printf("Username should contain only alphanumeric characters.\n");
            return false;
        }
    }
    return true;
}

bool validate_password(char *password) {
    size_t len = strlen(password);
    if (len < 6 || len > MAX_PASSWORD_LEN) {
        printf("Password should be between 6 and %d characters long.\n", MAX_PASSWORD_LEN);
        return false;
    }
    bool has_upper = false, has_lower = false, has_digit = false;
    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) {
            has_upper = true;
        }
        if (islower(password[i])) {
            has_lower = true;
        }
        if (isdigit(password[i])) {
            has_digit = true;
        }
    }
    if (!has_upper || !has_lower || !has_digit) {
        printf("Password should contain both uppercase and lowercase letters and at least one digit.\n");
        return false;
    }
    return true;
}

void create_user(struct User *user) {
    char username[MAX_USERNAME_LEN + 1], password[MAX_PASSWORD_LEN + 1];
    printf("Enter username: ");
    scanf("%s", username);
    if (!validate_username(username)) {
        return create_user(user);
    }
    printf("Enter password: ");
    scanf("%s", password);
    if (!validate_password(password)) {
        return create_user(user);
    }
    strcpy(user->username, username);
    strcpy(user->password, password);
}

void print_user(struct User user) {
    printf("Username: %s\n", user.username);
    printf("Password: %s\n", user.password);
}

int main() {
    printf("Welcome to the User Creation Management System!\n");
    int choice;
    struct User user;
    do {
        printf("Please choose an option:\n");
        printf("1. Create a new user\n");
        printf("2. Print user details\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("********** Creating a new user **********\n");
                create_user(&user);
                break;
            case 2:
                printf("********** User details **********\n");
                print_user(user);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 3);
    return 0;
}