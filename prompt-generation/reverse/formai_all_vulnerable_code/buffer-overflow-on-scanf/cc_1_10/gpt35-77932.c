//FormAI DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining constant variables
#define MAX_PASSWORDS 100
#define MAX_LENGTH 20

// Defining the structure for storing passwords
struct Password {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

// Function to add a password to the collection
void add_password(struct Password *passwords, int *count) {
    
    // Checking if maximum passwords have been reached
    if (*count >= MAX_PASSWORDS) {
        printf("Maximum passwords reached.");
        return;
    }
    
    // Getting user input for website, username and password
    printf("Enter website name: ");
    scanf("%s", passwords[*count].website);
    printf("Enter username: ");
    scanf("%s", passwords[*count].username);
    printf("Enter password: ");
    scanf("%s", passwords[*count].password);
    
    // Incrementing the count of passwords
    *count += 1;
    
    printf("Password added successfully.\n");
}

// Function to view all passwords in the collection
void view_passwords(struct Password *passwords, int count) {
    
    // Checking if there are no passwords
    if (count == 0) {
        printf("No passwords to show.");
        return;
    }
    
    // Displaying all the passwords one by one
    printf("Website\tUsername\tPassword\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

// Function to search for a specific password
void search_password(struct Password *passwords, int count) {
    
    // Checking if there are no passwords
    if (count == 0) {
        printf("No passwords to search.");
        return;
    }
    
    // Getting user input for the website to be searched
    char website[MAX_LENGTH];
    printf("Enter website name to be searched: ");
    scanf("%s", website);
    
    // Searching for the website name and displaying the corresponding
    // username and password
    int found = 0;
    for (int i =0; i < count; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Website not found.");
    }
}

// Function to delete a specific password
void delete_password(struct Password *passwords, int *count) {
    
    // Checking if there are no passwords
    if (*count == 0) {
        printf("No passwords to delete.");
        return;
    }
    
    // Getting user input for the website to be deleted
    char website[MAX_LENGTH];
    printf("Enter website name to be deleted: ");
    scanf("%s", website);
    
    // Searching for the website name and deleting the corresponding password
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            for (int j = i; j < *count - 1; j++) {
                passwords[j] = passwords[j+1];
            }
            *count -= 1;
            found = 1;
            printf("Password deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Website not found.");
    }
}

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int count = 0;
    int choice;
    
    // Main menu loop
    while (1) {
        printf("\nPassword Manager\n");
        printf("-----------------\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Search Password\n");
        printf("4. Delete Password\n");
        printf("5. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_password(passwords, &count);
                break;
            case 2:
                view_passwords(passwords, count);
                break;
            case 3:
                search_password(passwords, count);
                break;
            case 4:
                delete_password(passwords, &count);
                break;
            case 5:
                printf("Thank you for using Password Manager.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}