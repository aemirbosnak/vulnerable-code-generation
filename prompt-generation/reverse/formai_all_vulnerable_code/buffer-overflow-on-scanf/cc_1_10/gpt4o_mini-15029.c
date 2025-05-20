//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 100
#define PASSWORD_LENGTH 256
#define USERNAME_LENGTH 64

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

void clear_input_buffer() {
    while (getchar() != '\n');
}

int find_user(const char *username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached! Cannot register more users.\n");
        return;
    }

    User new_user;
    printf("Enter username (max %d characters): ", USERNAME_LENGTH - 1);
    scanf("%s", new_user.username);
    clear_input_buffer();

    if (find_user(new_user.username) != -1) {
        printf("Username already exists! Try another.\n");
        return;
    }

    printf("Enter password (max %d characters): ", PASSWORD_LENGTH - 1);
    scanf("%s", new_user.password);
    clear_input_buffer();

    users[user_count++] = new_user;
    printf("User registered successfully!\n");
}

void login_user() {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    clear_input_buffer();

    int index = find_user(username);
    if (index == -1) {
        printf("User not found! Please register or check your username.\n");
        return;
    }

    printf("Enter password: ");
    scanf("%s", password);
    clear_input_buffer();

    if (strcmp(users[index].password, password) == 0) {
        printf("Login successful! Welcome, %s!\n", username);
    } else {
        printf("Incorrect password! Try again.\n");
    }
}

void change_password() {
    char username[USERNAME_LENGTH];
    char old_password[PASSWORD_LENGTH];
    char new_password[PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);
    clear_input_buffer();

    int index = find_user(username);
    if (index == -1) {
        printf("User not found!\n");
        return;
    }

    printf("Enter your current password: ");
    scanf("%s", old_password);
    clear_input_buffer();

    if (strcmp(users[index].password, old_password) != 0) {
        printf("Current password is incorrect! Aborting password change.\n");
        return;
    }

    printf("Enter new password: ");
    scanf("%s", new_password);
    clear_input_buffer();

    strcpy(users[index].password, new_password);
    printf("Password changed successfully!\n");
}

void list_users() {
    if (user_count == 0) {
        printf("No registered users found.\n");
        return;
    }
    
    printf("Registered users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("%s\n", users[i].username);
    }
}

void menu() {
    int choice;

    do {
        printf("\nPassword Management System:\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Change Password\n");
        printf("4. List Users\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                login_user();
                break;
            case 3:
                change_password();
                break;
            case 4:
                list_users();
                break;
            case 5:
                printf("Exiting the Password Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}