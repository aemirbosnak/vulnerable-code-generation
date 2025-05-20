//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Welcome to the System Admin Example Program!\n");
    printf("This program will help you manage your system.\n");
    printf("What would you like to do today?\n");
    
    while (1) {
        int choice;
        printf("1. View system information\n");
        printf("2. Manage users\n");
        printf("3. Manage files and directories\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("lsb_release -a");
                system("uname -a");
                system("df -h");
                break;
                
            case 2:
                printf("Enter username to add: ");
                char username[30];
                scanf("%s", username);
                printf("Adding user %s...\n", username);
                char command[50];
                sprintf(command, "useradd %s", username);
                system(command);
                printf("User %s added successfully.\n", username);
                break;
                
            case 3:
                printf("Enter path of directory to create: ");
                char path[50];
                scanf("%s", path);
                printf("Creating directory %s...\n", path);
                char mkdir_command[50];
                sprintf(mkdir_command, "mkdir %s", path);
                system(mkdir_command);
                printf("Directory %s created successfully.\n", path);
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);
                break;
                
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}