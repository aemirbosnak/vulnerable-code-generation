//GEMINI-pro DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 100

// Define the number of passwords to store
#define NUM_PASSWORDS 10

// Define the structure of a password entry
typedef struct PasswordEntry {
    char *password;
    char *website;
} PasswordEntry;

// Create an array of password entries
PasswordEntry passwords[NUM_PASSWORDS];

// Get a password from the user
char *get_password() {
    char *password = malloc(MAX_PASSWORD_LENGTH + 1);
    printf("Enter a password: ");
    scanf("%s", password);
    return password;
}

// Get a website from the user
char *get_website() {
    char *website = malloc(MAX_PASSWORD_LENGTH + 1);
    printf("Enter a website: ");
    scanf("%s", website);
    return website;
}

// Add a password entry to the array
void add_password_entry(char *password, char *website) {
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        if (passwords[i].password == NULL) {
            passwords[i].password = password;
            passwords[i].website = website;
            return;
        }
    }

    printf("Error: Password array is full.\n");
}

// Print the password entries
void print_password_entries() {
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        if (passwords[i].password != NULL) {
            printf("%s: %s\n", passwords[i].website, passwords[i].password);
        }
    }
}

// Free the memory allocated for the password entries
void free_password_entries() {
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        if (passwords[i].password != NULL) {
            free(passwords[i].password);
            free(passwords[i].website);
        }
    }
}

// Main function
int main() {
    // Get passwords and websites from the user
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        char *password = get_password();
        char *website = get_website();
        add_password_entry(password, website);
    }

    // Print the password entries
    print_password_entries();

    // Free the memory allocated for the password entries
    free_password_entries();

    return 0;
}