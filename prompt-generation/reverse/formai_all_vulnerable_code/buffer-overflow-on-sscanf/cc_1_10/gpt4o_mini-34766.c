//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 50
#define USERNAME_LENGTH 32

typedef struct {
    char username[USERNAME_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

void add_user(const char* username) {
    if (user_count >= MAX_USERS) {
        printf("User limit reached. Cannot add more users!\n");
        return;
    }
    
    // Check if user already exists
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("User '%s' already exists.\n", username);
            return;
        }
    }

    // Add new user
    strcpy(users[user_count].username, username);
    user_count++;
    printf("User '%s' added successfully!\n", username);
}

void delete_user(const char* username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            // Shift remaining users
            for (int j = i; j < user_count - 1; j++) {
                users[j] = users[j + 1];
            }
            user_count--;
            printf("User '%s' deleted successfully!\n", username);
            return;
        }
    }
    printf("User '%s' not found.\n", username);
}

void list_users() {
    if (user_count == 0) {
        printf("No users found.\n");
        return;
    }
    
    printf("Current users:\n");
    for (int i = 0; i < user_count; i++) {
        printf(" - %s\n", users[i].username);
    }
}

int main() {
    char command[256];
    char username[USERNAME_LENGTH];

    printf("Welcome to the Simple User Management System!\n");
    printf("Commands:\n");
    printf("1. add <username>\n");
    printf("2. delete <username>\n");
    printf("3. list\n");
    printf("4. exit\n");
    
    while (1) {
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);
        
        // Removing new line character from the command
        command[strcspn(command, "\n")] = 0;
        
        // Parsing command
        if (strncmp(command, "add ", 4) == 0) {
            sscanf(command + 4, "%s", username);
            add_user(username);
        } else if (strncmp(command, "delete ", 7) == 0) {
            sscanf(command + 7, "%s", username);
            delete_user(username);
        } else if (strcmp(command, "list") == 0) {
            list_users();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the user management system. Goodbye!\n");
            break;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }
    
    return 0;
}