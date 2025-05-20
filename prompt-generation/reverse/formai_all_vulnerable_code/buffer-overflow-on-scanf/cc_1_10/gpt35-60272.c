//FormAI DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct User {
    char username[20];
    char password[20];
};

// Function to check if a user exists
int userExists(struct User users[], int size, char* username) {
    for(int i = 0; i < size; i++) {
        if(strcmp(users[i].username, username) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    
    struct User users[MAX];
    int numUsers = 0;
    int loggedIn = 0;
    char currentUser[20];
    
    while(1) {
        printf("1. Create User\n");
        printf("2. Login\n");
        printf("3. Logout\n");
        printf("4. Exit\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Create new user
                if(numUsers < MAX) {
                    printf("\nEnter username: ");
                    scanf("%s", users[numUsers].username);
                    if(userExists(users, numUsers, users[numUsers].username)) {
                        printf("User already exists. Try again.\n\n");
                        break;
                    }
                    printf("Enter password: ");
                    scanf("%s", users[numUsers].password);
                    numUsers++;
                    printf("User created successfully!\n\n");
                } else {
                    printf("Maximum number of users reached.\n\n");
                }
                break;
            case 2:
                // Login
                if(loggedIn) {
                    printf("You are already logged in.\n\n");
                    break;
                }
                printf("\nEnter username: ");
                scanf("%s", currentUser);
                if(userExists(users, numUsers, currentUser)) {
                    char password[20];
                    printf("Enter password: ");
                    scanf("%s", password);
                    for(int i = 0; i < numUsers; i++) {
                        if(strcmp(users[i].username, currentUser) == 0 && strcmp(users[i].password, password) == 0) {
                            loggedIn = 1;
                            printf("Login successful!\n\n");
                            break;
                        }
                    }
                    if(!loggedIn) {
                        printf("Invalid username or password.\n\n");
                    }
                } else {
                    printf("User not found. Please create an account.\n\n");
                }
                break;
            case 3:
                // Logout
                if(loggedIn) {
                    loggedIn = 0;
                    printf("Logout successful!\n\n");
                } else {
                    printf("You are not logged in.\n\n");
                }
                break;
            case 4:
                // Exit
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }   
    }
    
    return 0;
}