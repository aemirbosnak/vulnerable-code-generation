//GPT-4o-mini DATASET v1.0 Category: Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_NAME_LEN 50
#define MAX_PASSWORD_LEN 20
#define MAX_TRIES 3

typedef struct User {
    char username[MAX_NAME_LEN];
    char password[MAX_PASSWORD_LEN];
} User;

User users[MAX_USERS];
int user_count = 0;

// Function prototypes
int register_user(const char* username, const char* password);
int authenticate_user(const char* username, const char* password);
void display_menu();
void clear_buffer();

int main() {
    int choice;
    char username[MAX_NAME_LEN];
    char password[MAX_PASSWORD_LEN];

    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            clear_buffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        clear_buffer();
        
        switch (choice) {
            case 1:
                printf("Register\n");
                printf("Username: ");
                fgets(username, MAX_NAME_LEN, stdin);
                username[strcspn(username, "\n")] = 0;  // Remove newline
                
                printf("Password: ");
                fgets(password, MAX_PASSWORD_LEN, stdin);
                password[strcspn(password, "\n")] = 0;  // Remove newline

                if (register_user(username, password)) {
                    printf("Registration successful!\n");
                } else {
                    printf("Registration failed: username already exists.\n");
                }
                break;

            case 2:
                printf("Login\n");
                printf("Username: ");
                fgets(username, MAX_NAME_LEN, stdin);
                username[strcspn(username, "\n")] = 0;  // Remove newline
                
                printf("Password: ");
                fgets(password, MAX_PASSWORD_LEN, stdin);
                password[strcspn(password, "\n")] = 0;  // Remove newline

                if (authenticate_user(username, password)) {
                    printf("Login successful! Welcome, %s.\n", username);
                } else {
                    printf("Login failed: Invalid username or password.\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
}

// Function to register a new user
int register_user(const char* username, const char* password) {
    if (user_count >= MAX_USERS) {
        return 0; // User limit reached
    }

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 0; // Username already exists
        }
    }

    // Register new user
    strncpy(users[user_count].username, username, MAX_NAME_LEN);
    strncpy(users[user_count].password, password, MAX_PASSWORD_LEN);
    user_count++;
    return 1; // Registration successful
}

// Function to authenticate a user
int authenticate_user(const char* username, const char* password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; // Authentication successful
        }
    }
    return 0; // Authentication failed
}

// Function to display the menu
void display_menu() {
    printf("\n=== User Management System ===\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Function to clear input buffer
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}