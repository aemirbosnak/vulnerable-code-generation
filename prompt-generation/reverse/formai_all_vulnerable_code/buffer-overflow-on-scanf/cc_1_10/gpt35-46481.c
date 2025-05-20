//FormAI DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare global variables
char password[20];
char username[20];
char retrieved_password[20];
int incorrect_attempts = 0;
int is_locked_out = 0;

// Function to retrieve a password from the user
void retrieve_password() {
    printf("\nEnter your password: ");
    scanf("%s", retrieved_password);
}

// Function to check if the entered password matches the retrieved password
int password_match() {
    if (strcmp(password, retrieved_password) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    // Welcome message
    printf("Welcome to the medieval password management system!\n");

    // Get the username from the user
    printf("Please enter your username: ");
    scanf("%s", username);

    // Get the password from the user
    printf("Please enter your password: ");
    scanf("%s", password);

    // Display the password strength
    int password_length = strlen(password);
    if (password_length <= 5) {
        printf("Your password is very weak. Please choose a stronger password.\n");
    } else if (password_length <= 10) {
        printf("Your password is weak. Please choose a stronger password.\n");
    } else if (password_length <= 15) {
        printf("Your password is moderate. You could choose a stronger password.\n");
    } else {
        printf("Your password is strong. Well done!\n");
    }

    // Enter a loop where the user can retrieve their password or exit the program
    while (1) {
        // Check if the user has been locked out
        if (is_locked_out == 1) {
            printf("\nYou have been locked out due to too many incorrect attempts. Please contact support to unlock your account.\n");
            exit(1);
        }

        // Display menu options
        printf("\n---------------------------------------\n");
        printf("Please choose an option:\n");
        printf("1. Retrieve password\n");
        printf("2. Exit program\n");
        printf("---------------------------------------\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            // Retrieve password option
            case 1:
                if (incorrect_attempts < 3) {
                    retrieve_password();
                    if (password_match() == 1) {
                        printf("\nWelcome, %s!\n", username);
                    } else {
                        incorrect_attempts++;
                        printf("\nIncorrect password. Please try again.\n");
                    }
                } else {
                    is_locked_out = 1;
                }
                break;
            // Exit option
            case 2:
                printf("Goodbye!\n");
                exit(1);
                break;
            // Invalid option
            default:
                printf("Invalid option. Please choose a valid option.\n");
        }
    }
    return 0;
}