//FormAI DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare function for executing system commands
void executeCommand(char* command) {
    char buffer[512];
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        printf("Error executing command!\n");
        exit(1);
    }
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        printf("%s", buffer);
    }
    pclose(pipe);
}

// Declare function for displaying menu and accepting user input
void displayMenu() {
    printf("\nPlease choose an option:");
    printf("\n1. Display system information");
    printf("\n2. Display disk space information");
    printf("\n3. Display memory usage information");
    printf("\n4. Display network information");
    printf("\n5. Exit program");
    printf("\nEnter your choice: ");
}

// Main function
int main() {
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                executeCommand("uname -a");
                break;
            case 2:
                executeCommand("df -h");
                break;
            case 3:
                executeCommand("free -m");
                break;
            case 4:
                executeCommand("ifconfig");
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose again.\n");
                break;
        }
    }
    return 0;
}