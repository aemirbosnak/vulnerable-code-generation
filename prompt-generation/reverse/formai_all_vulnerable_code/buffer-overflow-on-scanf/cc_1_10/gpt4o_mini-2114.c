//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEMP_DIR "/tmp"

// Function to check disk usage
void check_disk_usage() {
    printf("Disk Usage:\n");
    system("df -h");
}

// Function to check CPU load
void check_cpu_load() {
    printf("\nCPU Load:\n");
    system("top -b -n1 | head -n 10");
}

// Function to clean temporary files
void clean_temp_files() {
    printf("\nCleaning temporary files from %s...\n", TEMP_DIR);
    if (system("rm -rf " TEMP_DIR "/*") == 0) {
        printf("Temporary files cleaned successfully.\n");
    } else {
        printf("Error cleaning temporary files.\n");
    }
}

// Function to display the current system uptime
void display_uptime() {
    printf("\nSystem Uptime:\n");
    system("uptime");
}

// Function to display memory usage
void display_memory_usage() {
    printf("\nMemory Usage:\n");
    system("free -h");
}

// Function to monitor system processes
void monitor_processes() {
    printf("\nMonitoring system processes:\n");
    system("ps aux --sort=-%mem | head -n 10");  // top 10 memory consuming processes
}

// Function to invoke system administrator tasks
void admin_tasks() {
    check_disk_usage();
    check_cpu_load();
    display_uptime();
    display_memory_usage();
    monitor_processes();
    
    char choice;
    printf("\nDo you want to clean temporary files? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        clean_temp_files();
    } else {
        printf("Skipping temporary file cleanup.\n");
    }
}

// Main function
int main() {
    printf("----------- System Administration Automation -----------\n");
    
    admin_tasks();
    
    printf("\nThank you for using the System Administration Automation tool!\n");
    return 0;
}