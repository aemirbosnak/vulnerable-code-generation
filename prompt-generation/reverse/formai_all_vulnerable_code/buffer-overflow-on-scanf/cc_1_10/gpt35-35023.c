//FormAI DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char cmd[100];

    printf("Welcome to System Administration Program\n\n");

    do {
        printf("Please select an option:\n\n");
        printf("1 - List all users\n");
        printf("2 - Add a new user\n");
        printf("3 - Remove a user\n");
        printf("4 - List all processes\n");
        printf("5 - Kill a process\n");
        printf("6 - Exit program\n\n");

        printf("==> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                system("getent passwd | cut -d: -f1");
                break;
            case 2:
                printf("Enter the name of the new user: ");
                scanf("%s", cmd);
                sprintf(cmd, "sudo adduser %s", cmd);
                system(cmd);
                break;
            case 3:
                printf("Enter the name of the user to remove: ");
                scanf("%s", cmd);
                sprintf(cmd, "sudo deluser %s", cmd);
                system(cmd);
                break;
            case 4:
                system("ps aux");
                break;
            case 5:
                printf("Enter the PID of the process to kill: ");
                scanf("%s", cmd);
                sprintf(cmd, "sudo kill %s", cmd);
                system(cmd);
                break;
            case 6:
                printf("Exiting the program...");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

        printf("\n");

    } while(choice != 6);

    return 0;
}