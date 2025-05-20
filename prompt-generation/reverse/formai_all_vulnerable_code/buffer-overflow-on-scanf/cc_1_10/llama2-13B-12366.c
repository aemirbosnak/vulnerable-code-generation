//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: retro
// Password Management Program (c) 1985

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

// Global variables
char passwords[MAX_PASSWORDS][20];
int attempts = 0;

// Function prototypes
void prompt();
int check_password(const char *password);
void add_password(const char *password);
void list_passwords();
void remove_password(int index);

int main() {
    // Welcome message
    printf("Welcome to the Password Management Program\n");

    // Prompt user for first password
    prompt();

    // Main loop
    while (1) {
        // Check if user wants to add a new password
        if (check_password(passwords[0])) {
            // Add new password and prompt user for next one
            add_password(passwords[0]);
            prompt();
        }
        // Check if user wants to list all passwords
        else if (attempts == 0) {
            // List all passwords and prompt user for next one
            list_passwords();
            prompt();
        }
        // Check if user wants to remove a password
        else if (attempts > 0) {
            // Remove the password at the specified index
            remove_password(attempts - 1);
        }
        // Increment attempts counter
        attempts++;
    }

    // Exit program
    return 0;
}

// Functions

void prompt() {
    // Print prompt and wait for user input
    printf("Enter a password (type 'q' to quit): ");
    scanf("%19s", passwords[0]);
}

int check_password(const char *password) {
    // Check if password is valid
    if (strcmp(password, passwords[0]) == 0) {
        // Password is valid, return 1
        return 1;
    }
    // Password is invalid, return 0
    return 0;
}

void add_password(const char *password) {
    // Add password to the end of the array
    strcpy(passwords[attempts], password);
}

void list_passwords() {
    // Print all passwords
    printf("Stored passwords:\n");
    for (int i = 0; i < attempts; i++) {
        printf("%d: %s\n", i + 1, passwords[i]);
    }
}

void remove_password(int index) {
    // Remove the password at the specified index
    for (int i = index; i < attempts - 1; i++) {
        strcpy(passwords[i], passwords[i + 1]);
    }
    attempts--;
}