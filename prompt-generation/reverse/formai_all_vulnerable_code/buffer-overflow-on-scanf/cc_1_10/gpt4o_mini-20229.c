//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

// Function to get current time as a string
char* get_current_time() {
    time_t t;
    time(&t);
    return ctime(&t);
}

// Function to write log messages to a log file
void log_message(const char* message) {
    FILE *log_file = fopen("system_admin.log", "a");
    if (log_file == NULL) {
        perror("Unable to open log file!");
        exit(EXIT_FAILURE);
    }
    fprintf(log_file, "[%s] %s\n", get_current_time(), message);
    fclose(log_file);
}

// Function to display disk usage
void check_disk_usage() {
    printf("\nChecking Disk Usage:\n");
    log_message("Disk usage checked.");
    system("df -h");
}

// Function to display system uptime
void check_uptime() {
    printf("\nChecking System Uptime:\n");
    log_message("System uptime checked.");
    system("uptime");
}

// Function to display current users
void check_current_users() {
    printf("\nCurrent Logged In Users:\n");
    log_message("Current users checked.");
    system("who");
}

// Function to check memory usage
void check_memory_usage() {
    printf("\nChecking Memory Usage:\n");
    log_message("Memory usage checked.");
    system("free -h");
}

// Function to check active network connections
void check_network_connections() {
    printf("\nActive Network Connections:\n");
    log_message("Network connections checked.");
    system("netstat -tuln");
}

// Function to display the menu
void display_menu() {
    printf("\n--- System Administration Menu ---\n");
    printf("1. Check Disk Usage\n");
    printf("2. Check System Uptime\n");
    printf("3. Check Current Users\n");
    printf("4. Check Memory Usage\n");
    printf("5. Check Network Connections\n");
    printf("6. Exit\n");
    printf("Select an option (1-6): ");
}

// Function to handle user input and call appropriate functions
void handle_input(int choice) {
    switch (choice) {
        case 1:
            check_disk_usage();
            break;
        case 2:
            check_uptime();
            break;
        case 3:
            check_current_users();
            break;
        case 4:
            check_memory_usage();
            break;
        case 5:
            check_network_connections();
            break;
        case 6:
            log_message("Exiting program.");
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
            log_message("Invalid option selected.");
    }
}

int main() {
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        handle_input(choice);
    }
    
    return 0;
}