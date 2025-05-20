//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkDiskSpace() {
    printf("\n--- Disk Space Usage ---\n");
    system("df -h");
}

void listCurrentUsers() {
    printf("\n--- Current Users ---\n");
    system("who");
}

void displayUptime() {
    printf("\n--- System Uptime ---\n");
    system("uptime");
}

void displayMenu() {
    printf("\n--- Simple System Administration Tool ---\n");
    printf("1. Check Disk Space\n");
    printf("2. List Current Users\n");
    printf("3. Display System Uptime\n");
    printf("4. Exit\n");
    printf("Please select an option: ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkDiskSpace();
                break;
            case 2:
                listCurrentUsers();
                break;
            case 3:
                displayUptime();
                break;
            case 4:
                printf("Exiting... Have a great day!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}