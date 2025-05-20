//FormAI DATASET v1.0 Category: Password management ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int num_users = 0;

/* Function to print all users and their passwords */
void print_users() {
    printf("List of users:\n");
    for(int i = 0; i < num_users; i++) {
        printf("%s: %s\n", users[i].username, users[i].password);
    }
}

/* Function to add a new user */
void add_user() {
    if(num_users >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    
    User new_user;
    printf("Enter a new username: ");
    scanf("%s", new_user.username);
    
    for(int i = 0; i < num_users; i++) {
        if(strcmp(users[i].username, new_user.username) == 0) {
            printf("Username already exists.\n");
            return;
        }
    }
    
    printf("Enter a new password: ");
    scanf("%s", new_user.password);
    strcpy(users[num_users++].username, new_user.username);
    strcpy(users[num_users - 1].password, new_user.password);
    printf("User added successfully.\n");
}

/* Function to change a user's password */
void change_password() {
    char username[MAX_PASSWORD_LENGTH];
    printf("Enter username of the user who's password you want to change: ");
    scanf("%s", username);
    
    for(int i = 0; i < num_users; i++) {
        if(strcmp(users[i].username, username) == 0) {
            printf("Enter a new password: ");
            scanf("%s", users[i].password);
            printf("Password changed successfully.\n");
            return;
        }
    }
    
    printf("User not found.\n");
}

/* Function to delete a user */
void delete_user() {
    char username[MAX_PASSWORD_LENGTH];
    printf("Enter username of the user you want to delete: ");
    scanf("%s", username);
    
    for(int i = 0; i < num_users; i++) {
        if(strcmp(users[i].username, username) == 0) {
            for(int j = i; j < num_users - 1; j++) {
                strcpy(users[j].username, users[j+1].username);
                strcpy(users[j].password, users[j+1].password);
            }
            num_users--;
            printf("User deleted successfully.\n");
            return;
        }
    }
    
    printf("User not found.\n");
}

int main() {
    int choice;
    
    printf("Welcome to Password Manager!\n");
    
    while(1) {
        printf("\nThe available options are:\n");
        printf("1. Print all users\n");
        printf("2. Add a new user\n");
        printf("3. Change a user's password\n");
        printf("4. Delete a user\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: print_users(); break;
            case 2: add_user(); break;
            case 3: change_password(); break;
            case 4: delete_user(); break;
            case 5: printf("Thank you for using Password Manager!\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}