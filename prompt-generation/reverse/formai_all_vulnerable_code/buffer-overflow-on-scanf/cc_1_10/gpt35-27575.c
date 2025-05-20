//FormAI DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

// Function declarations
void add_password(char passwords[][MAX_PASSWORD_LENGTH], int* num_passwords);
void view_passwords(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords);

// Main function
int main(void) {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];  // Array to store passwords
    int num_passwords = 0;  // Counter for number of passwords
    
    // Welcome message
    printf("Welcome to the password management program!\n\n");
    
    // Loop for menu options
    while(1) {
        int choice;
        
        // Menu
        printf("Menu:\n");
        printf("1. Add a password\n");
        printf("2. View stored passwords\n");
        printf("3. Exit\n\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            case 2:
                view_passwords(passwords, num_passwords);
                break;
            case 3:
                printf("\nThank you for using the password management program!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}

// Function to add a password
void add_password(char passwords[][MAX_PASSWORD_LENGTH], int* num_passwords) {
    // Check if maximum number of passwords have been added
    if(*num_passwords == MAX_PASSWORDS) {
        printf("\nMaximum number of passwords have been added. Cannot add any more.\n");
        return;
    }
    
    // Get password from user
    char password[MAX_PASSWORD_LENGTH];
    printf("\nEnter your password: ");
    scanf("%s", password);
    
    // Check if password is too long
    if(strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("\nPassword is too long. Please enter a password within %d characters.\n", MAX_PASSWORD_LENGTH);
        return;
    }
    
    // Add password to array
    strcpy(passwords[(*num_passwords)++], password);
    
    printf("\nPassword added successfully!\n");
}

// Function to view stored passwords
void view_passwords(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords) {
    // Check if no passwords have been added
    if(num_passwords == 0) {
        printf("\nNo passwords have been added.\n");
        return;
    }
    
    // Print passwords
    printf("\nStored passwords:\n");
    for(int i = 0; i < num_passwords; i++) {
        printf("%s\n", passwords[i]);
    }
}