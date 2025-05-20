//FormAI DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

// Struct representing a password entry
struct PasswordEntry {
    char domain[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

// Array of passwords
struct PasswordEntry passwords[MAX_PASSWORDS];

// Number of password entries in the array
int numPasswords = 0;

// Function to add a new password entry
void addPassword() {
    // Make sure we haven't hit the max number of passwords
    if(numPasswords >= MAX_PASSWORDS) {
        printf("Sorry, you have reached the maximum number of passwords allowed.\n");
        return;
    }
    
    // Prompt the user for the domain, username, and password
    printf("Enter the domain: ");
    scanf("%s", passwords[numPasswords].domain);
    printf("Enter the username: ");
    scanf("%s", passwords[numPasswords].username);
    printf("Enter the password: ");
    scanf("%s", passwords[numPasswords].password);
    
    // Increment the number of password entries
    numPasswords++;
    
    printf("Password added!\n");
}

// Function to list all password entries
void listPasswords() {
    // Make sure we have at least one password entry
    if(numPasswords == 0) {
        printf("You have no stored passwords.\n");
        return;
    }
    
    // Print out each password entry
    printf("%-20s%-20s%-20s\n", "Domain", "Username", "Password");
    for(int i = 0; i < numPasswords; i++) {
        printf("%-20s%-20s%-20s\n", 
        passwords[i].domain, passwords[i].username, passwords[i].password);
    }
}

// Function to search for a password entry by domain
void searchPasswords() {
    // Make sure we have at least one password entry
    if(numPasswords == 0) {
        printf("You have no stored passwords.\n");
        return;
    }
    
    // Prompt the user for the domain to search for
    printf("Enter the domain to search for: ");
    char domain[MAX_LENGTH];
    scanf("%s", domain);
    
    // Loop through each password entry to find a match
    int foundMatch = 0;
    for(int i = 0; i < numPasswords; i++) {
        if(strcmp(passwords[i].domain, domain) == 0) {
            printf("%-20s%-20s%-20s\n", 
            passwords[i].domain, passwords[i].username, passwords[i].password);
            foundMatch = 1;
        }
    }
    
    if(!foundMatch) {
        printf("No passwords found for that domain.\n");
    }
}

// Function to delete a password entry by domain
void deletePassword() {
    // Make sure we have at least one password entry
    if(numPasswords == 0) {
        printf("You have no stored passwords.\n");
        return;
    }
    
    // Prompt the user for the domain to delete
    printf("Enter the domain to delete: ");
    char domain[MAX_LENGTH];
    scanf("%s", domain);
    
    // Loop through each password entry to find a match
    int foundMatch = 0;
    for(int i = 0; i < numPasswords; i++) {
        if(strcmp(passwords[i].domain, domain) == 0) {
            // Move all the password entries after this one up by one
            for(int j = i+1; j < numPasswords; j++) {
                strcpy(passwords[j-1].domain, passwords[j].domain);
                strcpy(passwords[j-1].username, passwords[j].username);
                strcpy(passwords[j-1].password, passwords[j].password);
            }
            // Decrement the number of password entries
            numPasswords--;
            foundMatch = 1;
            printf("Password deleted!\n");
            break;
        }
    }
    
    if(!foundMatch) {
        printf("No passwords found for that domain.\n");
    }
}

int main() {
    int choice;
    
    while(1) {
        // Print out the menu
        printf("\nPassword Manager\n");
        printf("================\n");
        printf("1. Add Password\n");
        printf("2. List Passwords\n");
        printf("3. Search Passwords\n");
        printf("4. Delete Password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Handle the user's choice
        switch(choice) {
            case 1:
                addPassword();
                break;
            case 2:
                listPasswords();
                break;
            case 3:
                searchPasswords();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                printf("Thank you for using Password Manager!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}