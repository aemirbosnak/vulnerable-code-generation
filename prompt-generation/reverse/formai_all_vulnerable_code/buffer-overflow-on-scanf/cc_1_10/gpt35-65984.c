//FormAI DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a user account
typedef struct {
    char username[30];
    char password[30];
    int uid;
} UserAccount;

// Define a function to add a new user account
void addUser(UserAccount* users, int* numUsers) {
    // Get input from the user for the new account
    char newUsername[30];
    char newPassword[30];
    printf("Enter a new username: ");
    scanf("%s", newUsername);
    printf("Enter a new password: ");
    scanf("%s", newPassword);

    // Check if the username already exists
    for (int i = 0; i < *numUsers; i++) {
        if (strcmp(users[i].username, newUsername) == 0) {
            printf("Error: username already exists\n");
            return;
        }
    }

    // Create the new account
    UserAccount newAccount;
    strcpy(newAccount.username, newUsername);
    strcpy(newAccount.password, newPassword);
    newAccount.uid = (*numUsers) + 1;

    // Add the new account to the users array
    users[*numUsers] = newAccount;
    (*numUsers)++;
    printf("New account created with UID %d\n", newAccount.uid);
}

// Define a function to remove an existing user account
void removeUser(UserAccount* users, int* numUsers, int uid) {
    // Find the user account with the specified UID
    int index = -1;
    for (int i = 0; i < *numUsers; i++) {
        if (users[i].uid == uid) {
            index = i;
            break;
        }
    }

    // If the user account was not found, print an error message and return
    if (index == -1) {
        printf("Error: user with UID %d not found\n", uid);
        return;
    }

    // Remove the user account
    for (int i = index; i < (*numUsers) - 1; i++) {
        users[i] = users[i + 1];
    }
    (*numUsers)--;
    printf("User with UID %d has been removed\n", uid);
}

int main() {
    // Define an array of UserAccount structs to hold user data
    UserAccount users[100];

    // Initialize the number of users to 0
    int numUsers = 0;

    // Define variables to hold input from the user
    char command[30];
    int uid;

    // Display a welcome message and prompt the user for input
    printf("Welcome to the user account administration program.\n");
    printf("Type 'add' to add a new user account or 'remove' to remove an existing account.\n");

    // Enter a loop to handle user input
    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            addUser(users, &numUsers);
        }
        else if (strcmp(command, "remove") == 0) {
            printf("Enter the UID of the user account to remove: ");
            scanf("%d", &uid);
            removeUser(users, &numUsers, uid);
        }
        else {
            printf("Error: invalid command\n");
        }
    }

    // Return 0 to indicate successful execution
    return 0;
}