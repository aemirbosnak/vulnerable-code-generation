//FormAI DATASET v1.0 Category: System administration ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    char command[100];
    int choice;
    while(1){
        printf("\nWelcome to the System Administration program!\n\n");
        printf("Select an option:\n");
        printf("1. Check System Information\n");
        printf("2. Check Disk Space\n");
        printf("3. Check Memory Usage\n");
        printf("4. Check Running Processes\n");
        printf("5. Exit the Program\n");

        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("System Information:\n");
                //Execute the 'uname' command to get basic system information
                system("uname -a");
                break;
            case 2:
                printf("Disk Space:\n");
                //Execute the 'df' command to check the disk space
                system("df -h");
                break;
            case 3:
                printf("Memory Usage:\n");
                //Execute the 'free' command to check the memory usage
                system("free -m");
                break;
            case 4:
                printf("Running Processes:\n");
                //Execute the 'top' command to check the running processes
                system("top -b -n 1");
                break;
            case 5:
                printf("Exiting the Program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice (1-5).\n");
                break;
        }
    }
    return 0;
}