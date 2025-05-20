//FormAI DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 30

// Define a structure to store password information
struct password_info {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Define an array to store passwords
struct password_info passwords[MAX_PASSWORDS];

// Define a variable to track the number of passwords stored
int num_passwords = 0;

// Function to add a new password
void add_password() {
    // Check if there is room to add another password
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Cannot add password: memory limit reached\n");
        return;
    }
    
    // Get username and password from user
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    // Copy username and password into password struct
    strncpy(passwords[num_passwords].username, username, MAX_PASSWORD_LENGTH);
    strncpy(passwords[num_passwords].password, password, MAX_PASSWORD_LENGTH);
    
    // Increment number of passwords
    num_passwords++;
    
    printf("Password added!\n");
}

// Function to list all passwords
void list_passwords() {
    // Check if there are any passwords to list
    if (num_passwords == 0) {
        printf("No passwords stored\n");
        return;
    }
    
    // Iterate over passwords and print them
    printf("Listing passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

// Function to search for a password
void search_password() {
    // Check if there are any passwords to search
    if (num_passwords == 0) {
        printf("No passwords stored\n");
        return;
    }
    
    // Get username to search for
    char username[MAX_PASSWORD_LENGTH];
    printf("Enter username to search for: ");
    scanf("%s", username);
    
    // Search for the username in the password struct array
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password found: %s\n", passwords[i].password);
            return;
        }
    }
    
    printf("Password not found\n");
}

int main() {
    printf("Password Manager\n");
    printf("Commands:\n");
    printf("  add - add a new password\n");
    printf("  list - list all passwords\n");
    printf("  search - search for a password\n");
    printf("  exit - exit the program\n");
    
    char command[MAX_PASSWORD_LENGTH];
    while (1) {
        // Get command from user
        printf("\nEnter command: ");
        scanf("%s", command);
        
        // Handle add command
        if (strcmp(command, "add") == 0) {
            add_password();
        }
        // Handle list command
        else if (strcmp(command, "list") == 0) {
            list_passwords();
        }
        // Handle search command
        else if (strcmp(command, "search") == 0) {
            search_password();
        }
        // Handle exit command
        else if (strcmp(command, "exit") == 0) {
            exit(0);
        }
        // Handle invalid command
        else {
            printf("Invalid command\n");
        }
    }
    return 0;
}