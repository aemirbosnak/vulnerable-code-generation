//FormAI DATASET v1.0 Category: System administration ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining constants
#define MAX_USERS 100
#define MAX_LENGTH 50

// Defining a User struct
typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

// Declaring functions
void displayMenu();
void addUser(User users[], int *numUsers);
void removeUser(User users[], int *numUsers);
void viewUsers(User users[], int numUsers);

int main() {
    // Initializing variables
    User users[MAX_USERS];
    int numUsers = 0;
    int choice;

    // Displaying menu and getting user choice
    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addUser(users, &numUsers);
                break;
            case 2:
                removeUser(users, &numUsers);
                break;
            case 3:
                viewUsers(users, numUsers);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

// Function to display menu
void displayMenu() {
    printf("\n\nSystem Administration Menu:\n");
    printf("1. Add User\n");
    printf("2. Remove User\n");
    printf("3. View Users\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a user
void addUser(User users[], int *numUsers) {
    // Checking if there is space for another user
    if(*numUsers == MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    // Getting user input for username and password
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // Creating new User struct and adding to users array
    User newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);

    users[*numUsers] = newUser;
    *numUsers += 1;

    printf("User added successfully.\n");
}

// Function to remove a user
void removeUser(User users[], int *numUsers) {
    // Checking if there are any users to remove
    if(*numUsers == 0) {
        printf("There are no users to remove.\n");
        return;
    }

    // Getting user input for username to remove
    char username[MAX_LENGTH];

    printf("Enter username to remove: ");
    scanf("%s", username);

    // Looping through users array to find and remove user
    int i;
    for(i = 0; i < *numUsers; i++) {
        if(strcmp(users[i].username, username) == 0) {
            int j;
            for(j = i; j < *numUsers-1; j++) {
                users[j] = users[j+1];
            }
            *numUsers -= 1;
            printf("User removed successfully.\n");
            return;
        }
    }

    printf("User not found.\n");
}

// Function to view all users
void viewUsers(User users[], int numUsers) {
    // Checking if there are any users to view
    if(numUsers == 0) {
        printf("There are no users to view.\n");
        return;
    }

    // Looping through users array to print each user's information
    int i;
    for(i = 0; i < numUsers; i++) {
        printf("Username: %s\n", users[i].username);
        printf("Password: %s\n\n", users[i].password);
    }
}