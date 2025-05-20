//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a user in the database
typedef struct User {
    int id;
    char name[50];
    char email[50];
} User;

// Function prototypes
void addUser(User *users, int *count);
void displayUsers(User *users, int count);
void findUserById(User *users, int count, int id);
void deleteUser(User *users, int *count, int id);

int main() {
    User users[100]; // Array to hold users, with a maximum of 100 users
    int userCount = 0;
    int choice;

    // Display a welcome message
    printf("Welcome to the Grateful User Database!\n");
    printf("Here you can add, display, find, and delete users with ease.\n");

    // Main loop for the menu
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Find User by ID\n");
        printf("4. Delete User by ID\n");
        printf("5. Exit\n");
        printf("Please select an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser(users, &userCount);
                break;
            case 2:
                displayUsers(users, userCount);
                break;
            case 3:
                printf("Enter User ID to find: ");
                int id;
                scanf("%d", &id);
                findUserById(users, userCount, id);
                break;
            case 4:
                printf("Enter User ID to delete: ");
                scanf("%d", &id);
                deleteUser(users, &userCount, id);
                break;
            case 5:
                printf("Thank you for using the Grateful User Database. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option!\n");
        }
    }
    return 0;
}

void addUser(User *users, int *count) {
    if (*count >= 100) {
        printf("User limit reached, can't add more users!\n");
        return;
    }

    User newUser;
    newUser.id = *count + 1; // ID is set based on count
    printf("Enter name: ");
    scanf("%s", newUser.name);
    printf("Enter email: ");
    scanf("%s", newUser.email);
    
    // Add the new user to the database
    users[*count] = newUser;
    (*count)++;
    printf("User added successfully!\n");
}

void displayUsers(User *users, int count) {
    if (count == 0) {
        printf("No users to display.\n");
        return;
    }

    printf("\nList of Users:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
    }
}

void findUserById(User *users, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (users[i].id == id) {
            printf("User found: ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
            return;
        }
    }
    printf("User with ID %d not found.\n", id);
}

void deleteUser(User *users, int *count, int id) {
    for (int i = 0; i < *count; i++) {
        if (users[i].id == id) {
            // Shift users to delete the user at index i
            for (int j = i; j < *count - 1; j++) {
                users[j] = users[j + 1];
            }
            (*count)--;
            printf("User with ID %d deleted successfully!\n", id);
            return;
        }
    }
    printf("User with ID %d not found.\n", id);
}