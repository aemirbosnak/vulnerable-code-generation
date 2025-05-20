//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to execute a system command and display the output
void execute_command(const char *command) {
    FILE *fp;
    char buffer[256];

    // Open the command for reading
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return;
    }

    // Read the output a line at a time
    printf("Output of command (%s):\n", command);
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // Close the command stream
    pclose(fp);
}

// Function to display the main menu
void display_menu() {
    printf("\n=== System Administration Menu ===\n");
    printf("1. View system information\n");
    printf("2. Check disk usage\n");
    printf("3. Monitor memory usage\n");
    printf("4. List active processes\n");
    printf("5. Exit\n");
    printf("===================================\n");
    printf("Select an option (1-5): ");
}

// Main function
int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                execute_command("uname -a");
                break;
            case 2:
                execute_command("df -h");
                break;
            case 3:
                execute_command("free -h");
                break;
            case 4:
                execute_command("ps aux");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select between 1-5.\n");
        }
    } while (choice != 5);

    return 0;
}