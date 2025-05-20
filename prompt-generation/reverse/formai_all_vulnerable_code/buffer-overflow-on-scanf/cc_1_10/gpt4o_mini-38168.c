//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct User {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached! Cannot add more users.\n");
        return;
    }
    
    User newUser;
    newUser.id = userCount + 1;

    printf("Enter user's name: ");
    scanf(" %[^\n]", newUser.name);
    
    printf("Enter user's email: ");
    scanf(" %[^\n]", newUser.email);

    users[userCount] = newUser;
    userCount++;

    printf("User added successfully! ID: %d\n", newUser.id);
}

void displayUsers() {
    if (userCount == 0) {
        printf("No users to display.\n");
        return;
    }

    printf("\nList of Users:\n");
    for (int i = 0; i < userCount; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
    }
}

void searchUser() {
    int id;
    printf("Enter user ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            printf("User found! ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
            return;
        }
    }
    printf("User with ID %d not found!\n", id);
}

void deleteUser() {
    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            // Shift users to fill the gap
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            printf("User with ID %d deleted successfully!\n", id);
            return;
        }
    }
    printf("User with ID %d not found!\n", id);
}

void displayMenu() {
    printf("\n=== User Management System ===\n");
    printf("1. Add User\n");
    printf("2. Display Users\n");
    printf("3. Search User\n");
    printf("4. Delete User\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                displayUsers();
                break;
            case 3:
                searchUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}