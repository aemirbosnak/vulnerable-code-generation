//FormAI DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    // Welcome message
    printf("Welcome to the System Administration example program.\n");

    // User input for system configuration option
    int option;
    printf("Please select an option:\n");
    printf("1. Check system status\n");
    printf("2. Perform system update\n");
    printf("3. Create new user\n");
    scanf("%d", &option);

    // Check system status
    if(option == 1) {
        system("uname -a");
        system("uptime");
        system("free -h");
        system("df -h");
        printf("System status check complete.\n");
    }

    // Perform system update
    else if(option == 2) {
        printf("Starting system update...\n");
        system("sudo apt-get update");
        system("sudo apt-get upgrade");
        printf("System update complete.\n");
    }

    // Create new user
    else if(option == 3) {
        printf("Please enter the new user's username: \n");
        char username[20];
        scanf("%s", username);
        printf("Please enter the new user's password: \n");
        char password[20];
        scanf("%s", password);
        char command[50];
        sprintf(command, "sudo useradd -m -p %s %s", password, username);
        system(command);
        printf("New user %s created successfully.\n", username);
    }

    // Invalid option selected
    else {
        printf("Invalid option selected. Please try again.\n");
    }

    // Goodbye message
    printf("Thank you for using the System Administration example program.\n");
    return 0;
}