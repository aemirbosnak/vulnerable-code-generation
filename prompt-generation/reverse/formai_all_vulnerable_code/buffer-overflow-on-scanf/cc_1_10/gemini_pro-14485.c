//GEMINI-pro DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum length of a password
#define MAX_PASSWORD_LENGTH 32

// Structure to store a password entry
typedef struct {
    char website[50];
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

// Array to store the password entries
PasswordEntry entries[100];

// Current number of password entries
int num_entries = 0;

// Function to add a new password entry
void add_entry() {
    // Get the website, username, and password from the user
    printf("Enter the website: ");
    scanf("%s", entries[num_entries].website);
    printf("Enter the username: ");
    scanf("%s", entries[num_entries].username);
    printf("Enter the password: ");
    scanf("%s", entries[num_entries].password);

    // Increment the number of password entries
    num_entries++;
}

// Function to search for a password entry
void search_entry() {
    // Get the website from the user
    char website[50];
    printf("Enter the website: ");
    scanf("%s", website);

    // Search for the website in the array of password entries
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            // The website was found
            printf("Username: %s\n", entries[i].username);
            printf("Password: %s\n", entries[i].password);
            found = 1;
            break;
        }
    }

    // If the website was not found, print an error message
    if (!found) {
        printf("Website not found\n");
    }
}

// Function to delete a password entry
void delete_entry() {
    // Get the website from the user
    char website[50];
    printf("Enter the website: ");
    scanf("%s", website);

    // Search for the website in the array of password entries
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            // The website was found
            // Shift the remaining entries to the left
            for (int j = i; j < num_entries - 1; j++) {
                entries[j] = entries[j + 1];
            }
            // Decrement the number of password entries
            num_entries--;
            found = 1;
            break;
        }
    }

    // If the website was not found, print an error message
    if (!found) {
        printf("Website not found\n");
    }
}

// Function to print all password entries
void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Website: %s\n", entries[i].website);
        printf("Username: %s\n", entries[i].username);
        printf("Password: %s\n", entries[i].password);
        printf("\n");
    }
}

// Main function
int main() {
    // Print the welcome message
    printf("Welcome to the password manager!\n");

    // Loop until the user quits
    while (1) {
        // Print the menu
        printf("\nOptions:\n");
        printf("1. Add a new password entry\n");
        printf("2. Search for a password entry\n");
        printf("3. Delete a password entry\n");
        printf("4. Print all password entries\n");
        printf("5. Quit\n");

        // Get the user's choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                print_entries();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}