//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 256

void checkDiskUsage(int threshold);
void checkMemoryUsage(int threshold);
void listRunningServices();

int main() {
    int diskThreshold, memThreshold;

    printf("Welcome to the System Admin Dashboard!\n");
    printf("Let's configure your usage thresholds!\n");

    printf("Enter disk usage percentage threshold (0-100): ");
    scanf("%d", &diskThreshold);
    printf("Enter memory usage percentage threshold (0-100): ");
    scanf("%d", &memThreshold);

    printf("\n### System Checks Initiated! ###\n");
    
    checkDiskUsage(diskThreshold);
    checkMemoryUsage(memThreshold);
    listRunningServices();

    printf("\n### System Checks Complete! ###\n");
    return 0;
}

void checkDiskUsage(int threshold) {
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "df -h | awk '$NF==\"/\"{printf \"Disk Usage: %d%%\\n\", 100-$5}'");
    
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    int diskUsage;
    fscanf(fp, "Disk Usage: %d%%", &diskUsage);
    pclose(fp);

    printf("Current Disk Usage: %d%%\n", diskUsage);
    if (diskUsage >= threshold) {
        printf("Alert! Disk usage is above the set threshold of %d%%!\n", threshold);
    }
}

void checkMemoryUsage(int threshold) {
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "free | grep Mem | awk '{printf \"Memory Usage: %.2f%%\\n\", ($3/$2)*100}'");
    
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    float memUsage;
    fscanf(fp, "Memory Usage: %f%%", &memUsage);
    pclose(fp);

    printf("Current Memory Usage: %.2f%%\n", memUsage);
    if (memUsage >= threshold) {
        printf("Alert! Memory usage is above the set threshold of %d%%!\n", threshold);
    }
}

void listRunningServices() {
    printf("Currently Running Services:\n");
    system("systemctl list-units --type=service --state=running");
}