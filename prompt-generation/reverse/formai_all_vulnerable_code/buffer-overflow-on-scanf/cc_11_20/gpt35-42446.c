//FormAI DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char** argv) {

    // Check if running as root user
    if(getuid() != 0) {
        printf("Error: This program must be run as a root user!\n");
        exit(1);
    }

    printf("Welcome to Curious SysAdmin program!\n");
    printf("What would you like to do?\n");
    printf("1. Add a new user\n");
    printf("2. Delete an existing user\n");
    printf("3. Change a user's password\n");
    printf("4. Modify user permissions\n");
    printf("5. Show current users\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1: 
            printf("Enter new username: ");
            char username[50];
            scanf("%s", username);

            int status = system(strcat("adduser ", username));
            if(status != 0) {
                printf("Error: Failed to add new user!\n");
                exit(1);
            }
            printf("New user '%s' has been added successfully!\n", username);
            break;

        case 2:
            printf("Enter name of user to delete: ");
            char user_to_delete[50];
            scanf("%s", user_to_delete);

            status = system(strcat("deluser ", user_to_delete));
            if(status != 0) {
                printf("Error: Failed to delete user!\n");
                exit(1);
            }
            printf("User '%s' has been deleted successfully!\n", user_to_delete);
            break;

        case 3:
            printf("Enter username for which you want to change the password: ");
            char user_for_password[50];
            scanf("%s", user_for_password);

            status = system(strcat("passwd ", user_for_password));
            if(status != 0) {
                printf("Error: Failed to change password!\n");
                exit(1);
            }
            printf("Password for user '%s' has been changed successfully!\n", user_for_password);
            break;

        case 4:
            printf("Enter username for which you want to modify permissions: ");
            char user_for_permissions[50];
            scanf("%s", user_for_permissions);

            printf("Enter permissions in numeric form (e.g. 744): ");
            char permissions[5];
            scanf("%s", permissions);

            char command[100] = "chmod ";
            strcat(command, permissions);
            strcat(command, " ");
            strcat(command, user_for_permissions);

            status = system(command);
            if(status != 0) {
                printf("Error: Failed to modify permissions!\n");
                exit(1);
            }
            printf("Permissions for user '%s' have been modified successfully!\n", user_for_permissions);
            break;

        case 5:
            printf("Current users:\n");
            system("cut -d: -f1 /etc/passwd");
            break;

        default:
            printf("Error: Invalid choice!\n");
            exit(1);
    }

    return 0;
}