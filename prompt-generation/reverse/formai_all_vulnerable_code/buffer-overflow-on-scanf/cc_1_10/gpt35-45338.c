//FormAI DATASET v1.0 Category: System administration ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Welcome to my unique program! This program is an artistic representation of system administration.\n\n");

    int choice = 0;
    int sysload = 0;
    int memusage = 0;

    // Main menu
    while(choice != -1){

        printf("========== SYSTEM ADMINISTRATION MENU ==========\n");
        printf("1. Check system load\n");
        printf("2. Check memory usage\n");
        printf("3. Monitor network activity\n");
        printf("4. Check disk space\n");
        printf("5. Kill a process\n");
        printf("6. Logout\n");

        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice){

            // Check system load
            case 1:
                printf("Checking system load...\n");
                sysload = rand() % 101;
                printf("System load: %d%%\n", sysload);
                break;

            // Check memory usage
            case 2:
                printf("Checking memory usage...\n");
                memusage = rand() % 101;
                printf("Memory usage: %d%%\n", memusage);
                break;

            // Monitor network activity
            case 3:
                printf("Monitoring network activity...\n");
                printf("Sorry, this feature is not available in this artistic representation of system administration.\n");
                break;

            // Check disk space
            case 4:
                printf("Checking disk space...\n");
                printf("Sorry, this feature is not available in this artistic representation of system administration.\n");
                break;

            // Kill a process
            case 5:
                printf("Killing a process...\n");
                printf("Sorry, this feature is not available in this artistic representation of system administration.\n");
                break;

            // Logout
            case 6:
                printf("Logging out...\n");
                choice = -1; // Exits the loop
                break;

            // Invalid choice
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }

        printf("\n");

    } // End of main loop

    printf("Thank you for using my unique program! Goodbye.\n");

    return 0;
}