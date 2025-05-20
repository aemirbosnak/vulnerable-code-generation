//FormAI DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void clear_screen() {
    printf("\033[2J\033[1;1H");
}

void print_menu() {
    printf("========== System Administration Menu ==========\n");
    printf("1. Check Disk Space\n");
    printf("2. View Running Processes\n");
    printf("3. Check System Load Average\n");
    printf("4. Stop a Running Process\n");
    printf("5. Exit\n");
}

void check_disk_space() {
    system("df -h");
}

void view_running_processes() {
    system("ps aux");
}

void check_system_load_average() {
    system("uptime");
}

void stop_running_process() {
    char cmd[100];
    int pid;

    printf("Enter PID of the process to stop: ");
    scanf("%d", &pid);

    sprintf(cmd, "kill %d", pid);
    system(cmd);
}

int main() {
    int choice;

    do {
        clear_screen();
        print_menu();

        printf("\n\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                check_disk_space();
                break;
            case 2:
                view_running_processes();
                break;
            case 3:
                check_system_load_average();
                break;
            case 4:
                stop_running_process();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                sleep(2);
        }
    } while(choice != 5);

    return 0;
}