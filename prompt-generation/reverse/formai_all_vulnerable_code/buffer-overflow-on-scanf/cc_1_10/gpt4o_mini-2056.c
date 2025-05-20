//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 10
#define USERNAME_LENGTH 30
#define PASSWORD_LENGTH 32

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int loggedIn;
} User;

User users[MAX_USERS];
int userCount = 0;

void displayWelcomeMessage() {
    printf("🎉 Welcome to the Cheerful User Management System! 🎉\n");
    printf("Here you can register, log in, and manage users with a smile!\n");
    printf("----------------------------------------------------------\n");
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("☹️ Oops! The user list is full. Can't register more users.\n");
        return;
    }
    
    User newUser;
    
    printf("Enter a username: ");
    scanf("%s", newUser.username);
    printf("Enter a password: ");
    scanf("%s", newUser.password);
    
    newUser.loggedIn = 0;
    users[userCount] = newUser;
    userCount++;
    
    printf("🎊 User %s registered successfully! 🎊\n", newUser.username);
}

void loginUser() {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            users[i].loggedIn = 1;
            printf("🌟 Welcome back, %s! You are now logged in! 🌟\n", username);
            return;
        }
    }
    printf("😢 Login failed! Incorrect username or password. Try again!\n");
}

void logoutUser() {
    char username[USERNAME_LENGTH];
    
    printf("Enter your username to log out: ");
    scanf("%s", username);
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && users[i].loggedIn) {
            users[i].loggedIn = 0;
            printf("👋 Goodbye, %s! You have logged out successfully! 👋\n", username);
            return;
        }
    }
    printf("😔 You are not logged in or don't exist! Try again!\n");
}

void showActiveUsers() {
    printf("🎈 Currently logged in users 🎈\n");
    int found = 0;
    for (int i = 0; i < userCount; i++) {
        if (users[i].loggedIn) {
            printf("- %s\n", users[i].username);
            found = 1;
        }
    }
    if (!found) {
        printf("🔕 There are no active users at the moment!\n");
    }
}

void printMenu() {
    printf("\nOptions:\n");
    printf("1. Register User\n");
    printf("2. Login User\n");
    printf("3. Logout User\n");
    printf("4. Show Active Users\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

int main() {
    int choice;
    displayWelcomeMessage();
    
    do {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                logoutUser();
                break;
            case 4:
                showActiveUsers();
                break;
            case 5:
                printf("🎉 Thank you for using the Cheerful User Management System! Goodbye! 🎉\n");
                break;
            default:
                printf("❌ Invalid choice! Please choose a valid option (1-5).\n");
        }
    } while (choice != 5);

    return 0;
}