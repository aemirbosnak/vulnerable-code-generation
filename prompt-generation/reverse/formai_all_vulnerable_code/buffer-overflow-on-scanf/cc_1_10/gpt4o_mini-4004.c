//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_USERS 100
#define MAX_LENGTH 100
#define HASH_SIZE 256

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

// Simple hash function for demonstration
unsigned int hash(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % HASH_SIZE;
}

// Registers a user
bool register_user(const char *username, const char *password) {
    if (user_count >= MAX_USERS) {
        printf("User limit reached\n");
        return false;
    }

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists\n");
            return false;
        }
    }

    strncpy(users[user_count].username, username, MAX_LENGTH - 1);
    strncpy(users[user_count].password, password, MAX_LENGTH - 1);
    user_count++;
    printf("User registered successfully\n");
    return true;
}

// Validates a user's credentials
bool validate_user(const char *username, const char *password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return true;
        }
    }
    return false;
}

// Displays all registered users (for demo purposes)
void display_users() {
    printf("Registered Users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("%s\n", users[i].username);
    }
}

// Function to retrieve a password (simulating secure retrieval)
void retrieve_password(const char *username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Password for %s: %s\n", username, users[i].password);
            return;
        }
    }
    printf("User not found\n");
}

// Hashing passwords for storage (basic demo of transformation)
void hash_password(char *password) {
    for (int i = 0; password[i]; i++) {
        password[i] = password[i] + 3; // Simple Caesar cipher for demonstration
    }
}

// Main menu function
void menu() {
    while (1) {
        int choice;
        printf("\nPassword Management System\n");
        printf("1. Register User\n");
        printf("2. Login User\n");
        printf("3. Display Users\n");
        printf("4. Retrieve Password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1: {
                char username[MAX_LENGTH], password[MAX_LENGTH];
                printf("Enter username: ");
                fgets(username, MAX_LENGTH, stdin);
                username[strcspn(username, "\n")] = 0; // remove newline
                printf("Enter password: ");
                fgets(password, MAX_LENGTH, stdin);
                password[strcspn(password, "\n")] = 0; // remove newline
                hash_password(password);
                register_user(username, password);
                break;
            }
            case 2: {
                char username[MAX_LENGTH], password[MAX_LENGTH];
                printf("Enter username: ");
                fgets(username, MAX_LENGTH, stdin);
                username[strcspn(username, "\n")] = 0;
                printf("Enter password: ");
                fgets(password, MAX_LENGTH, stdin);
                password[strcspn(password, "\n")] = 0;
                if (validate_user(username, password))
                    printf("Login successful\n");
                else
                    printf("Login failed\n");
                break;
            }
            case 3:
                display_users();
                break;
            case 4: {
                char username[MAX_LENGTH];
                printf("Enter username to retrieve password: ");
                fgets(username, MAX_LENGTH, stdin);
                username[strcspn(username, "\n")] = 0;
                retrieve_password(username);
                break;
            }
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}