//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUF 256

void check_cpu_usage() {
    FILE *fp;
    char buffer[MAX_BUF];
    float usr, sys, nice, idle;

    // This command extracts CPU usage info
    fp = popen("mpstat | tail -1", "r");
    if (fp == NULL) {
        perror("Failed to execute command");
        exit(EXIT_FAILURE);
    }
    
    // Read the output from the command
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%*s %*s %*s %f %f %f %f", &usr, &nice, &sys, &idle);
        printf("CPU Usage: User: %.2f%%, System: %.2f%%, Nice: %.2f%%, Idle: %.2f%%\n",
               usr, sys, nice, idle);
    }
    
    pclose(fp);
}

void check_memory_usage() {
    FILE *fp;
    char buffer[MAX_BUF];
    long total, free, used;

    // This command extracts memory usage info
    fp = popen("free -m | grep Mem", "r");
    if (fp == NULL) {
        perror("Failed to execute command");
        exit(EXIT_FAILURE);
    }

    // Read the output from the command
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%*s %ld %ld %ld", &total, &used, &free);
        printf("Memory Usage: Total: %ld MB, Used: %ld MB, Free: %ld MB\n",
               total, used, free);
    }
    
    pclose(fp);
}

void check_disk_usage() {
    FILE *fp;
    char buffer[MAX_BUF];
    
    printf("Disk Usage:\n");
    // This command extracts disk usage info
    fp = popen("df -h --total | grep total", "r");
    if (fp == NULL) {
        perror("Failed to execute command");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    
    pclose(fp);
}

int main() {
    int choice;
    
    while (1) {
        printf("\n--- System Administration Tool ---\n");
        printf("1. Check CPU Usage\n");
        printf("2. Check Memory Usage\n");
        printf("3. Check Disk Usage\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_cpu_usage();
                break;
            case 2:
                check_memory_usage();
                break;
            case 3:
                check_disk_usage();
                break;
            case 4:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}