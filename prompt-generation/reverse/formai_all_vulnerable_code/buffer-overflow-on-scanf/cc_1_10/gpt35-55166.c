//FormAI DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold password information
typedef struct {
    char *username;
    char *password;
} Password;

// Define a function to prompt user for username and password
void promptUser(char **username, char **password) {
    printf("Enter username: ");
    scanf("%ms", username); // Use %ms to allocate memory for username string
    printf("Enter password: ");
    scanf("%ms", password); // Use %ms to allocate memory for password string
}

// Define a function to create a new password
void createPassword(Password **passwords, int *numPasswords) {
    // Allocate memory for a new Password struct
    Password *newPassword = malloc(sizeof(Password));

    // Prompt user for password information
    promptUser(&(newPassword->username), &(newPassword->password));

    // Add the new password to the array of passwords
    *numPasswords += 1;
    *passwords = realloc(*passwords, (*numPasswords) * sizeof(Password));
    (*passwords)[*numPasswords - 1] = *newPassword;

    // Free the memory allocated for the temporary Password struct
    free(newPassword);
}

// Define a function to search for a password by username
Password *searchForPassword(Password *passwords, int numPasswords, char *username) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return &(passwords[i]);
        }
    }
    return NULL;
}

// Define a function to change a password
void changePassword(Password *passwords, int numPasswords) {
    char *username;
    char *oldPassword;
    char *newPassword;
    Password *foundPassword;

    // Prompt user for old username and password
    printf("Enter current username: ");
    scanf("%ms", &username);
    printf("Enter current password: ");
    scanf("%ms", &oldPassword);

    // Search for the password by username
    foundPassword = searchForPassword(passwords, numPasswords, username);

    // Verify that the old password is correct
    if (foundPassword == NULL || strcmp(foundPassword->password, oldPassword) != 0) {
        printf("Error: Could not find a password matching the provided username and password.\n");
        return;
    }

    // Prompt user for new password
    printf("Enter new password: ");
    scanf("%ms", &newPassword);

    // Change the password
    foundPassword->password = newPassword;

    printf("Password changed successfully.\n");

    // Free the memory allocated for the temporary username and password strings
    free(username);
    free(oldPassword);
}

// Define a function to delete a password
void deletePassword(Password **passwords, int *numPasswords) {
    char *username;
    Password *foundPassword;

    // Prompt user for username to delete
    printf("Enter username to delete: ");
    scanf("%ms", &username);

    // Search for the password by username
    foundPassword = searchForPassword(*passwords, *numPasswords, username);

    // If found, remove the password from the array
    if (foundPassword != NULL) {
        // Shift all subsequent elements left
        for (int i = foundPassword - *passwords; i < *numPasswords - 1; i++) {
            (*passwords)[i] = (*passwords)[i + 1];
        }
        // Decrement the number of passwords and reallocate memory
        *numPasswords -= 1;
        *passwords = realloc(*passwords, (*numPasswords) * sizeof(Password));
        printf("Password for username '%s' deleted.\n", username);
    } else {
        printf("Error: Could not find a password matching the provided username.\n");
    }

    // Free the memory allocated for the temporary username string
    free(username);
}

// Define a function to print all passwords
void printPasswords(Password *passwords, int numPasswords) {
    printf("All passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("- Username: %s, Password: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    Password *passwords = NULL;
    int numPasswords = 0;
    int choice;

    while (1) {
        // Print menu
        printf("\n");
        printf("1. Create a new password\n");
        printf("2. Search for a password\n");
        printf("3. Change a password\n");
        printf("4. Delete a password\n");
        printf("5. Print all passwords\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createPassword(&passwords, &numPasswords);
                break;
            case 2: {
                char *username;
                printf("Enter username to search: ");
                scanf("%ms", &username);
                Password *foundPassword = searchForPassword(passwords, numPasswords, username);
                if (foundPassword != NULL) {
                    printf("Password for username '%s': %s\n", username, foundPassword->password);
                } else {
                    printf("Error: Could not find a password matching the provided username.\n");
                }
                free(username);
                break;
            }
            case 3:
                changePassword(passwords, numPasswords);
                break;
            case 4:
                deletePassword(&passwords, &numPasswords);
                break;
            case 5:
                printPasswords(passwords, numPasswords);
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}