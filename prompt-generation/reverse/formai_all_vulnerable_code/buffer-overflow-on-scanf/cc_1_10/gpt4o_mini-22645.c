//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void list_processes() {
    printf("Listing all running processes:\n");
    system("ps aux");
}

void kill_process() {
    int pid;
    printf("Enter the PID of the process you want to kill: ");
    scanf("%d", &pid);
    if (kill(pid, SIGKILL) == 0) {
        printf("Process %d killed successfully.\n", pid);
    } else {
        perror("Failed to kill process");
    }
}

void disk_usage() {
    printf("Displaying disk usage:\n");
    system("df -h");
}

void memory_usage() {
    printf("Displaying memory usage:\n");
    system("free -h");
}

void user_info() {
    printf("Current user information:\n");
    system("whoami");
}

void check_internet() {
    printf("Checking internet connection:\n");
    system("ping -c 1 google.com > /dev/null 2>&1 && echo 'Internet is up!' || echo 'Internet is down!'");
}

void show_menu() {
    printf("\n=== System Administration Menu ===\n");
    printf("1. List Processes\n");
    printf("2. Kill a Process\n");
    printf("3. Disk Usage\n");
    printf("4. Memory Usage\n");
    printf("5. User Info\n");
    printf("6. Check Internet Connection\n");
    printf("7. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    int choice;

    while (1) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_processes();
                break;
            case 2:
                kill_process();
                break;
            case 3:
                disk_usage();
                break;
            case 4:
                memory_usage();
                break;
            case 5:
                user_info();
                break;
            case 6:
                check_internet();
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("Press Enter to continue...");
        getchar(); // To catch newline
        getchar(); // Wait for user to press Enter
    }

    return 0;
}