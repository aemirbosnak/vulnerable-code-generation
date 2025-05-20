//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <time.h>

// Function to extract CPU usage percentage from /proc/stat
float get_cpu_usage() {
    FILE* file;
    char buffer[256];
    unsigned long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    float cpu_usage;

    file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to open /proc/stat");
        return -1.0;
    }

    fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu", 
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    fclose(file);

    // Calculate CPU usage
    unsigned long total_idle = idle + iowait;
    unsigned long total_active = user + nice + system + irq + softirq + steal + guest + guest_nice;

    unsigned long total = total_idle + total_active;
    
    cpu_usage = ((float)total_active / total) * 100;

    return cpu_usage;
}

// Function for printing CPU usage every second
void monitor_cpu_usage() {
    time_t start_time, end_time;
    float cpu_usage;
    
    printf("Monitoring CPU usage. Press Ctrl+C to exit.\n");
    printf("%-15s %s\n", "Timestamp", "CPU Usage (%)");
    printf("-----------------------------------------\n");

    while (1) {
        start_time = time(NULL);
        cpu_usage = get_cpu_usage();
        
        if (cpu_usage < 0) {
            fprintf(stderr, "Error retrieving CPU usage.\n");
            break;
        }

        // Print usage with timestamp
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&start_time));
        printf("%-15s %.2f\n", timestamp, cpu_usage);

        sleep(1);
    }
}

// Main function
int main() {
    monitor_cpu_usage();
    return 0;
}