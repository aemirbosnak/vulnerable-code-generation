//FormAI DATASET v1.0 Category: System administration ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/utsname.h>

int main()
{
    struct utsname sys_info;
    int option;
    char username[20];
    char command[100];

    printf("Welcome to the System Administration program!\n\n");
    printf("Please enter your username: ");
    scanf("%s", username);

    while(1){
        printf("\nHi %s! What would you like to do?\n", username);
        printf("1. Display system information\n");
        printf("2. View files in current directory\n");
        printf("3. Create a new directory\n");
        printf("4. Change directory\n");
        printf("5. Execute a command\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &option);

        switch(option)
        {
            case 1:
                uname(&sys_info);
                printf("\nSystem Information\n");
                printf("Operating System: %s\n", sys_info.sysname);
                printf("Node Name: %s\n", sys_info.nodename);
                printf("Release Version: %s\n", sys_info.release);
                printf("Version: %s\n", sys_info.version);
                printf("Machine Architecture: %s\n\n", sys_info.machine);
                break;

            case 2:
                system("ls -l");
                break;

            case 3:
                printf("Enter directory name: ");
                scanf("%s", command);
                sprintf(command, "mkdir %s", command);
                system(command);
                break;

            case 4:
                printf("Enter directory name: ");
                scanf("%s", command);
                sprintf(command, "cd %s", command);
                system(command);
                break;

            case 5:
                printf("Enter command to execute: ");
                scanf("%s", command);
                system(command);
                break;

            case 6:
                printf("\nGoodbye %s! Thank you for using the System Administration program.\n\n", username);
                exit(0);

            default:
                printf("\nError: Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}