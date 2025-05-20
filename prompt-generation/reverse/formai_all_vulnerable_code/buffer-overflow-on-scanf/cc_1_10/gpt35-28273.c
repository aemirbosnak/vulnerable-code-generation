//FormAI DATASET v1.0 Category: System administration ; Style: careful
/*
 * This program is a simple system administration tool
 * that allows the user to add, remove or modify users
 * on a Unix or Linux system.
 *
 * Author: John Doe <johndoe@example.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void add_user()
{
    char username[50];
    printf("Enter username: ");
    scanf("%s", username);

    char password[50];
    printf("Enter password: ");
    scanf("%s", password);

    char command[100];
    sprintf(command, "sudo useradd -m -p %s %s", password, username);
    system(command);

    printf("User %s has been added.\n", username);
}

void remove_user()
{
    char username[50];
    printf("Enter username to remove: ");
    scanf("%s", username);

    char command[100];
    sprintf(command, "sudo userdel -r %s", username);
    system(command);

    printf("User %s has been removed.\n", username);
}

void modify_password()
{
    char username[50];
    printf("Enter username to modify password: ");
    scanf("%s", username);

    char password[50];
    printf("Enter new password: ");
    scanf("%s", password);

    char command[100];
    sprintf(command, "sudo passwd %s %s", username, password);
    system(command);

    printf("Password for user %s has been modified.\n", username);
}

int main()
{
    int choice;
    while (1) {
        printf("\n========= SYSTEM ADMIN MENU =========\n");
        printf("1. Add User\n");
        printf("2. Remove User\n");
        printf("3. Modify Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                remove_user();
                break;
            case 3:
                modify_password();
                break;
            case 4:
                printf("Exiting... Good bye...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}