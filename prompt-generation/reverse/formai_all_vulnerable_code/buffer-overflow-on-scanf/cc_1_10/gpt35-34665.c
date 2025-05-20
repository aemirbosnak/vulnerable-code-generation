//FormAI DATASET v1.0 Category: System administration ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function to check if the current user is root or not
int check_user_privilege() {
    if(geteuid() == 0) {
        return 1; // Root user
    }
    else {
        return 0; // Non-root user
    }
}

// Function to create a user with specified name and password
void create_user(char* username, char* password) {
    if(check_user_privilege()) {
        char command[100];
        sprintf(command, "useradd -m -p %s %s", password, username);
        system(command);
        printf("User %s created successfully!\n", username);
    }
    else {
        printf("Error: You do not have sufficient privileges to create a new user.\n");
    }
}

// Function to delete a user
void delete_user(char* username) {
    if(check_user_privilege()) {
        char command[100];
        sprintf(command, "userdel -r %s", username);
        system(command);
        printf("User %s deleted successfully!\n", username);
    }
    else {
        printf("Error: You do not have sufficient privileges to delete a user.\n");
    }
}

// Function to change the password of a user
void change_password(char* username, char* password) {
    if(check_user_privilege()) {
        char command[100];
        sprintf(command, "echo \"%s:%s\" | chpasswd", username, password);
        system(command);
        printf("Password for user %s changed successfully!\n", username);
    }
    else {
        printf("Error: You do not have sufficient privileges to change a user's password.\n");
    }
}

// Main function for the program
int main() {
    char option;
    char username[20], password[20];

    printf("Select an option:\n");
    printf("1. Create a new user\n");
    printf("2. Delete an existing user\n");
    printf("3. Change a user's password\n");
    printf("Enter your choice: ");
    scanf("%c", &option);

    switch(option) {
        case '1':
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            create_user(username, password);
            break;

        case '2':
            printf("Enter username: ");
            scanf("%s", username);
            delete_user(username);
            break;

        case '3':
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter new password: ");
            scanf("%s", password);
            change_password(username, password);
            break;

        default:
            printf("Invalid option selected!\n");
            break;
    }

    return 0;
}