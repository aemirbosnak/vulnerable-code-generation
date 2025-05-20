//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu() {
    printf("\n--- Simple System Administration Tool ---\n");
    printf("1. Display System Information\n");
    printf("2. Check Disk Usage\n");
    printf("3. Show Current Users\n");
    printf("4. Monitor System Load\n");
    printf("5. Exit\n");
    printf("Please choose an option (1-5): ");
}

void execute_option(int choice) {
    switch (choice) {
        case 1:
            printf("Displaying System Information:\n");
            system("uname -a");
            break;
        case 2:
            printf("Checking Disk Usage:\n");
            system("df -h");
            break;
        case 3:
            printf("Current Users:\n");
            system("who");
            break;
        case 4:
            printf("Monitoring System Load (Press Ctrl+C to stop):\n");
            system("top");
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
    }
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);
        execute_option(choice);
    } while (choice != 5);

    return 0;
}