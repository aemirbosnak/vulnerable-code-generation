//GEMINI-pro DATASET v1.0 Category: Password management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 100

// Define the number of passwords to store
#define NUM_PASSWORDS 10

// Define the structure of a password
typedef struct {
    char *name;
    char *password;
} Password;

// Create an array of passwords
Password passwords[NUM_PASSWORDS];

// Get a password from the user
Password get_password() {
    Password password;

    // Get the name of the password
    printf("Enter the name of the password: ");
    password.name = malloc(MAX_PASSWORD_LENGTH);
    scanf("%s", password.name);

    // Get the password
    printf("Enter the password: ");
    password.password = malloc(MAX_PASSWORD_LENGTH);
    scanf("%s", password.password);

    // Return the password
    return password;
}

// Store a password in the array of passwords
void store_password(Password password) {
    // Find an empty slot in the array of passwords
    int i;
    for (i = 0; i < NUM_PASSWORDS; i++) {
        if (passwords[i].name == NULL) {
            break;
        }
    }

    // If there is no empty slot, then print an error message
    if (i == NUM_PASSWORDS) {
        printf("Error: no more space to store passwords.\n");
        return;
    }

    // Store the password in the array of passwords
    passwords[i] = password;
}

// Get a password from the array of passwords by name
Password *get_password_by_name(char *name) {
    // Find the password in the array of passwords
    int i;
    for (i = 0; i < NUM_PASSWORDS; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            return &passwords[i];
        }
    }

    // If the password is not found, then print an error message
    printf("Error: no password found with that name.\n");
    return NULL;
}

// Print all of the passwords in the array of passwords
void print_passwords() {
    // Print the passwords
    int i;
    for (i = 0; i < NUM_PASSWORDS; i++) {
        if (passwords[i].name != NULL) {
            printf("%s: %s\n", passwords[i].name, passwords[i].password);
        }
    }
}

// Free the memory allocated for the passwords
void free_passwords() {
    // Free the memory allocated for the passwords
    int i;
    for (i = 0; i < NUM_PASSWORDS; i++) {
        if (passwords[i].name != NULL) {
            free(passwords[i].name);
            free(passwords[i].password);
        }
    }
}

// Main function
int main() {
    // Get a password from the user
    Password password = get_password();

    // Store the password in the array of passwords
    store_password(password);

    // Get a password from the array of passwords by name
    Password *password2 = get_password_by_name(password.name);

    // Print the passwords
    print_passwords();

    // Free the memory allocated for the passwords
    free_passwords();

    return 0;
}