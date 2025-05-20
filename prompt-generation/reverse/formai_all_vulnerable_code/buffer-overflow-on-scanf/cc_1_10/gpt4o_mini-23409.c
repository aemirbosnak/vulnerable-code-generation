//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

void displayCpuUsage() {
    FILE *fp;
    char buffer[1024];
    
    fp = popen("top -bn1 | grep 'Cpu(s)'", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }
    
    printf("CPU Usage:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    
    pclose(fp);
}

void displayMemoryUsage() {
    struct sysinfo info;
    sysinfo(&info);
    
    printf("Memory Usage:\n");
    printf("Total RAM: %lu MB\n", info.totalram / (1024 * 1024));
    printf("Free RAM: %lu MB\n", info.freeram / (1024 * 1024));
    printf("Used RAM: %lu MB\n", (info.totalram - info.freeram) / (1024 * 1024));
}

void displayDiskUsage() {
    FILE *fp;
    char buffer[1024];
    
    fp = popen("df -h", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }
    
    printf("Disk Usage:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    
    pclose(fp);
}

void printMenu() {
    printf("System Resource Monitor\n");
    printf("1. Check CPU Usage\n");
    printf("2. Check Memory Usage\n");
    printf("3. Check Disk Usage\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    int interval = 0;
    
    while (1) {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayCpuUsage();
                break;
            case 2:
                displayMemoryUsage();
                break;
            case 3:
                displayDiskUsage();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                continue;
        }
        
        printf("Do you want to continue checking resources after an interval? (1: Yes, 0: No): ");
        scanf("%d", &interval);
        
        if (interval) {
            int seconds;
            printf("Enter interval in seconds: ");
            scanf("%d", &seconds);
            
            printf("Waiting %d seconds...\n", seconds);
            sleep(seconds);
        }
    }
    
    return 0;
}