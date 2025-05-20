//FormAI DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Declare variables
    char command[100];
    int userChoice;
    int flag = 1;

    while (flag) {
        // Prompt user for choice
        printf("Enter a choice:\n");
        printf("1. View current CPU usage\n");
        printf("2. View disk usage\n");
        printf("3. View memory usage\n");
        printf("4. Exit\n");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                // Use top command to view current CPU usage
                system("top -b -n 1 | awk '/^%Cpu/{print $2}'");

                break;

            case 2:
                // Use df command to view disk usage
                system("df -h");

                break;

            case 3:
                // Use free command to view memory usage
                system("free -h");

                break;

            case 4:
                flag = 0;
                printf("Exiting program...\n");

                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
        // Clear buffer
        while ((getchar()) != '\n');
    }
    return 0;
}