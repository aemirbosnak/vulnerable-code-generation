//FormAI DATASET v1.0 Category: System administration ; Style: Donald Knuth
/* 
   This C program demonstrates a system administration tool that interacts with the user via a command-line interface,
   and allows the user to perform basic system administration functions.
    
   Written by: [Your Name Here]
   Date: [Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 100 // Maximum command length

/* Function to print the menu */
void print_menu()
{
    printf("\nSystem Administration Tool\n");
    printf("---------------------------\n");
    printf("1. List all users\n");
    printf("2. List running processes\n");
    printf("3. Kill a process\n");
    printf("4. Reboot the system\n");
    printf("5. Shut down the system\n");
    printf("6. Exit\n");
}

/* Function to list all users */
void list_users()
{
    system("cat /etc/passwd | awk -F: '{ print $1 }'");
}

/* Function to list running processes */
void list_processes()
{
    system("ps aux");
}

/* Function to kill a process */
void kill_process()
{
    char cmd[MAX_CMD_LENGTH];
    int pid;
    
    printf("Enter the PID of the process to kill: ");
    scanf("%d", &pid);
    
    sprintf(cmd, "kill %d", pid);
    system(cmd);
}

/* Function to reboot the system */
void reboot_system()
{
    printf("Rebooting the system...\n");
    sleep(2);
    system("reboot");
}

/* Function to shut down the system */
void shutdown_system()
{
    printf("Shutting down the system...\n");
    sleep(2);
    system("shutdown now");
}

/* Main function */
int main()
{
    int option;
    
    while(1)
    {
        print_menu();
        
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1: // List all users
                list_users();
                break;
                
            case 2: // List running processes
                list_processes();
                break;
                
            case 3: // Kill a process
                kill_process();
                break;
                
            case 4: // Reboot the system
                reboot_system();
                break;
                
            case 5: // Shut down the system
                shutdown_system();
                break;
                
            case 6: // Exit
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("\nInvalid choice!\n");
                break;
        }
        
        // Wait for the user to press enter before clearing the screen
        getchar();
        printf("\nPress Enter to continue...\n");
        getchar();
        
        // Clear the screen
        system("clear");
    }
    
    return 0;
}