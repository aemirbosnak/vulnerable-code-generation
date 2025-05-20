//FormAI DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void add_user();
void delete_user();
void change_password();
void view_users();

int main() {
    int option;

    while(1) {
        printf("Welcome to the User Management System\n");
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. Change Password\n");
        printf("4. View Users\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d",&option);

        switch(option) {
            case 1:
                add_user();
                break;
            case 2:
                delete_user();
                break;
            case 3:
                change_password();
                break;
            case 4:
                view_users();
                break;
            case 5:
                printf("Exiting User Management System\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

// function to add a new user
void add_user() {
    char username[20];
    char password[20];

    printf("Enter a username: ");
    scanf("%s",username);

    printf("Enter a password: ");
    scanf("%s",password);

    printf("User %s added successfully!\n",username);
}

// function to delete a user
void delete_user() {
    char username[20];

    printf("Enter the username to delete: ");
    scanf("%s",username);

    printf("User %s deleted successfully!\n",username);
}

// function to change password
void change_password() {
    char username[20];
    char old_password[20];
    char new_password[20];

    printf("Enter your username: ");
    scanf("%s",username);

    printf("Enter your old password: ");
    scanf("%s",old_password);

    printf("Enter your new password: ");
    scanf("%s",new_password);

    printf("Password changed successfully!\n");
}

// function to view all users
void view_users() {
    printf("List of all users:\n");
    printf("User 1\n");
    printf("User 2\n");
    printf("User 3\n");
    printf("User 4\n");
    printf("User 5\n");
}