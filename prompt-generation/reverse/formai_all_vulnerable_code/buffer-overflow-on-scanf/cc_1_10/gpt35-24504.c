//FormAI DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct for a single user
typedef struct {
    int id;
    char name[20];
    char email[50];
} User;

// Function to add a new user to the database
void add_user(User *users, int *count) {
    // Prompt for user details
    printf("Enter user name: ");
    scanf("%s", users[*count].name);
    printf("Enter user email: ");
    scanf("%s", users[*count].email);
    // Generate user ID
    users[*count].id = *count + 1;
    // Increment user count
    (*count)++;
    // Confirmation message
    printf("User added successfully!\n");
}

// Function to display all users in the database
void display_users(User *users, int count) {
    // Check if there are any users
    if (count == 0) {
        printf("No users found.\n");
        return;
    }
    // Print table header
    printf("| %-3s | %-20s | %-50s |\n", "ID", "Name", "Email");
    // Print table separator
    printf("+-----+----------------------+----------------------------------------------------+\n");
    // Print users
    for (int i = 0; i < count; i++) {
        printf("| %-3d | %-20s | %-50s |\n", users[i].id, users[i].name, users[i].email);
    }
}

// Function to find a user by email address
int find_user(User *users, int count, char *email) {
    // Loop through users to find matching email
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].email, email) == 0) {
            // Match found, return user ID
            return i;
        }
    }
    // No match found
    return -1;
}

// Function to update an existing user's details
void update_user(User *users, int count) {
    // Prompt for user email
    char email[50];
    printf("Enter user email: ");
    scanf("%s", email);
    // Find user by email
    int user_index = find_user(users, count, email);
    if (user_index == -1) {
        // User not found
        printf("User not found.\n");
        return;
    }
    // Prompt for updated details
    printf("Enter updated name: ");
    scanf("%s", users[user_index].name);
    // Confirmation message
    printf("User updated successfully!\n");
}

// Function to delete an existing user
void delete_user(User *users, int *count) {
    // Prompt for user email
    char email[50];
    printf("Enter user email: ");
    scanf("%s", email);
    // Find user by email
    int user_index = find_user(users, *count, email);
    if (user_index == -1) {
        // User not found
        printf("User not found.\n");
        return;
    }
    // Shift remaining users left to fill space
    for (int i = user_index; i < *count - 1; i++) {
        users[i] = users[i + 1];
    }
    // Decrement user count
    (*count)--;
    // Confirmation message
    printf("User deleted successfully!\n");
}

int main() {
    // Initialize user count to 0
    int user_count = 0;
    // Allocate memory for array of users
    User *users = (User*) malloc(sizeof(User) * 100);
    // Loop until user chooses to exit
    while (true) {
        // Display menu options
        printf("Choose an option:\n");
        printf("1. Add user\n");
        printf("2. Display all users\n");
        printf("3. Update user details\n");
        printf("4. Delete user\n");
        printf("5. Exit system\n");
        // Prompt for user input
        int option;
        printf("Option: ");
        scanf("%d", &option);
        // Execute selected option
        switch (option) {
            case 1:
                add_user(users, &user_count);
                break;
            case 2:
                display_users(users, user_count);
                break;
            case 3:
                update_user(users, user_count);
                break;
            case 4:
                delete_user(users, &user_count);
                break;
            case 5:
                free(users);
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}