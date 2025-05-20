//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

void print_system_info() {
    struct sysinfo info;
    sysinfo(&info);
    
    printf("System Information:\n");
    printf("Uptime: %ld days, %ld hours, %ld minutes\n", 
           info.uptime / (60 * 60 * 24), 
           (info.uptime / (60 * 60)) % 24, 
           (info.uptime / 60) % 60);
    printf("Total RAM: %lu MB\n", info.totalram / (1024 * 1024));
    printf("Free RAM: %lu MB\n", info.freeram / (1024 * 1024));
    printf("Number of processes: %d\n", info.procs);
}

void print_current_time() {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    printf("Current Date and Time: %s", asctime(tm_info));
}

void display_menu() {
    printf("\n=======================\n");
    printf("System Administration Menu\n");
    printf("=======================\n");
    printf("1. View System Info\n");
    printf("2. View Current Time\n");
    printf("3. Exit\n");
    printf("=======================\n");
}

int main() {
    int choice;
    do {
        display_menu();
        printf("Select an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nFetching system information...\n");
                print_system_info();
                break;

            case 2:
                printf("\nFetching current date and time...\n");
                print_current_time();
                break;
                
            case 3:
                printf("\nExiting the program. Thank you!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}