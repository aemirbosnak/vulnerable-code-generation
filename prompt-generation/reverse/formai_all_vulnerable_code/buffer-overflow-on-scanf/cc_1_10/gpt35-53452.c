//FormAI DATASET v1.0 Category: System administration ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct representing a user on the system */
struct User {
    char name[20];
    char username[20];
    char password[20];
    int isAdmin;
};

/* Prototype for function to add new user */
void addUser();

/* Prototype for function to remove user */
void removeUser();

/* Array to hold all users */
struct User users[100];

/* Counter for number of users */
int numUsers = 0;

int main() {
    int choice;
    do {
        /* Display menu options */
        printf("Choose an option:\n");
        printf("1. Add a user\n");
        printf("2. Remove a user\n");
        printf("3. Show all users\n");
        printf("4. Exit\n");

        /* Read in user's choice */
        scanf("%d", &choice);
        
        /* Perform action depending on user's choice */
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                removeUser();
                break;
            case 3:
                printf("Name\tUsername\tIs Admin\n");
                printf("------------------------------\n");
                for (int i = 0; i < numUsers; i++) {
                    printf("%s\t%s\t\t%d\n", users[i].name, users[i].username, users[i].isAdmin);
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
    } while (choice != 4); /* Continue looping unless user chooses to exit */
    
    return 0;
}

/* Function to add a new user */
void addUser() {
    /* Check if maximum user limit has been reached */
    if (numUsers == 100) {
        printf("Maximum number of users has been reached. Cannot add new user.\n");
        return;
    }
    
    /* Read in user's information */
    printf("Enter name: ");
    scanf("%s", users[numUsers].name);
    
    printf("Enter username: ");
    scanf("%s", users[numUsers].username);
    
    printf("Enter password: ");
    scanf("%s", users[numUsers].password);
    
    printf("Enter 1 if user is admin, 0 otherwise: ");
    scanf("%d", &users[numUsers].isAdmin);
    
    numUsers++; /* Increment number of users */
    
    printf("User added successfully.\n");
}

/* Function to remove a user */
void removeUser() {
    char username[20];
    printf("Enter username of user to remove: ");
    scanf("%s", username);
    
    int index = -1; /* Index of user to be removed */
    
    /* Search for user with given username */
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("User with username %s not found.\n", username);
        return;
    }
    
    /* Shift all users after the user to be removed back by one position */
    for (int i = index; i < numUsers - 1; i++) {
        strcpy(users[i].name, users[i+1].name);
        strcpy(users[i].username, users[i+1].username);
        strcpy(users[i].password, users[i+1].password);
        users[i].isAdmin = users[i+1].isAdmin;
    }
    
    numUsers--; /* Decrement number of users */
    
    printf("User with username %s removed successfully.\n", username);
}