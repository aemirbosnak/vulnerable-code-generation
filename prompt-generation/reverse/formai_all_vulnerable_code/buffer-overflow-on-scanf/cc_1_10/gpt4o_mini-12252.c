//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_CMD_LENGTH 256
#define MAX_LOG_LENGTH 512
#define LOG_FILE "sysadmin_log.txt"

// Function to log messages to a file
void log_message(const char *message) {
    FILE *logfile = fopen(LOG_FILE, "a");
    if (logfile == NULL) {
        perror("Failed to open log file");
        return;
    }
    fprintf(logfile, "%s\n", message);
    fclose(logfile);
}

// Function to display the current system time
void show_time() {
    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    printf("Current system time: %s", time_str);
    log_message("Displayed current system time.");
}

// Function to list files in the current directory
void list_files() {
    system("ls -l");
    log_message("Listed files in current directory.");
}

// Function to change the ownership of a file
void change_ownership(const char *file, const char *user) {
    char command[MAX_CMD_LENGTH];
    snprintf(command, sizeof(command), "sudo chown %s %s", user, file);
    int status = system(command);
    printf(status == 0 ? "Changed ownership of %s to %s.\n" : "Failed to change ownership of %s.\n", file, user);
    log_message("Changed ownership of file.");
}

// Function to modify file permissions
void change_permissions(const char *file, const char *permissions) {
    char command[MAX_CMD_LENGTH];
    snprintf(command, sizeof(command), "sudo chmod %s %s", permissions, file);
    int status = system(command);
    printf(status == 0 ? "Changed permissions of %s to %s.\n" : "Failed to change permissions of %s.\n", file, permissions);
    log_message("Changed file permissions.");
}

// Function to check disk usage
void check_disk_usage() {
    system("df -h");
    log_message("Displayed disk usage information.");
}

// Function to display a menu of options
void display_menu() {
    printf("=== System Administration Tool ===\n");
    printf("1. Show Current Time\n");
    printf("2. List Files in Current Directory\n");
    printf("3. Change Ownership of File\n");
    printf("4. Change Permissions of File\n");
    printf("5. Check Disk Usage\n");
    printf("6. Exit\n");
    printf("===================================\n");
}

int main() {
    int choice;
    char file[MAX_CMD_LENGTH], user[MAX_CMD_LENGTH], permissions[MAX_CMD_LENGTH];

    log_message("Sysadmin Tool Started.");

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                show_time();
                break;
            case 2:
                list_files();
                break;
            case 3:
                printf("Enter file name: ");
                scanf("%s", file);
                printf("Enter new owner: ");
                scanf("%s", user);
                change_ownership(file, user);
                break;
            case 4:
                printf("Enter file name: ");
                scanf("%s", file);
                printf("Enter new permissions (e.g., 755): ");
                scanf("%s", permissions);
                change_permissions(file, permissions);
                break;
            case 5:
                check_disk_usage();
                break;
            case 6:
                log_message("Sysadmin Tool Exited.");
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                log_message("Invalid menu choice.");
        }
    }

    return 0;
}