//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void display_cpu_usage() {
    system("top -bn1 | grep 'Cpu(s)'");
}

void display_memory_usage() {
    system("free -h");
}

void display_disk_usage() {
    system("df -h");
}

void display_active_processes() {
    system("ps aux --sort=-%mem | head -n 10");
}

void clear_screen() {
    printf("\033[H\033[J");
}

void display_menu() {
    printf("****************************************\n");
    printf("          System Resource Monitor        \n");
    printf("****************************************\n");
    printf("1. CPU Usage\n");
    printf("2. Memory Usage\n");
    printf("3. Disk Space Usage\n");
    printf("4. Active Processes\n");
    printf("5. Exit\n");
    printf("****************************************\n");
    printf("Select an option: ");
}

int main() {
    int option;

    do {
        clear_screen();
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                clear_screen();
                printf("----- CPU Usage -----\n");
                display_cpu_usage();
                break;
            case 2:
                clear_screen();
                printf("----- Memory Usage -----\n");
                display_memory_usage();
                break;
            case 3:
                clear_screen();
                printf("----- Disk Space Usage -----\n");
                display_disk_usage();
                break;
            case 4:
                clear_screen();
                printf("----- Active Processes -----\n");
                display_active_processes();
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
        
        if (option != 5) {
            printf("\nPress Enter to continue...");
            while(getchar() != '\n'); // Clear the buffer
            getchar(); // Wait for Enter
        }

    } while (option != 5);

    return 0;
}