//GEMINI-pro DATASET v1.0 Category: Password management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a password entry
typedef struct password_entry {
    char website[100];
    char username[50];
    char password[50];
} password_entry;

// Array to store the password entries
password_entry passwords[100];

// Current number of password entries
int num_passwords = 0;

// Function to add a password entry
void add_password_entry(char *website, char *username, char *password) {
    // Check if the array is full
    if (num_passwords >= 100) {
        printf("Error: Password array is full.\n");
        return;
    }
    
    // Add the password entry to the array
    strcpy(passwords[num_passwords].website, website);
    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    
    // Increment the number of password entries
    num_passwords++;
}

// Function to print a password entry
void print_password_entry(password_entry *entry) {
    printf("Website: %s\n", entry->website);
    printf("Username: %s\n", entry->username);
    printf("Password: %s\n", entry->password);
}

// Function to search for a password entry
password_entry *find_password_entry(char *website) {
    int i;
    
    // Search for the password entry
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            return &passwords[i];
        }
    }
    
    // Password entry not found
    return NULL;
}

// Function to delete a password entry
void delete_password_entry(char *website) {
    int i;
    
    // Search for the password entry
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            // Shift the remaining entries down
            memmove(&passwords[i], &passwords[i + 1], (num_passwords - i - 1) * sizeof(password_entry));
            num_passwords--;
            return;
        }
    }
}

// Main function
int main() {
    char choice;
    char website[100];
    char username[50];
    char password[50];
    password_entry *entry;
    
    while (1) {
        // Display the menu
        printf("Password Manager\n");
        printf("=================\n");
        printf("1. Add password entry\n");
        printf("2. Print password entry\n");
        printf("3. Search for password entry\n");
        printf("4. Delete password entry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        
        switch (choice) {
            case '1':
                // Add a password entry
                printf("Enter the website: ");
                scanf("%s", website);
                printf("Enter the username: ");
                scanf("%s", username);
                printf("Enter the password: ");
                scanf("%s", password);
                add_password_entry(website, username, password);
                break;
            case '2':
                // Print a password entry
                printf("Enter the website: ");
                scanf("%s", website);
                entry = find_password_entry(website);
                if (entry != NULL) {
                    print_password_entry(entry);
                } else {
                    printf("Password entry not found.\n");
                }
                break;
            case '3':
                // Search for a password entry
                printf("Enter the website: ");
                scanf("%s", website);
                entry = find_password_entry(website);
                if (entry != NULL) {
                    printf("Password entry found:\n");
                    print_password_entry(entry);
                } else {
                    printf("Password entry not found.\n");
                }
                break;
            case '4':
                // Delete a password entry
                printf("Enter the website: ");
                scanf("%s", website);
                delete_password_entry(website);
                break;
            case '5':
                // Exit the program
                exit(0);
            default:
                // Invalid choice
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}