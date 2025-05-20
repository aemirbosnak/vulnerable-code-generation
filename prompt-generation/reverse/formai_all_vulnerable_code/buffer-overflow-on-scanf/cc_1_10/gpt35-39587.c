//FormAI DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing user information
typedef struct {
    char username[20];
    char password[20];
    int uid;
} User;

// Function for adding new user accounts
void add_user(User* users, int* count) {
    printf("Enter username: ");
    scanf("%s", users[*count].username);
    printf("Enter password: ");
    scanf("%s", users[*count].password);
    users[*count].uid = *count + 1000;
    *count += 1;
    printf("User account created successfully!\n");
}

// Function for deleting user accounts
void delete_user(User* users, int* count) {
    int uid;
    printf("Enter user ID to delete: ");
    scanf("%d", &uid);
    for (int i = 0; i < *count; i++) {
        if (users[i].uid == uid) {
            for (int j = i; j < *count - 1; j++) {
                users[j] = users[j+1];
            }
            *count -= 1;
            printf("User account deleted successfully!\n");
            return;
        }
    }
    printf("User ID not found.\n");
}

// Main function
int main() {
    User users[10];
    int count = 0;
    int choice;

    printf("Welcome to the user account management system.\n");

    while (1) {
        printf("\n1. Add user\n");
        printf("2. Delete user\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user(users, &count);
                break;
            case 2:
                delete_user(users, &count);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}