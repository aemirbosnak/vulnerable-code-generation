//FormAI DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to change the system timezone
void changeTimezone(char *timezone) {
    char command[100];
    // Creating the command to set the timezone
    sprintf(command, "timedatectl set-timezone %s", timezone);
    // Running the command
    system(command);
    printf("System timezone changed to %s\n", timezone);
}

// Function to check system resources usage
void checkResources() {
    char command[50];
    // Creating the command to get the system resources usage
    sprintf(command, "free -m");
    // Running the command
    system(command);
}

// Function to check disk usage
void checkDiskUsage() {
    char command[50];
    // Creating the command to get the disk usage
    sprintf(command, "df -H");
    // Running the command
    system(command);
}

// Function to get system information
void getSystemInfo() {
    char command[50];
    // Creating the command to get the system information
    sprintf(command, "uname -a");
    // Running the command
    system(command);
}

int main() {
    // Printing main menu
    printf("===================================\n");
    printf("          System Administration     \n");
    printf("===================================\n");
    printf("1. Change timezone\n");
    printf("2. Check resources usage\n");
    printf("3. Check disk usage\n");
    printf("4. Get system information\n");

    int choice = 0;

    while(choice < 1 || choice > 4) {
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
    }

    switch(choice) {
        case 1:
            printf("Enter the new timezone: ");
            char timezone[30];
            scanf(" %[^\n]s", timezone);
            changeTimezone(timezone);
            break;
        case 2:
            checkResources();
            break;
        case 3:
            checkDiskUsage();
            break;
        case 4:
            getSystemInfo();
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}