//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

// Function to add a new user
void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }
    User newUser;
    newUser.id = userCount + 1; // Incremental ID
    printf("Enter user name: ");
    fgets(newUser.name, MAX_NAME_LENGTH, stdin);
    newUser.name[strcspn(newUser.name, "\n")] = 0; // Remove newline
    printf("Enter user email: ");
    fgets(newUser.email, MAX_EMAIL_LENGTH, stdin);
    newUser.email[strcspn(newUser.email, "\n")] = 0; // Remove newline
    users[userCount++] = newUser; // Add user to array
    printf("User added successfully!\n");
}

// Function to display all users
void displayUsers() {
    if (userCount == 0) {
        printf("No users found.\n");
        return;
    }
    printf("\nList of Users:\n");
    printf("ID\tName\t\tEmail\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < userCount; ++i) {
        printf("%d\t%-15s\t%s\n", users[i].id, users[i].name, users[i].email);
    }
}

// Function to delete a user by ID
void deleteUser() {
    int idToDelete;
    printf("Enter the ID of the user to delete: ");
    scanf("%d", &idToDelete);
    getchar(); // Consume the newline character
    int found = 0;
    for (int i = 0; i < userCount; ++i) {
        if (users[i].id == idToDelete) {
            found = 1;
            // Shift other users up
            for (int j = i; j < userCount - 1; ++j) {
                users[j] = users[j + 1];
            }
            userCount--;
            printf("User with ID %d deleted successfully!\n", idToDelete);
            break;
        }
    }
    if (!found) {
        printf("User with ID %d not found.\n", idToDelete);
    }
}

// Function to search for a user by email
void searchUser() {
    char email[MAX_EMAIL_LENGTH];
    printf("Enter the email of the user to search: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = 0; // Remove newline
    int found = 0;
    for (int i = 0; i < userCount; ++i) {
        if (strcmp(users[i].email, email) == 0) {
            found = 1;
            printf("User found: ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
            break;
        }
    }
    if (!found) {
        printf("User with email '%s' not found.\n", email);
    }
}

// Main menu function
void menu() {
    int choice;
    do {
        printf("\nUser Management System\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Delete User\n");
        printf("4. Search User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character
        
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                displayUsers();
                break;
            case 3:
                deleteUser();
                break;
            case 4:
                searchUser();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}