//FormAI DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program will manage user accounts on a Linux system */

typedef struct {
    char username[20];
    char password[20];
    char home_dir[50];
} User;

void create_user(User user) {
    char command[150];
    sprintf(command, "sudo useradd -m -d %s -p %s %s", user.home_dir, user.password, user.username);
    system(command);
}

void delete_user(User user) {
    char command[150];
    sprintf(command, "sudo userdel -r %s", user.username);
    system(command);
}

void change_password(User user, char new_password[20]) {
    char command[100];
    sprintf(command, "sudo passwd %s %s", user.username, new_password);
    system(command);
}

void display_menu() {
    printf("\n");
    printf("======== User Account Manager =======\n");
    printf("1. Create User Account\n");
    printf("2. Delete User Account\n");
    printf("3. Change Password\n");
    printf("4. Exit\n");
    printf("=====================================\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    char new_password[20];
    User user;

    printf("Welcome to the User Account Manager!\n");

    while(1) {
        display_menu();

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", user.username);

                printf("Enter password: ");
                scanf("%s", user.password);

                printf("Enter home directory: ");
                scanf("%s", user.home_dir);

                create_user(user);

                printf("User account created successfully!\n");
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", user.username);

                delete_user(user);

                printf("User account deleted successfully!\n");
                break;

            case 3:
                printf("Enter username: ");
                scanf("%s", user.username);

                printf("Enter new password: ");
                scanf("%s", new_password);

                change_password(user, new_password);

                printf("Password changed successfully!\n");
                break;

            case 4:
                printf("Thanks for using the User Account Manager!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}