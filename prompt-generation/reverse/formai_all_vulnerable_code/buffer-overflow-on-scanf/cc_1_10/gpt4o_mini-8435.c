//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu() {
    printf("System Administration Tool\n");
    printf("1. Display System Information\n");
    printf("2. List Running Processes\n");
    printf("3. Check Disk Usage\n");
    printf("4. Get Memory Usage\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

void system_info() {
    printf("\nDisplaying system information...\n");
    system("uname -a");
}

void list_processes() {
    printf("\nListing running processes...\n");
    system("ps -aux");
}

void check_disk_usage() {
    printf("\nChecking disk usage...\n");
    system("df -h");
}

void get_memory_usage() {
    printf("\nGetting memory usage...\n");
    system("free -h");
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system_info();
                break;
            case 2:
                list_processes();
                break;
            case 3:
                check_disk_usage();
                break;
            case 4:
                get_memory_usage();
                break;
            case 5:
                printf("Exiting the tool. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }

        printf("\nPress Enter to continue...");
        while ((getchar()) != '\n');  // Clear the newline character left by scanf
        getchar();  // Wait for the user to press Enter
        printf("\n");
    }

    return 0;
}