//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

#define TIME_INTERVAL 1
#define BUFFER_SIZE 256

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

double getCpuUsage() {
    // Get the CPU usage by reading from /proc/stat
    FILE *fp;
    char buffer[BUFFER_SIZE];
    unsigned long long idle_time, total_time, user_time, nice_time, system_time, iowait_time, irq_time, softirq_time, steal_time;
    
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Unable to open /proc/stat");
        exit(EXIT_FAILURE);
    }
    
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu  %llu %llu %llu %llu %llu %llu %llu %llu",
           &user_time, &nice_time, &system_time, &idle_time, &iowait_time, &irq_time, &softirq_time, &steal_time);
    
    fclose(fp);
    
    total_time = user_time + nice_time + system_time + idle_time + iowait_time + irq_time + softirq_time + steal_time;
    
    return 100.0 * (total_time - idle_time) / total_time; // Return CPU usage percentage
}

void displayUsage(double cpuUsage) {
    // Display the CPU usage in a visual format
    int barWidth = 50; // Width of the CPU usage bar
    int pos = (int)(barWidth * cpuUsage / 100);

    printf("\rCPU Usage: [");
    for (int i = 0; i < barWidth; i++) {
        if (i < pos) {
            printf("█"); // Filled part
        } else {
            printf(" "); // Empty part
        }
    }
    printf("] %.2f%%", cpuUsage);
    fflush(stdout);
}

int main() {
    printf("Starting CPU Usage Monitor...\n");
    printf("Press Ctrl+C to exit.\n");
    
    while (1) {
        double cpuUsage = getCpuUsage();
        clearScreen();
        displayUsage(cpuUsage);
        sleep(TIME_INTERVAL);
    }
    
    return 0;
}