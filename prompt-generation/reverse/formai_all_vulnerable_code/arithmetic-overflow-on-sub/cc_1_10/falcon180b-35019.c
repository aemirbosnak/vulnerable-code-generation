//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 100

// Function prototypes
void print_cpu_usage(double cpu_percentage);
void print_memory_usage(double memory_percentage);
void print_uptime(long uptime);

int main() {
    double cpu_percentage, memory_percentage;
    long uptime;
    char line[MAX_LINE_LENGTH];

    // Initialize variables
    cpu_percentage = 0.0;
    memory_percentage = 0.0;
    uptime = 0;

    while (1) {
        // Get CPU usage
        FILE *file = fopen("/proc/stat", "r");
        if (file == NULL) {
            printf("Error: Could not open /proc/stat\n");
            exit(1);
        }

        fscanf(file, "cpu %*d %*d %*d %*d %*d %*d %*d %ld", &uptime);
        fclose(file);

        // Get CPU percentage
        cpu_percentage = ((double) (100 - (int) ((double) uptime / (double) sysconf(_SC_CLK_TCK) * 100.0))) / 100.0;

        // Get memory usage
        FILE *meminfo = fopen("/proc/meminfo", "r");
        if (meminfo == NULL) {
            printf("Error: Could not open /proc/meminfo\n");
            exit(1);
        }

        while (fgets(line, MAX_LINE_LENGTH, meminfo)!= NULL) {
            if (strstr(line, "MemTotal:")!= NULL) {
                fscanf(meminfo, "MemTotal: %lu kB", &memory_percentage);
                break;
            }
        }

        fclose(meminfo);

        // Print CPU usage
        print_cpu_usage(cpu_percentage);

        // Print memory usage
        print_memory_usage(memory_percentage);

        // Print uptime
        print_uptime(uptime);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}

void print_cpu_usage(double cpu_percentage) {
    printf("CPU Usage: %.2f%%\n", cpu_percentage);
}

void print_memory_usage(double memory_percentage) {
    printf("Memory Usage: %.2f%%\n", memory_percentage);
}

void print_uptime(long uptime) {
    printf("Uptime: %ld seconds\n", uptime);
}