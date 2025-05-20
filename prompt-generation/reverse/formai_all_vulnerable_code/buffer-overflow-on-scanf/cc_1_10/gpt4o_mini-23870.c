//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void displayWelcomeMessage() {
    printf("********************************\n");
    printf("*     🎉 Welcome to My System   *\n");
    printf("*       Administration Tool      *\n");
    printf("********************************\n");
}

void displayMainMenu() {
    printf("\nMain Menu:\n");
    printf("1. Add a New User\n");
    printf("2. Delete a User\n");
    printf("3. Display System Information\n");
    printf("4. Exit\n");
    printf("Please choose an option (1-4): ");
}

void addUser() {
    char username[50];
    printf("Enter a new username: ");
    scanf("%s", username);

    char command[100];
    snprintf(command, sizeof(command), "sudo useradd %s", username);
    system(command);
    printf("🎉 User '%s' has been added successfully!\n", username);
}

void deleteUser() {
    char username[50];
    printf("Enter the username to delete: ");
    scanf("%s", username);

    char command[100];
    snprintf(command, sizeof(command), "sudo userdel %s", username);
    system(command);
    printf("🚫 User '%s' has been deleted successfully!\n", username);
}

void displaySystemInfo() {
    printf("Here comes the juicy system info:\n");

    // Display uptime
    printf("\nUptime:\n");
    system("uptime");

    // Display disk usage
    printf("\nDisk Usage:\n");
    system("df -h");

    // Display memory usage
    printf("\nMemory Usage:\n");
    system("free -h");
}

int main() {
    int choice;

    displayWelcomeMessage();

    do {
        displayMainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                deleteUser();
                break;
            case 3:
                displaySystemInfo();
                break;
            case 4:
                printf("Exiting... Have a great day! 🌈\n");
                break;
            default:
                printf("🤔 Oops! Please choose a valid option (1-4).\n");
        }
    } while (choice != 4);

    return 0;
}