//FormAI DATASET v1.0 Category: System administration ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu(); // Function prototype for displaying the menu
void createUser(); // Function prototype for creating a new user
void deleteUser(); // Function prototype for deleting an existing user
int checkUserExists(char* username); // Function prototype for checking if a user already exists
void displayAllUsers(); // Function prototype for displaying all the existing users

int main() {

    char choice;
    do {
        displayMenu(); // Display the menu
        
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                createUser(); // Create a new user
                break;
            case '2':
                deleteUser(); // Delete an existing user
                break;
            case '3':
                displayAllUsers(); // Display all the existing users
                break;
            case '4':
                printf("\nExiting...\n");
                exit(0); // Exit the program
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while (choice != '4');

    return 0;
}

void displayMenu() {
    printf("\n-------------------------\n");
    printf("  User Administration\n");
    printf("-------------------------\n");
    printf("1. Create a new user\n");
    printf("2. Delete an existing user\n");
    printf("3. Display all users\n");
    printf("4. Exit\n");
    printf("-------------------------\n");
}

void createUser() {
    char username[20];
    int exists;

    printf("\nEnter the new username: ");
    scanf("%s", username);

    exists = checkUserExists(username);

    if (exists) {
        printf("User already exists.\n");
    } else {
        printf("User created successfully.\n");
    }
}

void deleteUser() {
    char username[20];
    int exists;

    printf("\nEnter the username to delete: ");
    scanf("%s", username);

    exists = checkUserExists(username);

    if (exists) {
        printf("User deleted successfully.\n");
    } else {
        printf("User does not exist.\n");
    }
}

int checkUserExists(char* username) {
    // Check if the user already exists in the system
    return 0;
}

void displayAllUsers() {
    printf("\nList of all users:\n");
    // Code to display all the existing users
}