//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_cpu_usage() {
    FILE *fp;
    char buffer[100];
    unsigned long user, nice, system, idle;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to read cpu stats");
        return;
    }

    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %lu %lu %lu %lu", &user, &nice, &system, &idle);
    fclose(fp);

    unsigned long total = user + nice + system + idle;
    printf("CPU Usage:\n");
    printf("User: %.2f%%\n", (double)user / total * 100);
    printf("System: %.2f%%\n", (double)system / total * 100);
    printf("Idle: %.2f%%\n", (double)idle / total * 100);
}

void display_memory_usage() {
    FILE *fp;
    char buffer[100];
    unsigned long total_memory, free_memory;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to read memory stats");
        return;
    }

    fgets(buffer, sizeof(buffer), fp); // Total Memory
    sscanf(buffer, "MemTotal: %lu kB", &total_memory);
    fgets(buffer, sizeof(buffer), fp); // Free Memory
    sscanf(buffer, "MemFree: %lu kB", &free_memory);
    fclose(fp);

    unsigned long used_memory = total_memory - free_memory;
    printf("Memory Usage:\n");
    printf("Total: %lu kB\n", total_memory);
    printf("Used: %lu kB\n", used_memory);
    printf("Free: %lu kB\n", free_memory);
}

void display_disk_usage() {
    FILE *fp;
    char buffer[256];

    printf("Disk Usage:\n");
    fp = popen("df -h", "r");
    if (fp == NULL) {
        perror("Failed to run df command");
        return;
    }

    while (fgets(buffer, sizeof(buffer) - 1, fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

int main() {
    int choice;
    
    while (1) {
        printf("\nSystem Monitoring Tool\n");
        printf("1. Display CPU Usage\n");
        printf("2. Display Memory Usage\n");
        printf("3. Display Disk Usage\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_cpu_usage();
                break;
            case 2:
                display_memory_usage();
                break;
            case 3:
                display_disk_usage();
                break;
            case 4:
                printf("Exiting the program. Have a nice day!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}