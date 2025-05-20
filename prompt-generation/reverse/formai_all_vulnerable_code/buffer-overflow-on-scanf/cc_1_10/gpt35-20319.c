//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printMainMenu() {
    printf("Welcome to Imaginative System Administration Program\n");
    printf("Please select an option:\n");
    printf("1. Shutdown the System\n");
    printf("2. Restart the System\n");
    printf("3. View System Information\n");
    printf("4. Manage Users\n");
    printf("5. Exit Program\n");
}

void shutdownSystem() {
    printf("Are you sure you want to shutdown the system? (Y/N)\n");
    char answer[10];
    scanf("%s", answer);
    if (strcmp(answer, "Y") == 0 || strcmp(answer, "y") == 0) {
        printf("Shutting down the system...\n");
        sleep(3); // sleep for 3 seconds to simulate shutdown
        system("shutdown now"); // execute shutdown command
    } else {
        printf("System shutdown cancelled.\n");
    }
}

void restartSystem() {
    printf("Are you sure you want to restart the system? (Y/N)\n");
    char answer[10];
    scanf("%s", answer);
    if (strcmp(answer, "Y") == 0 || strcmp(answer, "y") == 0) {
        printf("Restarting the system...\n");
        sleep(3); // sleep for 3 seconds to simulate restart
        system("reboot"); // execute reboot command
    } else {
        printf("System restart cancelled.\n");
    }
}

void viewSystemInfo() {
    printf("Showing System Information...\n");
    system("uname -a"); // execute uname command to show system information
}

void manageUsers() {
    printf("Welcome to User Management System\n");
    printf("Please select an option:\n");
    printf("1. Add a New User\n");
    printf("2. Delete an Existing User\n");
    int option;
    scanf("%d", &option);
    if (option == 1) {
        printf("Enter the name of the new user:\n");
        char username[50];
        scanf("%s", username);
        char addUserCommand[100];
        sprintf(addUserCommand, "useradd %s", username); // construct addUser command and execute
        system(addUserCommand);
        printf("User '%s' added successfully.\n", username);
    } else if (option == 2) {
        printf("Enter the name of the user you want to delete:\n");
        char username[50];
        scanf("%s", username);
        char deleteUserCommand[100];
        sprintf(deleteUserCommand, "userdel -f %s", username); // construct deleteUser command and execute
        system(deleteUserCommand);
        printf("User '%s' deleted successfully.\n", username);
    } else {
        printf("Invalid Option Selected.\n");
    }
}

int main() {
    int option;
    do {
        printMainMenu(); // print main menu options
        scanf("%d", &option);
        switch(option) {
            case 1: {
                shutdownSystem(); // call shutdownSystem function
                break;
            }
            case 2: {
                restartSystem(); // call restartSystem function
                break;
            }
            case 3: {
                viewSystemInfo(); // call viewSystemInfo function
                break;
            }
            case 4: {
                manageUsers(); // call manageUsers function
                break;
            }
            case 5: {
                printf("Exiting the program...\n");
                exit(0); // exit the program
            }
            default: {
                printf("Invalid Option Selected.\n");
                break;
            }
        }
    } while (option != 5);
    return 0;
}