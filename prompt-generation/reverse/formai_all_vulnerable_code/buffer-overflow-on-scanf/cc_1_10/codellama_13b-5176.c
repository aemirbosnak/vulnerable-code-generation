//Code Llama-13B DATASET v1.0 Category: Password management ; Style: enthusiastic
// Password management program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to store password information
typedef struct {
    char* username;
    char* password;
    bool is_active;
} Password;

// Function to create a new password
void create_password(Password* pwd) {
    // Prompt user for username and password
    printf("Enter username: ");
    scanf("%s", pwd->username);
    printf("Enter password: ");
    scanf("%s", pwd->password);
    pwd->is_active = true;
}

// Function to display a password
void display_password(Password* pwd) {
    printf("Username: %s\n", pwd->username);
    printf("Password: %s\n", pwd->password);
    printf("Is active: %d\n", pwd->is_active);
}

// Function to change a password
void change_password(Password* pwd) {
    // Prompt user for new password
    printf("Enter new password: ");
    scanf("%s", pwd->password);
    pwd->is_active = true;
}

// Function to delete a password
void delete_password(Password* pwd) {
    // Prompt user for confirmation
    printf("Are you sure you want to delete this password? (y/n): ");
    char confirm;
    scanf("%c", &confirm);
    if (confirm == 'y') {
        pwd->is_active = false;
        printf("Password deleted\n");
    } else {
        printf("Password not deleted\n");
    }
}

// Function to search for a password
void search_password(Password* pwd) {
    // Prompt user for username
    printf("Enter username: ");
    char* username;
    scanf("%s", username);
    // Search for password
    for (int i = 0; i < 10; i++) {
        if (strcmp(pwd[i].username, username) == 0) {
            display_password(&pwd[i]);
            return;
        }
    }
    // If password not found
    printf("Password not found\n");
}

int main() {
    // Create 10 password objects
    Password pwd[10];
    // Initialize each password
    for (int i = 0; i < 10; i++) {
        create_password(&pwd[i]);
    }
    // Prompt user for action
    char action;
    printf("Enter action (c, d, s): ");
    scanf("%c", &action);
    switch (action) {
        case 'c':
            // Create a new password
            create_password(&pwd[0]);
            break;
        case 'd':
            // Delete a password
            delete_password(&pwd[0]);
            break;
        case 's':
            // Search for a password
            search_password(pwd);
            break;
        default:
            // Invalid action
            printf("Invalid action\n");
            break;
    }
    return 0;
}