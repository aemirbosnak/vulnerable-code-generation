//GEMINI-pro DATASET v1.0 Category: Password management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 100

// Define the number of password entries
#define NUM_PASSWORD_ENTRIES 10

// Define the structure of a password entry
typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_entry;

// Define the array of password entries
password_entry password_entries[NUM_PASSWORD_ENTRIES];

// Get a password from the user
char* get_password() {
    char* password = malloc(MAX_PASSWORD_LENGTH);
    printf("Enter your password: ");
    scanf("%s", password);
    return password;
}

// Save a password entry to the array
void save_password_entry(password_entry entry) {
    for (int i = 0; i < NUM_PASSWORD_ENTRIES; i++) {
        if (password_entries[i].username[0] == '\0') {
            password_entries[i] = entry;
            return;
        }
    }
}

// Get a password entry from the array by username
password_entry* get_password_entry(char* username) {
    for (int i = 0; i < NUM_PASSWORD_ENTRIES; i++) {
        if (strcmp(password_entries[i].username, username) == 0) {
            return &password_entries[i];
        }
    }
    return NULL;
}

// Delete a password entry from the array by username
void delete_password_entry(char* username) {
    for (int i = 0; i < NUM_PASSWORD_ENTRIES; i++) {
        if (strcmp(password_entries[i].username, username) == 0) {
            password_entries[i].username[0] = '\0';
            password_entries[i].password[0] = '\0';
            return;
        }
    }
}

// Print the array of password entries
void print_password_entries() {
    for (int i = 0; i < NUM_PASSWORD_ENTRIES; i++) {
        if (password_entries[i].username[0] != '\0') {
            printf("%s: %s\n", password_entries[i].username, password_entries[i].password);
        }
    }
}

// Main function
int main() {
    // Get a password from the user
    char* password = get_password();

    // Create a password entry
    password_entry entry;
    strcpy(entry.username, "Example User");
    strcpy(entry.password, password);

    // Save the password entry to the array
    save_password_entry(entry);

    // Get a password entry from the array by username
    password_entry* entry2 = get_password_entry("Example User");

    // Print the password entry
    printf("Username: %s\n", entry2->username);
    printf("Password: %s\n", entry2->password);

    // Delete the password entry from the array
    delete_password_entry("Example User");

    // Print the array of password entries
    print_password_entries();

    return 0;
}