//FormAI DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USER 100
#define MAX_PASSWORD 50

struct User {
    char username[MAX_USER];
    char password[MAX_PASSWORD];
    int is_active;
};

int count_user = 0;
struct User users[MAX_USER];

void print_header(char *title) {
    printf("\n------------------------------\n");
    printf("      %s\n", title);
    printf("------------------------------\n");
}

void print_menu() {
    print_header("PASSWORD MANAGEMENT");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Change Password\n");
    printf("4. Logout\n");
    printf("5. Exit\n");
    printf("------------------------------\n");
}

int is_username_exist(char *username) {
    for (int i = 0; i < count_user; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

int is_valid_password(char *password) {
    int length = strlen(password);
    if (length < 6 || length > 20) {
        return 0;
    }
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
        } else if (isupper(password[i])) {
            has_upper = 1;
        } else if (islower(password[i])) {
            has_lower = 1;
        } else if (ispunct(password[i])) {
            has_special = 1;
        }
    }
    return has_upper && has_lower && has_digit && has_special;
}

void register_user() {
    print_header("REGISTER");
    struct User user;
    printf("Enter username (max %d characters): ", MAX_USER - 1);
    scanf("%s", user.username);
    int index = is_username_exist(user.username);
    if (index != -1) {
        printf("Username is already taken!\n");
        return;
    }
    printf("Enter password (6-20 characters, at least one uppercase, one lowercase, one digit, and one special character): ");
    scanf("%s", user.password);
    if (!is_valid_password(user.password)) {
        printf("Invalid password format!\n");
        return;
    }
    user.is_active = 1;
    users[count_user++] = user;
    printf("Registration successful!\n");
}

int login() {
    print_header("LOGIN");
    char username[MAX_USER], password[MAX_PASSWORD];
    printf("Enter username: ");
    scanf("%s", username);
    int index = is_username_exist(username);
    if (index == -1) {
        printf("Username not found!\n");
        return -1;
    }
    printf("Enter password: ");
    scanf("%s", password);
    if (strcmp(users[index].password, password) != 0) {
        printf("Wrong password!\n");
        return -1;
    }
    users[index].is_active = 1;
    printf("Login successful!\n");
    return index;
}

void change_password(int index) {
    print_header("CHANGE PASSWORD");
    char password[MAX_PASSWORD], new_password[MAX_PASSWORD];
    printf("Enter current password: ");
    scanf("%s", password);
    if (strcmp(users[index].password, password) != 0) {
        printf("Wrong password!\n");
        return;
    }
    printf("Enter new password (6-20 characters, at least one uppercase, one lowercase, one digit, and one special character): ");
    scanf("%s", new_password);
    if (!is_valid_password(new_password)) {
        printf("Invalid password format!\n");
        return;
    }
    strcpy(users[index].password, new_password);
    printf("Password changed successfully!\n");
}

void logout(int index) {
    print_header("LOGOUT");
    users[index].is_active = 0;
    printf("Logout successful!\n");
}

int main() {
    int choice, index = -1;
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                if (index != -1) {
                    printf("You are already logged in!\n");
                } else {
                    index = login();
                }
                break;
            case 3:
                if (index == -1) {
                    printf("You are not logged in!\n");
                } else {
                    change_password(index);
                }
                break;
            case 4:
                if (index == -1) {
                    printf("You are not logged in!\n");
                } else {
                    logout(index);
                    index = -1;
                }
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}