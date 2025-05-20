//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_COMMANDS 50
#define COMMAND_LENGTH 256

void display_menu() {
    printf("\n--- Surprise System Admin Utility ---\n");
    printf("1. List all running processes\n");
    printf("2. Check disk usage\n");
    printf("3. Display current users\n");
    printf("4. Monitor system load\n");
    printf("5. Get current date and time\n");
    printf("6. Exit\n");
    printf("Choose an option (1-6): ");
}

void list_processes() {
    FILE *fp = popen("ps aux", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }
    char buffer[COMMAND_LENGTH];
    printf("\n--- Running Processes ---\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

void check_disk_usage() {
    FILE *fp = popen("df -h", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }
    char buffer[COMMAND_LENGTH];
    printf("\n--- Disk Usage ---\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

void display_current_users() {
    FILE *fp = popen("who", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }
    char buffer[COMMAND_LENGTH];
    printf("\n--- Current Users ---\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

void monitor_system_load() {
    FILE *fp = popen("uptime", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }
    char buffer[COMMAND_LENGTH];
    printf("\n--- System Load ---\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

void get_current_date_time() {
    FILE *fp = popen("date", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }
    char buffer[COMMAND_LENGTH];
    printf("\n--- Current Date and Time ---\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

int main() {
    int choice;

    do {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Please enter a valid number.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                list_processes();
                break;
            case 2:
                check_disk_usage();
                break;
            case 3:
                display_current_users();
                break;
            case 4:
                monitor_system_load();
                break;
            case 5:
                get_current_date_time();
                break;
            case 6:
                printf("Exiting the utility. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}