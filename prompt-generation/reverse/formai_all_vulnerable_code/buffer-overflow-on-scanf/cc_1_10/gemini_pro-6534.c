//GEMINI-pro DATASET v1.0 Category: Password management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 256

// Define the number of password entries in the database
#define NUM_ENTRIES 5

// Define the structure of a password entry
typedef struct password_entry {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_entry_t;

// Define the array of password entries
password_entry_t entries[NUM_ENTRIES];

// Get a password from the user
char* get_password() {
    char* password = malloc(MAX_PASSWORD_LENGTH);
    if (password == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for password.\n");
        exit(1);
    }
    printf("Enter your password: ");
    scanf("%s", password);
    return password;
}

// Add a password entry to the database
void add_entry(char* username, char* password) {
    int i;
    for (i = 0; i < NUM_ENTRIES; i++) {
        if (entries[i].username[0] == '\0') {
            strcpy(entries[i].username, username);
            strcpy(entries[i].password, password);
            return;
        }
    }
    fprintf(stderr, "Error: Database is full.\n");
}

// Find a password entry in the database
password_entry_t* find_entry(char* username) {
    int i;
    for (i = 0; i < NUM_ENTRIES; i++) {
        if (strcmp(entries[i].username, username) == 0) {
            return &entries[i];
        }
    }
    return NULL;
}

// Print the password entries in the database
void print_entries() {
    int i;
    for (i = 0; i < NUM_ENTRIES; i++) {
        if (entries[i].username[0] != '\0') {
            printf("%s: %s\n", entries[i].username, entries[i].password);
        }
    }
}

// Main function
int main() {
    int choice;
    char* username;
    char* password;

    // Print the menu options
    printf("1. Add a password entry\n");
    printf("2. Find a password entry\n");
    printf("3. Print the password entries\n");
    printf("4. Exit\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Process the user's choice
    switch (choice) {
        case 1:
            // Get the username and password from the user
            printf("Enter the username: ");
            username = get_password();
            printf("Enter the password: ");
            password = get_password();

            // Add the password entry to the database
            add_entry(username, password);

            // Print a success message
            printf("Password entry added successfully.\n");
            break;

        case 2:
            // Get the username from the user
            printf("Enter the username: ");
            username = get_password();

            // Find the password entry in the database
            password_entry_t* entry = find_entry(username);

            // If the password entry was found, print it
            if (entry != NULL) {
                printf("Password entry found:\n");
                printf("%s: %s\n", entry->username, entry->password);
            } else {
                // If the password entry was not found, print an error message
                printf("Password entry not found.\n");
            }
            break;

        case 3:
            // Print the password entries in the database
            print_entries();
            break;

        case 4:
            // Exit the program
            exit(0);

        default:
            // Print an error message
            fprintf(stderr, "Error: Invalid choice.\n");
    }

    return 0;
}