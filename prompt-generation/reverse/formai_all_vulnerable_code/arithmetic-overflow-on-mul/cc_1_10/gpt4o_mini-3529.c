//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define BUFFER_SIZE 128

void get_memory_usage() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);

    long totalPhysMem = memInfo.totalram;
    totalPhysMem *= memInfo.mem_unit;

    long usedPhysMem = memInfo.totalram - memInfo.freeram;
    usedPhysMem *= memInfo.mem_unit;

    printf("Memory Usage:\n");
    printf("Total Memory: %.2f GB\n", (float)totalPhysMem / (1024 * 1024 * 1024));
    printf("Used Memory: %.2f GB\n", (float)usedPhysMem / (1024 * 1024 * 1024));
    printf("Free Memory: %.2f GB\n", (float)memInfo.freeram * memInfo.mem_unit / (1024 * 1024 * 1024));
}

void get_cpu_usage() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    unsigned long totalUser, totalUserNice, totalSystem, totalIdle, total;
    unsigned long totalCpuTime;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        return;
    }

    fgets(buffer, BUFFER_SIZE, fp);
    fclose(fp);

    sscanf(buffer, "cpu %lu %lu %lu %lu", &totalUser, &totalUserNice, &totalSystem, &totalIdle);

    total = totalUser + totalUserNice + totalSystem + totalIdle;
    totalCpuTime = total - totalIdle;

    printf("CPU Usage:\n");
    printf("Total CPU Time: %lu\n", total);
    printf("Total CPU Time (Active): %lu\n", totalCpuTime);
}

void display_usage() {
    printf("System Resource Monitor\n");
    printf("1. Show Memory Usage\n");
    printf("2. Show CPU Usage\n");
    printf("3. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_usage();

        printf("Select an option: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                get_memory_usage();
                break;
            case 2:
                get_cpu_usage();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                fprintf(stderr, "Invalid option. Please try again.\n");
        }
    }

    return 0;
}