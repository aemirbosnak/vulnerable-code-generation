//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LOG_SIZE 1024
#define LOG_FILE "/var/log/sysadmin_activity.log"

// Function to log messages to a specified log file
void log_message(const char *message) {
    FILE *logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL) {
        perror("Could not open log file");
        return;
    }

    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char timeString[26];
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", tm_info);

    fprintf(logFile, "[%s] %s\n", timeString, message);
    fclose(logFile);
}

// Function to get the current disk usage
void check_disk_usage() {
    printf("Checking disk usage...\n");
    log_message("Checking disk usage.");
    system("df -h");
}

// Function to display the current memory usage
void check_memory_usage() {
    printf("Checking memory usage...\n");
    log_message("Checking memory usage.");
    system("free -h");
}

// Function to display system uptime
void check_system_uptime() {
    printf("Checking system uptime...\n");
    log_message("Checking system uptime.");
    system("uptime");
}

// Function to show the top users consuming CPU resources
void check_top_users() {
    printf("Checking top 5 CPU consuming processes...\n");
    log_message("Checking top CPU consuming processes.");
    system("ps -eo user,pid,pcpu,pmem,command --sort=-pcpu | head -n 6");
}

// Function to display active network connections
void check_network_connections() {
    printf("Checking active network connections...\n");
    log_message("Checking active network connections.");
    system("ss -tuln");
}

// Function to display a menu of system administration tasks
void display_menu() {
    printf("\n===== System Administration Menu =====\n");
    printf("1. Check disk usage\n");
    printf("2. Check memory usage\n");
    printf("3. Check system uptime\n");
    printf("4. Show top CPU consuming users\n");
    printf("5. Check active network connections\n");
    printf("6. Exit\n");
    printf("======================================\n");
}

// Main function
int main() {
    int choice;

    // Ensure the log file can be written to
    log_message("System administration program started.");

    do {
        display_menu();

        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_disk_usage();
                break;
            case 2:
                check_memory_usage();
                break;
            case 3:
                check_system_uptime();
                break;
            case 4:
                check_top_users();
                break;
            case 5:
                check_network_connections();
                break;
            case 6:
                log_message("Exiting the program.");
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                log_message("User made an invalid choice.");
        }

        printf("\nPress Enter to continue...");
        while (getchar() != '\n'); // clear buffer
        getchar(); // wait for Enter

    } while (choice != 6);

    return 0;
}