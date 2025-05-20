//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_uptime() {
    printf("\n🕒 Fetching system uptime...\n");
    system("uptime");
}

void display_users() {
    printf("\n👥 Gathering current users...\n");
    system("who");
}

void display_disk_usage() {
    printf("\n💾 Checking disk usage...\n");
    system("df -h");
}

void display_processes() {
    printf("\n🔍 Listing active processes...\n");
    system("ps aux");
}

void shocking_resource_hog() {
    printf("\n😱 Warning! Forcing a shockingly high CPU load...\n");
    printf("This might make your system unresponsive. Proceed with caution!\n");
    for (int i = 0; i < 3; i++) {
        printf("Shocking your CPU... %d/3\n", i + 1);
        fflush(stdout); // Ensure the output is printed instantly
        for (unsigned long j = 0; j < 100000000; j++); // Busy-wait loop
    }
    printf("👀 Just kidding! But be careful with CPU usage!\n");
}

void display_menu() {
    printf("\n---- System Administration Shock Tool ----\n");
    printf("1. Check Uptime\n");
    printf("2. List Current Users\n");
    printf("3. Show Disk Usage\n");
    printf("4. Display Processes\n");
    printf("5. Shock CPU (WARNING)\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_uptime();
                break;
            case 2:
                display_users();
                break;
            case 3:
                display_disk_usage();
                break;
            case 4:
                display_processes();
                break;
            case 5:
                shocking_resource_hog();
                break;
            case 6:
                printf("👋 Exiting... Thank you for using the Shock Tool!\n");
                break;
            default:
                printf("🚫 Invalid choice! Try again.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}