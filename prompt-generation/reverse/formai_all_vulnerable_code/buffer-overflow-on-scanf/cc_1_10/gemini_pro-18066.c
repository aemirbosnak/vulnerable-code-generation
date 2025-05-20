//GEMINI-pro DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 256

// Define the number of password categories
#define NUM_PASSWORD_CATEGORIES 5

// Define the password categories
char *password_categories[] = {
    "Personal",
    "Work",
    "Financial",
    "Social",
    "Other"
};

// Define the structure of a password entry
typedef struct {
    char *category;
    char *website;
    char *username;
    char *password;
} password_entry;

// Create a new password entry
password_entry *new_password_entry(char *category, char *website, char *username, char *password) {
    password_entry *entry = malloc(sizeof(password_entry));
    entry->category = category;
    entry->website = website;
    entry->username = username;
    entry->password = password;
    return entry;
}

// Free a password entry
void free_password_entry(password_entry *entry) {
    free(entry->category);
    free(entry->website);
    free(entry->username);
    free(entry->password);
    free(entry);
}

// Print a password entry
void print_password_entry(password_entry *entry) {
    printf("Category: %s\n", entry->category);
    printf("Website: %s\n", entry->website);
    printf("Username: %s\n", entry->username);
    printf("Password: %s\n", entry->password);
}

// Compare two password entries
int compare_password_entries(password_entry *entry1, password_entry *entry2) {
    return strcmp(entry1->category, entry2->category) == 0 &&
           strcmp(entry1->website, entry2->website) == 0 &&
           strcmp(entry1->username, entry2->username) == 0 &&
           strcmp(entry1->password, entry2->password) == 0;
}

// Get a password entry from the user
password_entry *get_password_entry() {
    char category[MAX_PASSWORD_LENGTH];
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter the category of the password: ");
    scanf("%s", category);

    printf("Enter the website of the password: ");
    scanf("%s", website);

    printf("Enter the username of the password: ");
    scanf("%s", username);

    printf("Enter the password: ");
    scanf("%s", password);

    return new_password_entry(category, website, username, password);
}

// Print the password entries
void print_password_entries(password_entry **entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        print_password_entry(entries[i]);
    }
}

// Main function
int main() {
    // Create an array of password entries
    password_entry **entries = malloc(sizeof(password_entry *) * NUM_PASSWORD_CATEGORIES);

    // Get the password entries from the user
    for (int i = 0; i < NUM_PASSWORD_CATEGORIES; i++) {
        entries[i] = get_password_entry();
    }

    // Print the password entries
    print_password_entries(entries, NUM_PASSWORD_CATEGORIES);

    // Free the password entries
    for (int i = 0; i < NUM_PASSWORD_CATEGORIES; i++) {
        free_password_entry(entries[i]);
    }

    // Free the array of password entries
    free(entries);

    return 0;
}