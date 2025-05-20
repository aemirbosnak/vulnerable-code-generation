//FormAI DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearConsole() {
    // This function clears the console
    system("clear");
}

void displayBanner() {
    // This function displays a happy banner
    printf("\n");
    printf(" _______  _______  _______  _______    _______           _______    \n");
    printf("(       )(       )(  ____ \\(  ____ \\  (  ___  )|\\     /|(       )  \n");
    printf("| () () || () () || (    \\/| (    \\/  | (   ) || )   ( || () () |  \n");
    printf("| || || || || || || (__    | |        | |   | || |   | || || || |  \n");   
    printf("| |(_)| || |(_)| ||  __)   | |        | |   | || |   | || |(_)| |  \n");   
    printf("| |   | || |   | || (      | |        | |   | | \\   / / | |   | |  \n");   
    printf("| )   ( || )   ( || (____/\\| (____/\\  | (___) |  \\_/ /  | )   ( |  \n");
    printf("|/     \\||/     \\|(_______/(_______/  (_______)  \\_/   |/     \\|  \n");
    printf("\n");                                                                                                                                                                                                            
}

void printOptionList() {
    // This function prints the option list
    printf("\nAvailable Options:\n\n");
    printf("1. Check System Usage\n");
    printf("2. Create a New User\n");
    printf("3. Install a Package\n");
    printf("4. Restart Services\n");
    printf("5. Exit\n\n");
}

int main() {
    int option;
    char username[30], password[30];
    
    clearConsole();
    
    displayBanner();
    
    printf("Welcome to the Happy System Administration Program!\n");
    
    while (1) {
        printOptionList();
        
        printf("Please enter an option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                clearConsole();
                printf("Checking system usage...\n");
                // Some code to check system usage goes here
                printf("System usage checked successfully! :)\n");
                break;

            case 2:
                clearConsole();
                printf("Creating a new user...\n");
                printf("Please enter a username: ");
                scanf("%s", username);
                printf("Please enter a password: ");
                scanf("%s", password);
                // Some code to create a new user goes here
                printf("User %s created successfully! :)\n", username);
                break;

            case 3:
                clearConsole();
                printf("Installing a package...\n");
                // Some code to install a package goes here
                printf("Package installed successfully! :)\n");
                break;

            case 4:
                clearConsole();
                printf("Restarting services...\n");
                // Some code to restart services goes here
                printf("Services restarted successfully! :)\n");
                break;

            case 5:
                clearConsole();
                printf("Thank you for using our Happy System Administration Program! :)\n");
                exit(0);
            
            default:
                clearConsole();
                printf("Invalid option selected! Please try again.\n");
                break;
        }
    }
    
    return 0;
}