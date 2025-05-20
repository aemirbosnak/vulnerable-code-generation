//FormAI DATASET v1.0 Category: System administration ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void addUser();
void deleteUser();
void editUser();

// User struct
typedef struct {
    char username[20];
    char password[20];
    int isAdmin;
} user;

// Global variables
user users[50];
int numUsers = 0;
char adminPass[20] = "root";

// Main function
int main() {
    int choice;
    
    // Loop until user quits
    while(1) {
        // Print menu
        printf("-----------------\n");
        printf("1. Add user\n");
        printf("2. Delete user\n");
        printf("3. Edit user\n");
        printf("4. Quit\n");
        printf("-----------------\n");
        printf("Enter choice: ");
        
        // Get user choice
        scanf("%d", &choice);
        
        // Switch statement for menu
        switch(choice) {
            case 1:
                addUser();
                break;
            
            case 2:
                deleteUser();
                break;
            
            case 3:
                editUser();
                break;
            
            case 4:
                printf("Quitting...\n");
                exit(0);
            
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}

// Function to add a new user
void addUser() {
    // Check if maximum users reached
    if(numUsers == 50) {
        printf("Maximum number of users reached. Cannot add more.\n");
        return;
    }
    
    // Get new user details
    printf("Enter username: ");
    scanf("%s", users[numUsers].username);
    printf("Enter password: ");
    scanf("%s", users[numUsers].password);
    printf("Is user admin (0 for no, 1 for yes): ");
    scanf("%d", &users[numUsers].isAdmin);
    
    // Increment number of users
    numUsers++;
    
    printf("User added successfully.\n");
}

// Function to delete an existing user
void deleteUser() {
    char username[20];
    int i, index = -1;
    
    // Get username of user to delete
    printf("Enter username of user to delete: ");
    scanf("%s", username);
    
    // Search for user and get index
    for(i = 0; i < numUsers; i++) {
        if(strcmp(users[i].username, username) == 0) {
            index = i;
            break;
        }
    }
    
    // If user not found, return
    if(index == -1) {
        printf("User with username %s not found.\n", username);
        return;
    }
    
    // If user is admin and trying to delete themselves, ask for admin password
    if(users[index].isAdmin && strcmp(users[index].username, "root") == 0) {
        char password[20];
        
        printf("Enter admin password to delete admin user: ");
        scanf("%s", password);
        
        if(strcmp(password, adminPass) != 0) {
            printf("Incorrect admin password.\n");
            return;
        }
    }
    
    // Shift all other users and decrease number of users
    for(i = index; i < numUsers - 1; i++) {
        users[i] = users[i + 1];
    }
    
    numUsers--;
    
    printf("User deleted successfully.\n");
}

// Function to edit an existing user
void editUser() {
    char username[20];
    int i, index = -1;
    
    // Get username of user to edit
    printf("Enter username of user to edit: ");
    scanf("%s", username);
    
    // Search for user and get index
    for(i = 0; i < numUsers; i++) {
        if(strcmp(users[i].username, username) == 0) {
            index = i;
            break;
        }
    }
    
    // If user not found, return
    if(index == -1) {
        printf("User with username %s not found.\n", username);
        return;
    }
    
    // Get new user details
    printf("Enter new password (press Enter to keep current password): ");
    char password[20];
    fgets(password, 20, stdin); // consume newline character
    fgets(password, 20, stdin);
    
    if(password[0] != '\n') {
        password[strlen(password) - 1] = '\0'; // remove newline character
        strcpy(users[index].password, password);
    }
    
    printf("Is user admin (0 for no, 1 for yes): ");
    scanf("%d", &users[index].isAdmin);
    
    printf("User edited successfully.\n");
}