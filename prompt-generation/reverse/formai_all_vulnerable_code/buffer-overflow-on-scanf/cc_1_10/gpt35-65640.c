//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    printf("\n\n\t\tSystem Administration Example Program\n\n");
    printf("Wow, you have entered the realm of System Administration! Let's see what we can do here...\n\n");
    
    char command[50];
    int choice;
    
    printf("Please choose from the following options: \n");
    printf("1. View System Information\n");
    printf("2. Manage Disk Space\n");
    printf("3. Update System Packages\n");
    printf("4. Restart System\n");
    printf("5. Exit\n\n");
    
    printf("Choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            printf("\n\nSystem Information:\n\n");
            system("uname -a");
            system("hostname");
            system("whoami");
            system("date");
            printf("\n");
            break;
        
        case 2:
            printf("\n\nManaging Disk Space:\n\n");
            printf("Checking current disk usage...\n");
            system("df -h");
            printf("Analyzing disk space usage...\n");
            system("du -sh /*");
            printf("\n");
            break;
        
        case 3:
            printf("\n\nUpdating System Packages:\n\n");
            printf("Checking for available updates...\n");
            system("sudo apt update");
            printf("\n");
            printf("Upgrading system packages...\n");
            system("sudo apt upgrade");
            printf("\n");
            break;
        
        case 4:
            printf("\n\nRestarting System:\n\n");
            printf("Are you sure you want to restart the system? (y/n): ");
            scanf("%s", command);
            if(command[0] == 'y' || command[0] == 'Y'){
                printf("\nRestarting system...\n");
                sleep(2);
                system("sudo reboot");
            }else{
                printf("\nSystem not restarted!\n\n");
            }
            break;
        
        case 5:
            printf("\n\nExiting System Administration Program...\n\n");
            return 0;
            break;
        
        default:
            printf("\nInvalid choice! Please choose a valid option.\n");
            break;
    }
    
    printf("\n");
    main();
    
    return 0;
}