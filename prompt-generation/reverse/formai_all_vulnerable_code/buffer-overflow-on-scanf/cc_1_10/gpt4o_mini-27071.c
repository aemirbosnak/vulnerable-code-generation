//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu() {
    printf("\nSystem Administration Tool\n");
    printf("1. Display System Information\n");
    printf("2. Check Disk Space\n");
    printf("3. List Running Processes\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void display_system_info() {
    printf("\n--- System Information ---\n");
    system("uname -a");
}

void check_disk_space() {
    printf("\n--- Disk Space Usage ---\n");
    system("df -h");
}

void list_running_processes() {
    printf("\n--- Running Processes ---\n");
    system("ps aux");
}

int main() {
    int choice;
    
    while(1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }

        switch(choice) {
            case 1:
                display_system_info();
                break;
            case 2:
                check_disk_space();
                break;
            case 3:
                list_running_processes();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}