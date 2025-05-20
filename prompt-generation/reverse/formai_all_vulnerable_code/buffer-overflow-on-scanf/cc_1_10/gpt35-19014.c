//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    
    int choice;
    
    do {
        printf("---------------\n");
        printf("Welcome to System Administration\n");
        printf("---------------\n");
        printf("1. Check system uptime\n");
        printf("2. Shutdown system\n");
        printf("3. Restart system\n");
        printf("4. Get system information\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                system("uptime");
                break;
                
            case 2:
                system("shutdown -P now");
                break;
                
            case 3:
                system("reboot");
                break;
                
            case 4:
                system("uname -a");
                break;
                
            case 5:
                printf("Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        
        sleep(1); // Wait for 1 second before clearing the screen
        system("clear"); // Clear the screen

    } while (choice != 5);

    return 0;
}