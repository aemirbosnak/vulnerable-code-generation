//FormAI DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

// Welcome message
printf("Welcome to the System Administration example program\n\n");  

// Variable declaration
char command[100];
char dir[100];
char user[100];
char password[100];
int choice;

// Loop for user input
do {
    printf("--------------------------------------------------\n");
    printf("Please select an option\n");
    printf("1. Display current working directory\n");
    printf("2. Create a new directory\n");
    printf("3. Change current working directory\n");
    printf("4. Add a new user\n");
    printf("5. Change user password\n");
    printf("6. Exit the program\n");
    printf("--------------------------------------------------\n");

    // User choice input
    printf("Enter choice: ");
    scanf("%d", &choice);

    // Switch statement for user choice
    switch(choice) {
        case 1: // Display current working directory
            printf("\nCurrent working directory: ");
            system("pwd"); // pwd command
            printf("\n");
            break;

        case 2: // Create a new directory
            printf("\nEnter directory name: ");
            scanf("%s", dir);
            sprintf(command, "mkdir %s", dir); // mkdir command
            system(command);
            printf("\nDirectory '%s' created successfully!\n", dir);
            break;

        case 3: // Change current working directory
            printf("\nEnter directory path: ");
            scanf("%s", dir);
            sprintf(command, "cd %s", dir); // cd command
            system(command);
            printf("\nChanged to directory '%s'\n", dir);
            break;

        case 4: // Add a new user
            printf("\nEnter new username: ");
            scanf("%s", user);
            sprintf(command, "useradd %s", user); // useradd command
            system(command);
            printf("\nUser '%s' added successfully!\n", user);
            break;

        case 5: // Change user password
            printf("\nEnter username: ");
            scanf("%s", user);
            printf("Enter new password: ");
            scanf("%s", password);
            sprintf(command, "echo %s:%s | chpasswd", user, password); // chpasswd command
            system(command);
            printf("\nPassword for user '%s' changed successfully!\n", user);
            break;

        case 6: // Exit program
            printf("\nExiting program...\n");
            break;

        default: // Invalid input
            printf("\nInvalid input. Please try again.\n");
            break;
    }

} while(choice != 6); // Loop until user chooses to exit

return 0; // Return statement
}