//FormAI DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for the maximum number of users we can handle
#define MAX_USERS 100

// Define a structure for our user data
typedef struct {
    char username[20];
    char password[20];
    int uid;
} User;

// Define a function to print a menu to the user and return their choice
int menu(void) {
    int choice;
    printf("======= User Administration =======\n");
    printf("1. Add user\n");
    printf("2. Delete user\n");
    printf("3. List users\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Define a function to add a user and their password
void add_user(User *users, int *num_users, int *next_id) {
    // Check if we've reached the maximum number of users
    if (*num_users >= MAX_USERS) {
        printf("Error: Maximum number of users reached\n");
        return;
    }

    // Get the new user's username and password
    printf("Enter username: ");
    scanf("%s", users[*num_users].username);
    printf("Enter password: ");
    scanf("%s", users[*num_users].password);

    // Set the new user's ID and increment the next ID
    users[*num_users].uid = *next_id;
    (*next_id)++;

    // Increment the number of users
    (*num_users)++;

    printf("User added successfully\n");
}

// Define a function to delete a user by their ID
void delete_user(User *users, int *num_users) {
    int uid, i, j;

    // Get the ID of the user to delete
    printf("Enter the user ID to delete: ");
    scanf("%d", &uid);

    // Find the user with the given ID
    for (i = 0; i < *num_users; i++) {
        if (users[i].uid == uid) {
            // Shift the remaining users down one slot in the array
            for (j = i; j < *num_users - 1; j++) {
                users[j] = users[j+1];
            }
            // Decrement the number of users
            (*num_users)--;
            printf("User deleted successfully\n");
            return;
        }
    }

    // If we get here, the user was not found
    printf("Error: User not found\n");
}

// Define a function to list all users
void list_users(User *users, int *num_users) {
    int i;
    printf("User ID\tUsername\n");
    for (i = 0; i < *num_users; i++) {
        printf("%d\t%s\n", users[i].uid, users[i].username);
    }
}

int main(void) {
    User users[MAX_USERS];
    int num_users = 0;
    int next_id = 1;
    int choice;

    // Main loop
    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                add_user(users, &num_users, &next_id);
                break;
            case 2:
                delete_user(users, &num_users);
                break;
            case 3:
                list_users(users, &num_users);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice\n");
        }
    }

    return 0;
}