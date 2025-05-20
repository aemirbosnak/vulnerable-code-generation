//Falcon2-11B DATASET v1.0 Category: Password management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a user
typedef struct user {
    char username[50];
    char password[50];
} user;

// Function to create a new user
void create_user(user* user) {
    printf("Username: ");
    scanf("%s", user->username);
    printf("Password: ");
    scanf("%s", user->password);
}

// Function to delete a user
void delete_user(user* user) {
    printf("Username: ");
    scanf("%s", user->username);
}

// Function to display a user's information
void display_user(user* user) {
    printf("Username: %s\n", user->username);
    printf("Password: %s\n", user->password);
}

int main() {
    user users[100];
    int num_users = 0;

    printf("Welcome to the Password Manager!\n");

    // Initialize the user manager
    while (1) {
        printf("1. Create a new user\n");
        printf("2. Delete a user\n");
        printf("3. Display user information\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_user(&users[num_users]);
                num_users++;
                break;
            case 2:
                delete_user(&users[num_users]);
                num_users--;
                break;
            case 3:
                display_user(&users[num_users]);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}