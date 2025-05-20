//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int choice;
    char username[20], password[20];
    char filename[50], command[100];

    printf("Welcome to the Grateful System Administration!\n");
    printf("Please enter your username: ");
    scanf("%s", username);

    printf("Please enter your password: ");
    scanf("%s", password);

    // Verify username and password
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        printf("Welcome, %s! You have successfully logged in.\n", username);
        printf("What would you like to do?\n");
        printf("1. Create a new file\n");
        printf("2. Edit an existing file\n");
        printf("3. Delete a file\n");
        printf("4. View current directory contents\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the filename you want to create: ");
                scanf("%s", filename);
                sprintf(command, "touch %s", filename);
                system(command);
                printf("File created successfully!\n");
                break;

            case 2:
                printf("Enter the filename you want to edit: ");
                scanf("%s", filename);
                sprintf(command, "vim %s", filename);
                system(command);
                printf("File edited successfully!\n");
                break;

            case 3:
                printf("Enter the filename you want to delete: ");
                scanf("%s", filename);
                sprintf(command, "rm %s", filename);
                system(command);
                printf("File deleted successfully!\n");
                break;

            case 4:
                system("ls -alh");
                break;

            case 5:
                printf("Goodbye, %s! Thanks for using Grateful System Administration.\n", username);
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } else {
        printf("Invalid username or password. Please try again.\n");
    }

    return 0;
}