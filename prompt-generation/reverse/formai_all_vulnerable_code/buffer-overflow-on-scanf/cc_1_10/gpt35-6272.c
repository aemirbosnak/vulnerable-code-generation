//FormAI DATASET v1.0 Category: Password management ; Style: calm
/*
This is a simple password management program that allows the user to input and store various passwords for different accounts.
It prompts the user to select from a menu of options including adding a new password, displaying all passwords, removing a password, 
or searching for a specific password.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 10
#define MAX_LENGTH 50

// Define a struct to hold account and password information
struct Password {
    char account[MAX_LENGTH];
    char password[MAX_LENGTH];
};

// Declare an array of Password structs to hold all the passwords
struct Password passwords[ARRAY_SIZE];

// Declare functions for each option in the menu
void add_password();
void display_passwords();
void remove_password();
void search_password();

// Declare a function to clear the input buffer
void clear_buffer();

int main() {
    int choice;
    
    do {
        // Print the menu options to the user
        printf("\n====== Password Management ======\n");
        printf("1. Add Password\n");
        printf("2. Display Passwords\n");
        printf("3. Remove Password\n");
        printf("4. Search Password\n");
        printf("5. Exit\n");
        
        // Prompt the user to enter a choice
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
    
        switch(choice) {
            case 1:
                add_password();
                break;
            case 2:
                display_passwords();
                break;
            case 3:
                remove_password();
                break;
            case 4:
                search_password();
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please select again.\n");
                break;
        } 
    } while(choice != 5);
    
    return 0;
}

void add_password() {
    char account[MAX_LENGTH];
    char password[MAX_LENGTH];
    int i;
    
    // Prompt the user to enter the account and password
    printf("\nEnter the account name: ");
    scanf("%s", account);
    
    // Check if the account already exists
    for(i = 0; i < ARRAY_SIZE; i++) {
        if(strcmp(passwords[i].account, account) == 0) {
            printf("\nAccount already exists!\n");
            return;
        }
    }
    
    printf("Enter the password: ");
    scanf("%s", password);
    
    // Create a new Password struct with the entered account and password information
    struct Password new_password;
    strcpy(new_password.account, account);
    strcpy(new_password.password, password);
    
    // Add the new Password struct to the passwords array
    for(i = 0; i < ARRAY_SIZE; i++) {
        if(strcmp(passwords[i].account, "") == 0) {
            passwords[i] = new_password;
            printf("\nPassword added successfully!\n");
            return;
        }
    }
    
    printf("\nPassword storage is full. Please remove a password before adding a new one.\n");
}

void display_passwords() {
    int i;
    
    // Check if any passwords have been added yet
    if(strcmp(passwords[0].account, "") == 0) {
        printf("\nNo passwords have been added yet.\n");
        return;
    }
    
    // Display all the passwords in the array
    printf("\nAll Saved Passwords:\n");
    for(i = 0; i < ARRAY_SIZE; i++) {
        if(strcmp(passwords[i].account, "") != 0) {
            printf("%d. Account: %s  Password: %s\n", i+1, passwords[i].account, passwords[i].password);
        }
    }
}

void remove_password() {
    char account[MAX_LENGTH];
    int i;
    
    // Prompt the user to enter the account they want to remove
    printf("\nEnter the account to remove: ");
    scanf("%s", account);
    
    // Remove the password from the passwords array
    for(i = 0; i < ARRAY_SIZE; i++) {
        if(strcmp(passwords[i].account, account) == 0) {
            passwords[i].account[0] = '\0';
            passwords[i].password[0] = '\0';
            printf("\nPassword removed successfully!\n");
            return;
        }
    }
    
    printf("\nThe account %s was not found.\n", account);
}

void search_password() {
    char account[MAX_LENGTH];
    int i;
    
    // Prompt the user to enter the account they want to search for
    printf("\nEnter the account to search: ");
    scanf("%s", account);
    
    // Search for the account in the passwords array
    for(i = 0; i < ARRAY_SIZE; i++) {
        if(strcmp(passwords[i].account, account) == 0) {
            printf("\nPassword for account %s is: %s\n", account, passwords[i].password);
            return;
        }
    }
    
    printf("\nThe account %s was not found.\n", account);
}

void clear_buffer() {
    while(getchar() != '\n');
}