//GEMINI-pro DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the data structure for a password entry
struct password_entry {
    char website[100];
    char username[100];
    char password[100];
};

// Declare the maximum number of password entries
#define MAX_ENTRIES 100

// Declare the array of password entries
struct password_entry entries[MAX_ENTRIES];

// Declare the number of password entries
int num_entries = 0;

// Function to add a new password entry
void add_entry() {
    // Get the website name
    printf("Enter the website name: ");
    scanf("%s", entries[num_entries].website);

    // Get the username
    printf("Enter the username: ");
    scanf("%s", entries[num_entries].username);

    // Get the password
    printf("Enter the password: ");
    scanf("%s", entries[num_entries].password);

    // Increment the number of password entries
    num_entries++;
}

// Function to view a password entry
void view_entry() {
    // Get the index of the password entry
    int index;
    printf("Enter the index of the password entry: ");
    scanf("%d", &index);

    // Check if the index is valid
    if (index < 0 || index >= num_entries) {
        printf("Invalid index\n");
        return;
    }

    // Print the password entry
    printf("Website: %s\n", entries[index].website);
    printf("Username: %s\n", entries[index].username);
    printf("Password: %s\n", entries[index].password);
}

// Function to delete a password entry
void delete_entry() {
    // Get the index of the password entry
    int index;
    printf("Enter the index of the password entry: ");
    scanf("%d", &index);

    // Check if the index is valid
    if (index < 0 || index >= num_entries) {
        printf("Invalid index\n");
        return;
    }

    // Shift the password entries down to fill the gap
    for (int i = index; i < num_entries - 1; i++) {
        entries[i] = entries[i + 1];
    }

    // Decrement the number of password entries
    num_entries--;
}

// Function to print the menu
void print_menu() {
    printf("1. Add a new password entry\n");
    printf("2. View a password entry\n");
    printf("3. Delete a password entry\n");
    printf("4. Exit\n");
}

// Main function
int main() {
    // Print a welcome message
    printf("Welcome to the Password Manager!\n");

    // Initialize the number of password entries
    num_entries = 0;

    // Run the main loop
    while (1) {
        // Print the menu
        print_menu();

        // Get the user's choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}