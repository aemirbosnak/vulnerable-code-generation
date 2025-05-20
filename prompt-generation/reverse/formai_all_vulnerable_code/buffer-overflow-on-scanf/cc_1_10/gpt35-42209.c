//FormAI DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 50

// Define a password struct to hold relevant information for each password
typedef struct password {
    char name[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

// Global variables for the number of passwords saved and an array to store them
int num_passwords_saved = 0;
Password saved_passwords[MAX_PASSWORD_LENGTH];

// Function prototypes
void add_password();
void view_passwords();

int main() {
    int user_choice;
    do {
        // Interact with the user
        printf("\nWelcome to the Password Management Program!\n");
        printf("1. Add a password\n");
        printf("2. View saved passwords\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &user_choice);

        // Call appropriate function based on user input
        switch (user_choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (user_choice != 3);
    return 0;
}

// Function to add a new password to the saved_passwords array
void add_password() {
    // If the array is already full, return and notify user
    if (num_passwords_saved >= MAX_PASSWORD_LENGTH) {
        printf("Cannot add another password. Maximum number of passwords reached.\n");
        return;
    }

    // Collect input from user and add new password to array
    Password new_password;
    printf("\nEnter the name of the account (e.g. Gmail, Facebook, etc.): ");
    scanf("%s", new_password.name);
    printf("Enter the account's username: ");
    scanf("%s", new_password.username);
    printf("Enter the account's password: ");
    scanf("%s", new_password.password);

    saved_passwords[num_passwords_saved] = new_password;
    num_passwords_saved++;

    printf("Password for %s added successfully.\n", new_password.name);
}

// Function to view all saved passwords
void view_passwords() {
    // If there are no passwords saved yet, return and notify user
    if (num_passwords_saved == 0) {
        printf("There are no saved passwords yet.\n");
        return;
    }

    // Print out each saved password's information
    printf("\nThere are %d saved passwords: \n", num_passwords_saved);
    for (int i = 0; i < num_passwords_saved; i++) {
        printf("%d. Account Name: %s\n", i+1, saved_passwords[i].name);
        printf("   Username: %s\n", saved_passwords[i].username);
        printf("   Password: %s\n", saved_passwords[i].password);
    }
}