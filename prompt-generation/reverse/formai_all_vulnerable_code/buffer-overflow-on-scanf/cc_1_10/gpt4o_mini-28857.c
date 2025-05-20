//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_USERS 10
#define MAX_LENGTH 100

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char hackerAlias[MAX_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void delay(unsigned int seconds) {
    sleep(seconds);
}

void welcomeMessage() {
    printf("=== Cyberpunk Data Vault ===\n");
    printf("Enter the neon-lit world of cybernetic lore and digital intrigue.\n");
    delay(1);
    printf("══════════════════════════════════════════════\n");
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Data vault is full! Cannot register new user.\n");
        return;
    }
    
    printf("Register a new user:\n");
    
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    
    printf("Enter password: ");
    scanf("%s", users[userCount].password);

    printf("Enter hacker alias: ");
    scanf("%s", users[userCount].hackerAlias);

    userCount++;
    printf("User registered successfully! Proceed with caution...\n");
}

int isValidUser(const char *username, const char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && 
            strcmp(users[i].password, password) == 0) {
            return i; // Return user index if valid
        }
    }
    return -1; // Invalid user
}

void loginUser() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);
    
    printf("Enter your password: ");
    scanf("%s", password);

    int userIndex = isValidUser(username, password);
    if (userIndex == -1) {
        printf("Access Denied! Invalid username or password.\n");
    } else {
        printf("Access Granted! Welcome back, %s.\n", users[userIndex].hackerAlias);
        delay(1);
        printf("Loading your digital profile...\n");
        delay(2);
        printf("Here's your last known activity:\n");
        printf(" - Accessed restricted data files.\n");
        printf(" - Engaged in a cyber battle with the Yakuza.\n");
        printf(" - Hacked into the corporate mainframe.\n");
    }
}

void listUsers() {
    printf("=== List of all registered hackers ===\n");
    for (int i = 0; i < userCount; i++) {
        printf("- %s (Hacker Alias: %s)\n", users[i].username, users[i].hackerAlias);
    }
}

void showMenu() {
    int choice;

    do {
        printf("\n=== Main Menu ===\n");
        printf("1. Register User\n");
        printf("2. Login User\n");
        printf("3. List Users\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                listUsers();
                break;
            case 0:
                printf("Shutting down the neon lights...\n");
                delay(2);
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while (choice != 0);
}

int main() {
    welcomeMessage();
    showMenu();
    return 0;
}