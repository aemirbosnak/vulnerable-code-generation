//FormAI DATASET v1.0 Category: System administration ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERS 10

struct user {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int isAdmin;
};

struct user users[MAX_USERS];
int numUsers = 0;

void addUser() {
    if (numUsers >= MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }
    
    struct user newUser;
    
    printf("Enter username: ");
    scanf("%s", newUser.username);
    
    printf("Enter password: ");
    scanf("%s", newUser.password);
    
    printf("Is this user an admin? (1 for yes, 0 for no): ");
    scanf("%d", &newUser.isAdmin);
    
    users[numUsers++] = newUser;
}

void deleteUser() {
    if (numUsers == 0) {
        printf("Error: There are no users to delete.\n");
        return;
    }
    
    char username[MAX_USERNAME_LENGTH];
    
    printf("Enter the username of the user you want to delete: ");
    scanf("%s", username);
    
    int foundIndex = -1;
    
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex == -1) {
        printf("Error: User not found.\n");
        return;
    }
    
    for (int i = foundIndex; i < numUsers - 1; i++) {
        users[i] = users[i + 1];
    }
    
    numUsers--;
    
    printf("User successfully deleted.\n");
}

void printAllUsers() {
    if (numUsers == 0) {
        printf("There are no users to display.\n");
        return;
    }
    
    printf("Username\tPassword\tIs Admin\n");
    
    for (int i = 0; i < numUsers; i++) {
        printf("%s\t\t%s\t\t%s\n",
               users[i].username,
               users[i].password,
               users[i].isAdmin ? "true" : "false");
    }
}

int main() {
    int choice;
    
    do {
        printf("\nUser Administration\n");
        printf("1. Add user\n");
        printf("2. Delete user\n");
        printf("3. Display all users\n");        
        printf("0. Exit\n\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                deleteUser();
                break;
            case 3:
                printAllUsers();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0);
    
    return 0;
}