//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 100
#define USERNAME_LENGTH 30
#define PASSWORD_LENGTH 30

typedef struct User {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int is_logged_in;
} User;

User users[MAX_USERS];
int user_count = 0;

void display_welcome_message() {
    printf("Welcome to the Capulet System Administration!\n");
    printf("Here, we guard the peace of Verona as fiercely as Romeo's love.\n");
}

void add_user() {
    if (user_count < MAX_USERS) {
        printf("Enter a username: ");
        scanf("%s", users[user_count].username);
        printf("Enter a password: ");
        scanf("%s", users[user_count].password);
        users[user_count].is_logged_in = 0;
        user_count++;
        printf("Alas! A new user hath entered our realm: %s\n", users[user_count - 1].username);
    } else {
        printf("The user horde is full, dear friend!\n");
    }
}

int login_user() {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            users[i].is_logged_in = 1;
            printf("O sweet entrance, %s! Thou art logged in.\n", username);
            return 1;
        }
    }
    printf("O woe! The username or password be false.\n");
    return 0;
}

void view_users() {
    printf("Revealing the loyal subjects of Verona:\n");
    for (int i = 0; i < user_count; i++) {
        printf("- %s %s\n", users[i].username, users[i].is_logged_in ? "(Logged In)" : "(Logged Out)");
    }
}

void logout_user() {
    char username[USERNAME_LENGTH];
    printf("Enter the username to log out: ");
    scanf("%s", username);
    
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && users[i].is_logged_in) {
            users[i].is_logged_in = 0;
            printf("%s hath departed. Farewell!\n", username);
            return;
        }
    }
    printf("O fickle fate! Either that name is wrong or they were not logged in.\n");
}

int main() {
    int choice;

    display_welcome_message();

    while (1) {
        printf("\nWhat would you like to do, noble friend?\n");
        printf("1. Add User\n");
        printf("2. Login\n");
        printf("3. View Users\n");
        printf("4. Logout User\n");
        printf("5. Exit the Realm\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                login_user();
                break;
            case 3:
                view_users();
                break;
            case 4:
                logout_user();
                break;
            case 5:
                printf("Parting is such sweet sorrow. Until we meet again!\n");
                exit(0);
            default:
                printf("I know not what thou mean'st, try again!\n");
                break;
        }
    }
    
    return 0;
}