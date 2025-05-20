//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

void display_menu(void);

void manage_users(void);

void add_user(void);

void remove_user(void);

int main()
{
    display_menu();

    return 0;
}

void display_menu(void)
{
    int choice;

    do {
        printf("\nWelcome to the user management program\n");
        printf("Please select an option from the menu below\n");
        printf("1. Manage users\n");
        printf("2. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                manage_users();
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    } while (choice != 2);
}

void manage_users(void)
{
    int choice;

    do {
        printf("\nManage users\n");
        printf("Please select an option from the menu below\n");
        printf("1. Add user\n");
        printf("2. Remove user\n");
        printf("3. Back to main menu\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                remove_user();
                break;
            case 3:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    } while (choice != 3);
}

void add_user(void)
{
    char username[BUF_SIZE];

    printf("Please enter a username for the new user: ");
    scanf("%s", username);

    char command[BUF_SIZE];
    sprintf(command, "useradd %s", username);

    int status = system(command);

    if (status == -1) {
        printf("Failed to add new user - system call failed\n");
    } else {
        printf("New user added successfully!\n");
    }
}

void remove_user(void)
{
    char username[BUF_SIZE];

    printf("Please enter the username of the user to be removed: ");
    scanf("%s", username);

    char command[BUF_SIZE];
    sprintf(command, "userdel %s", username);

    int status = system(command);

    if (status == -1) {
        printf("Failed to remove user - system call failed\n");
    } else {
        printf("User removed successfully!\n");
    }
}