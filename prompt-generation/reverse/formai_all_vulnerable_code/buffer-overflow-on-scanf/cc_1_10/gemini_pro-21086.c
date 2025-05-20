//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a password entry
typedef struct password_entry {
    char *name; // The name of the website or service
    char *username; // The username or email address
    char *password; // The password
    struct password_entry *next; // A pointer to the next entry in the list
} password_entry_t;

// Define the head of the password list
password_entry_t *head = NULL;

// Read a password entry from the user
void read_password_entry(password_entry_t *entry) {
    printf("Enter the name of the website or service: ");
    scanf("%s", entry->name);

    printf("Enter your username or email address: ");
    scanf("%s", entry->username);

    printf("Enter your password: ");
    scanf("%s", entry->password);
}

// Add a password entry to the list
void add_password_entry(password_entry_t *entry) {
    // If the list is empty, make the new entry the head of the list
    if (head == NULL) {
        head = entry;
    } else {
        // Otherwise, add the new entry to the end of the list
        password_entry_t *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = entry;
    }
}

// Print a password entry
void print_password_entry(password_entry_t *entry) {
    printf("Name: %s\n", entry->name);
    printf("Username: %s\n", entry->username);
    printf("Password: %s\n\n", entry->password);
}

// Print the entire password list
void print_password_list() {
    password_entry_t *current = head;
    while (current != NULL) {
        print_password_entry(current);
        current = current->next;
    }
}

// Free the memory allocated for a password entry
void free_password_entry(password_entry_t *entry) {
    free(entry->name);
    free(entry->username);
    free(entry->password);
    free(entry);
}

// Free the entire password list
void free_password_list() {
    password_entry_t *current = head;
    while (current != NULL) {
        password_entry_t *next = current->next;
        free_password_entry(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a new password entry
    password_entry_t *entry = malloc(sizeof(password_entry_t));

    // Read the password entry from the user
    read_password_entry(entry);

    // Add the password entry to the list
    add_password_entry(entry);

    // Print the entire password list
    print_password_list();

    // Free the memory allocated for the password entry
    free_password_entry(entry);

    return 0;
}