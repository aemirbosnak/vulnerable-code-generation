//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

void drawShape(int cpuUsage) {
    // Map CPU usage to the number of bars (0-20)
    int bars = cpuUsage / 5;

    // Print shape based on the level of CPU usage
    printf("CPU Usage: %d%%\n", cpuUsage);
    for (int i = 0; i < 20; i++) {
        if (i < bars) {
            printf("█");
        } else {
            printf("░");
        }
    }
    printf("\n");
}

void printHeader() {
    printf("\n=============================\n");
    printf("     CPU USAGE MONITOR\n");
    printf("=============================\n");
}

int getCPUUsage() {
    FILE *fp;
    long long totalUser, totalUserLow, totalSys, totalIdle, total;
    float cpuUsage;

    // Open the file to read CPU information
    if ((fp = fopen("/proc/stat", "r")) == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the first line (the total CPU stats)
    fscanf(fp, "cpu  %lld %lld %lld %lld", &totalUser, &totalUserLow, &totalSys, &totalIdle);
    fclose(fp);

    // Calculate total CPU time
    total = totalUser + totalUserLow + totalSys + totalIdle;
    
    // Calculate CPU usage percentage
    cpuUsage = 100 * (1.0 - ((float)totalIdle / total));
    return (int)cpuUsage;
}

int main() {
    printHeader();
    
    while (1) {
        int cpuUsage = getCPUUsage();
        if (cpuUsage == -1) {
            return 1; // Exit on error
        }
        
        // Clear the console
        printf("\033c");

        drawShape(cpuUsage);
        
        // Wait for 1 second
        sleep(1);
    }

    return 0;
}