//FormAI DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for maximum password length and maximum number of stored passwords
#define MAX_PASSWORD_LENGTH 20
#define MAX_NUM_PASSWORDS 10

// Define a struct to represent a single password
struct password {
    char site[50];
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
};

// Define a function to prompt the user to add a password and store it in the passwords array
void add_password(struct password passwords[], int num_passwords) {
    // Check if the passwords array is already full
    if (num_passwords >= MAX_NUM_PASSWORDS) {
        printf("Cannot store any more passwords. Please delete an existing password first.\n");
    } else {
        // Prompt the user to enter the site, username, and password for the new password
        printf("Enter the site for the new password (e.g. google.com): ");
        scanf("%s", passwords[num_passwords].site);
        printf("Enter the username for the new password: ");
        scanf("%s", passwords[num_passwords].username);
        printf("Enter the password for the new password (must be %d characters or less): ", MAX_PASSWORD_LENGTH);
        scanf("%s", passwords[num_passwords].password);

        // Increment the number of passwords in the array
        num_passwords++;

        // Let the user know the password was successfully added
        printf("Password added successfully.\n");
    }
}

// Define a function to prompt the user to view a specific password
void view_password(struct password passwords[], int num_passwords) {
    // Check if there are no passwords stored yet
    if (num_passwords == 0) {
        printf("No passwords stored yet.\n");
    } else {
        // Prompt the user to enter the site and username for the password they want to view
        char site[50];
        char username[50];
        printf("Enter the site for the password you want to view: ");
        scanf("%s", site);
        printf("Enter the username for the password you want to view: ");
        scanf("%s", username);

        // Loop through the passwords array to find a match for the specified site and username
        bool found_password = false;
        for (int i = 0; i < num_passwords; i++) {
            if (strcmp(passwords[i].site, site) == 0 && strcmp(passwords[i].username, username) == 0) {
                // Print the password
                printf("Site: %s\n", passwords[i].site);
                printf("Username: %s\n", passwords[i].username);
                printf("Password: %s\n", passwords[i].password);

                // Set found_password to true and break out of the loop
                found_password = true;
                break;
            }
        }

        // If no match was found, let the user know
        if (!found_password) {
            printf("No password found for the specified site and username.\n");
        }
    }
}

// Define a function to prompt the user to delete a specific password
void delete_password(struct password passwords[], int *num_passwords_pointer) {
    // Check if there are no passwords stored yet
    if (*num_passwords_pointer == 0) {
        printf("No passwords stored yet.\n");
    } else {
        // Prompt the user to enter the site and username for the password they want to delete
        char site[50];
        char username[50];
        printf("Enter the site for the password you want to delete: ");
        scanf("%s", site);
        printf("Enter the username for the password you want to delete: ");
        scanf("%s", username);

        // Loop through the passwords array to find a match for the specified site and username
        bool found_password = false;
        for (int i = 0; i < *num_passwords_pointer; i++) {
            if (strcmp(passwords[i].site, site) == 0 && strcmp(passwords[i].username, username) == 0) {
                // Move all subsequent passwords in the array back one index to "delete" this password
                for (int j = i; j < *num_passwords_pointer - 1; j++) {
                    passwords[j] = passwords[j + 1];
                }

                // Decrement the number of passwords in the array
                (*num_passwords_pointer)--;

                // Set found_password to true and break out of the loop
                found_password = true;
                break;
            }
        }

        // If no match was found, let the user know
        if (!found_password) {
            printf("No password found for the specified site and username.\n");
        } else {
            // Let the user know that the password was deleted successfully
            printf("Password deleted successfully.\n");
        }
    }
}

int main() {
    // Initialize an array to store all password structs
    struct password passwords[MAX_NUM_PASSWORDS];

    // Initialize the number of stored passwords to 0
    int num_passwords = 0;

    // Print an initial welcome message and prompt the user to choose an option
    printf("Welcome to the Password Manager!\n");
    char input[50];
    while (true) {
        printf("\nWhat would you like to do?\n");
        printf("a - Add a password\n");
        printf("v - View a password\n");
        printf("d - Delete a password\n");
        printf("q - Quit\n");
        printf("> ");
        scanf("%s", input);
        printf("\n");

        // Call the appropriate function based on the user's input
        if (strcmp(input, "a") == 0) {
            add_password(passwords, num_passwords);
        } else if (strcmp(input, "v") == 0) {
            view_password(passwords, num_passwords);
        } else if (strcmp(input, "d") == 0) {
            delete_password(passwords, &num_passwords);
        } else if (strcmp(input, "q") == 0) {
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    // Print a final message before exiting
    printf("Thank you for using the Password Manager!\n");
    return 0;
}