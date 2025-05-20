//GEMINI-pro DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a password entry
typedef struct {
    char website[100];
    char username[50];
    char password[50];
} PasswordEntry;

// Array to store the password entries
PasswordEntry passwordEntries[100];

// Current number of password entries
int numPasswordEntries = 0;

// Function to add a new password entry
void addPasswordEntry() {
    // Get the website name
    printf("Enter the website name: ");
    scanf("%s", passwordEntries[numPasswordEntries].website);

    // Get the username
    printf("Enter the username: ");
    scanf("%s", passwordEntries[numPasswordEntries].username);

    // Get the password
    printf("Enter the password: ");
    scanf("%s", passwordEntries[numPasswordEntries].password);

    // Increment the number of password entries
    numPasswordEntries++;
}

// Function to view all password entries
void viewPasswordEntries() {
    // Print the header
    printf("%-30s %-20s %-20s\n", "Website", "Username", "Password");

    // Print each password entry
    for (int i = 0; i < numPasswordEntries; i++) {
        printf("%-30s %-20s %-20s\n", passwordEntries[i].website, passwordEntries[i].username, passwordEntries[i].password);
    }
}

// Function to search for a password entry
void searchPasswordEntry() {
    // Get the website name
    char website[100];
    printf("Enter the website name: ");
    scanf("%s", website);

    // Find the password entry
    int found = 0;
    for (int i = 0; i < numPasswordEntries; i++) {
        if (strcmp(passwordEntries[i].website, website) == 0) {
            // Print the password entry
            printf("%-30s %-20s %-20s\n", passwordEntries[i].website, passwordEntries[i].username, passwordEntries[i].password);
            found = 1;
            break;
        }
    }

    // If the password entry was not found, print an error message
    if (!found) {
        printf("Password entry not found.\n");
    }
}

// Function to delete a password entry
void deletePasswordEntry() {
    // Get the website name
    char website[100];
    printf("Enter the website name: ");
    scanf("%s", website);

    // Find the password entry
    int found = 0;
    for (int i = 0; i < numPasswordEntries; i++) {
        if (strcmp(passwordEntries[i].website, website) == 0) {
            // Delete the password entry
            for (int j = i; j < numPasswordEntries - 1; j++) {
                passwordEntries[j] = passwordEntries[j + 1];
            }
            numPasswordEntries--;
            found = 1;
            break;
        }
    }

    // If the password entry was not found, print an error message
    if (!found) {
        printf("Password entry not found.\n");
    }
}

// Main function
int main() {
    // Print the welcome message
    printf("Welcome to the Password Manager!\n");

    // Loop until the user quits
    int choice;
    do {
        // Print the menu
        printf("\n1. Add a new password entry\n2. View all password entries\n3. Search for a password entry\n4. Delete a password entry\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addPasswordEntry();
                break;
            case 2:
                viewPasswordEntries();
                break;
            case 3:
                searchPasswordEntry();
                break;
            case 4:
                deletePasswordEntry();
                break;
        }
    } while (choice != 5);

    // Print the goodbye message
    printf("Thank you for using the Password Manager!\n");

    return 0;
}