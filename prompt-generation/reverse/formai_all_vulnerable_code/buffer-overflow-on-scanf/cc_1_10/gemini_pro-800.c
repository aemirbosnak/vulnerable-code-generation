//GEMINI-pro DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 20

// Define the number of passwords to store
#define NUM_PASSWORDS 5

// Define the password struct
typedef struct password {
    char *username;
    char *password;
} password;

// Create an array of passwords
password passwords[NUM_PASSWORDS];

// Get a password from the user
void get_password(char *username, char *password) {
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
}

// Store a password in the array
void store_password(password *password) {
    // Find an empty slot in the array
    int i;
    for (i = 0; i < NUM_PASSWORDS; i++) {
        if (passwords[i].username == NULL) {
            break;
        }
    }

    // If there is no empty slot, return an error
    if (i == NUM_PASSWORDS) {
        printf("Error: Password array is full\n");
        return;
    }

    // Copy the password into the array
    passwords[i].username = strdup(password->username);
    passwords[i].password = strdup(password->password);
}

// Retrieve a password from the array
void retrieve_password(char *username, char *password) {
    // Find the password in the array
    int i;
    for (i = 0; i < NUM_PASSWORDS; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            break;
        }
    }

    // If the password was not found, return an error
    if (i == NUM_PASSWORDS) {
        printf("Error: Password not found\n");
        return;
    }

    // Copy the password into the output parameters
    strcpy(password, passwords[i].password);
}

// Delete a password from the array
void delete_password(char *username) {
    // Find the password in the array
    int i;
    for (i = 0; i < NUM_PASSWORDS; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            break;
        }
    }

    // If the password was not found, return an error
    if (i == NUM_PASSWORDS) {
        printf("Error: Password not found\n");
        return;
    }

    // Free the memory associated with the password
    free(passwords[i].username);
    free(passwords[i].password);

    // Set the password slot to NULL
    passwords[i].username = NULL;
    passwords[i].password = NULL;
}

// Print the passwords in the array
void print_passwords() {
    int i;
    for (i = 0; i < NUM_PASSWORDS; i++) {
        if (passwords[i].username != NULL) {
            printf("%s: %s\n", passwords[i].username, passwords[i].password);
        }
    }
}

// Main function
int main() {
    // Get a password from the user
    password password;
    get_password(password.username, password.password);

    // Store the password in the array
    store_password(&password);

    // Retrieve the password from the array
    char retrieved_password[MAX_PASSWORD_LENGTH];
    retrieve_password(password.username, retrieved_password);

    // Print the retrieved password
    printf("Retrieved password: %s\n", retrieved_password);

    // Delete the password from the array
    delete_password(password.username);

    // Print the passwords in the array
    print_passwords();

    return 0;
}