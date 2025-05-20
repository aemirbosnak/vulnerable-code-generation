//GEMINI-pro DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 100

// Define the number of passwords to store
#define NUM_PASSWORDS 10

// Define the structure of a password
typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

// Define the array of passwords
Password passwords[NUM_PASSWORDS];

// Get a password from the user
void get_password(Password *password) {
    printf("Enter your username: ");
    scanf("%s", password->username);

    printf("Enter your password: ");
    scanf("%s", password->password);
}

// Store a password in the array
void store_password(Password *password) {
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        if (passwords[i].username[0] == '\0') {
            passwords[i] = *password;
            break;
        }
    }
}

// Retrieve a password from the array
Password *retrieve_password(char *username) {
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return &passwords[i];
        }
    }

    return NULL;
}

// Delete a password from the array
void delete_password(char *username) {
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            passwords[i].username[0] = '\0';
            passwords[i].password[0] = '\0';
            break;
        }
    }
}

// Print the array of passwords
void print_passwords() {
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        if (passwords[i].username[0] != '\0') {
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
        }
    }
}

// Main function
int main() {
    // Get a password from the user
    Password password;
    get_password(&password);

    // Store the password in the array
    store_password(&password);

    // Retrieve the password from the array
    Password *retrieved_password = retrieve_password(password.username);

    // Print the retrieved password
    if (retrieved_password != NULL) {
        printf("Retrieved password:\n");
        printf("Username: %s\n", retrieved_password->username);
        printf("Password: %s\n", retrieved_password->password);
    } else {
        printf("Password not found.\n");
    }

    // Delete the password from the array
    delete_password("admin");

    // Print the array of passwords
    printf("Passwords:\n");
    print_passwords();

    return 0;
}