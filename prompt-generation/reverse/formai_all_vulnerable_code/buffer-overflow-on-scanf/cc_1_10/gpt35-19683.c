//FormAI DATASET v1.0 Category: System administration ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// function to display system information
void displaySystemInfo() {
    printf("*********** System Information ***********\n");
    system("uname -a"); // displays the system information using "uname" command
    printf("***************************************\n\n");
}

// function to display the disk space utilization
void displayDiskSpaceUtilization() {
    printf("*********** Disk Space Utilization ***********\n");
    system("df -h"); // displays the disk space utilization using "df" command
    printf("********************************************\n\n");
}

// function to display the current logged in users
void displayCurrentLoggedInUsers() {
    printf("*********** Current Logged In Users ***********\n");
    system("who"); // displays the current logged in users using "who" command
    printf("*********************************************\n\n");
}

int main() {

    int choice;
    while(1) {
        printf("Please enter your choice:\n");
        printf("1. Display system information\n");
        printf("2. Display disk space utilization\n");
        printf("3. Display current logged in users\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displaySystemInfo();
                break;
            case 2:
                displayDiskSpaceUtilization();
                break;
            case 3:
                displayCurrentLoggedInUsers();
                break;
            case 4:
                printf("Thank you for using the system administration program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}