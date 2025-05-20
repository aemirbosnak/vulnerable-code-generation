//FormAI DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int choice;
    printf("Welcome to System Administration Helper!\n");
    while(1) {
        printf("\nWhat action would you like to perform?\n");
        printf("1. Create a new user\n");
        printf("2. Delete an existing user\n");
        printf("3. Add a user to a group\n");
        printf("4. Remove a user from a group\n");
        printf("5. Change a user's password\n");
        printf("6. Force a password change on next login\n");
        printf("7. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the username you wish to create: ");
                char create_user[50];
                scanf("%s", create_user);
                char* args[] = {"adduser", create_user, NULL};
                execvp("adduser", args);
                break;
            case 2:
                printf("Enter the username you wish to delete: ");
                char del_user[50];
                scanf("%s", del_user);
                char* del_args[] = {"userdel", del_user, NULL};
                execvp("userdel", del_args);
                break;
            case 3:
                printf("Enter the username you wish to add to a group: ");
                char add_user[50];
                scanf("%s", add_user);
                printf("Enter the name of the group: ");
                char add_group[50];
                scanf("%s", add_group);
                char* add_args[] = {"usermod", "-a", "-G", add_group, add_user, NULL};
                execvp("usermod", add_args);
                break;
            case 4:
                printf("Enter the username you wish to remove from a group: ");
                char rem_user[50];
                scanf("%s", rem_user);
                printf("Enter the name of the group: ");
                char rem_group[50];
                scanf("%s", rem_group);
                char* rem_args[] = {"gpasswd", "-d", rem_user, rem_group, NULL};
                execvp("gpasswd", rem_args);
                break;
            case 5:
                printf("Enter the username you wish to change the password for: ");
                char pass_user[50];
                scanf("%s", pass_user);
                char* pass_args[] = {"passwd", pass_user, NULL};
                execvp("passwd", pass_args);
                break;
            case 6:
                printf("Enter the username you wish to force a password change for: ");
                char force_user[50];
                scanf("%s", force_user);
                char* force_args[] = {"chage", "-d", "0", force_user, NULL};
                execvp("chage", force_args);
                break;
            case 7:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}