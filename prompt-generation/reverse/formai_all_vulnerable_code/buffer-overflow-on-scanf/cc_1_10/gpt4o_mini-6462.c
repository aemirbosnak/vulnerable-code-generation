//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to get CPU Usage
void get_cpu_usage() {
    FILE *fp;
    char buffer[1024];

    fp = popen("top -bn1 | grep 'Cpu(s)'", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("CPU Usage: %s", buffer);
    }
    pclose(fp);
}

// Function to get Memory Usage
void get_memory_usage() {
    FILE *fp;
    char buffer[1024];

    fp = popen("free -h", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    printf("\nMemory Usage:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

// Function to get Disk Space
void get_disk_usage() {
    FILE *fp;
    char buffer[1024];

    fp = popen("df -h", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    printf("\nDisk Usage:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

// Function to clear the console
void clear_console() {
    printf("\033[H\033[J");
}

// Function to display menu
void display_menu() {
    printf("\nSystem Resource Monitor\n");
    printf("1. View CPU Usage\n");
    printf("2. View Memory Usage\n");
    printf("3. View Disk Usage\n");
    printf("4. Clear Console\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                clear_console();
                get_cpu_usage();
                break;
            case 2:
                clear_console();
                get_memory_usage();
                break;
            case 3:
                clear_console();
                get_disk_usage();
                break;
            case 4:
                clear_console();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        printf("\nPress Enter to continue...");
        while (getchar() != '\n');  // Clear input buffer
        getchar();  // Wait for user to press Enter
    }

    return 0;
}