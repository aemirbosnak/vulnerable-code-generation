//FormAI DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 30

// Define a structure for each password entry
struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char value[MAX_PASSWORD_LENGTH];
};

// Declare an array to hold all of the password entries
struct Password passwords[MAX_PASSWORDS];

// Declare a variable to keep track of how many passwords have been added
int numPasswords = 0;

// Function to add a password to the list
void addPassword(char name[], char value[]) {
    // Check if we have reached the maximum number of passwords
    if (numPasswords == MAX_PASSWORDS) {
        printf("Maximum number of passwords reached!\n");
        return;
    }
    
    // Copy the name and value into the new password entry
    strcpy(passwords[numPasswords].name, name);
    strcpy(passwords[numPasswords].value, value);
    
    // Increment the number of passwords
    numPasswords++;
    
    printf("Password added!\n");
}

// Function to remove a password from the list
void removePassword(char name[]) {
    int i;
    int removed = 0; // Flag to keep track of whether a password was removed
    
    // Loop through all of the password entries
    for (i = 0; i < numPasswords; i++) {
        // Check if the name matches the password we want to remove
        if (strcmp(passwords[i].name, name) == 0) {
            // Shift all of the passwords after this one back by one
            while (i < numPasswords - 1) {
                strcpy(passwords[i].name, passwords[i+1].name);
                strcpy(passwords[i].value, passwords[i+1].value);
                i++;
            }
            
            // Decrement the number of passwords
            numPasswords--;
            
            // Set the removed flag
            removed = 1;
            
            break;
        }
    }
    
    // Print a message depending on whether a password was removed or not
    if (removed) {
        printf("Password removed!\n");
    } else {
        printf("Password not found!\n");
    }
}

// Function to view a password from the list
void viewPassword(char name[]) {
    int i;
    int found = 0; // Flag to keep track of whether a password was found
    
    // Loop through all of the password entries
    for (i = 0; i < numPasswords; i++) {
        // Check if the name matches the password we want to view
        if (strcmp(passwords[i].name, name) == 0) {
            // Print the password value
            printf("Password for %s: %s\n", name, passwords[i].value);
            
            // Set the found flag
            found = 1;
            
            break;
        }
    }
    
    // Print a message depending on whether a password was found or not
    if (!found) {
        printf("Password not found!\n");
    }
}

// Main function
int main() {
    int choice;
    char name[MAX_PASSWORD_LENGTH];
    char value[MAX_PASSWORD_LENGTH];
    
    printf("Welcome to Password Manager!\n");
    
    // Loop until the user chooses to exit
    while (1) {
        printf("Choose an option:\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. View password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Handle the user's choice
        switch (choice) {
            case 1:
                printf("Enter the name of the password: ");
                scanf("%s", name);
                printf("Enter the value of the password: ");
                scanf("%s", value);
                addPassword(name, value);
                break;
            case 2:
                printf("Enter the name of the password: ");
                scanf("%s", name);
                removePassword(name);
                break;
            case 3:
                printf("Enter the name of the password: ");
                scanf("%s", name);
                viewPassword(name);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}