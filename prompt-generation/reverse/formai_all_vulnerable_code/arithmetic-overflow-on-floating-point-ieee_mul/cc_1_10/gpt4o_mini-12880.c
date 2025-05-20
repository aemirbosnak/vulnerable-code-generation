//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

#define MAX_CPUS 16
#define SLEEP_INTERVAL 1
#define TOTAL_SAMPLE_COUNT 10

void get_cpu_usage(double *usage, int count);
void display_cpu_usage(double usage[], int count);
void display_current_load(struct sysinfo info);

int main() {
    double cpu_usage[MAX_CPUS] = {0};
    struct sysinfo sys_info;
    
    printf("Initializing CPU Usage Monitor...\n");
    printf("Monitoring CPU usage every %d second(s)\n", SLEEP_INTERVAL);
    printf("Press Ctrl+C to stop the monitoring.\n\n");

    while (1) {
        // Capture initial load and perform calculations
        get_cpu_usage(cpu_usage, MAX_CPUS);
        if (sysinfo(&sys_info) == 0) {
            display_current_load(sys_info);
        }

        // Print CPU usage
        printf("\nCPU Usage (last %d seconds):\n", TOTAL_SAMPLE_COUNT);
        display_cpu_usage(cpu_usage, MAX_CPUS);
        
        // Sleep for specified interval
        sleep(SLEEP_INTERVAL);
    }

    return 0;
}

void get_cpu_usage(double *usage, int count) {
    FILE *fp;
    char path[128];
    double total_time = 0.0, idle_time = 0.0;

    // Read /proc/stat for CPU usage details
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        if (!fgets(path, sizeof(path) - 1, fp)) {
            break; // Exit if we reach the end of file
        }
        
        // Skip the first line which is total CPU usage
        if (i == 0) {
            continue;
        }

        char *token = strtok(path, " ");
        int j = 0;

        while (token != NULL) {
            if (j == 0) {
                // Get CPU number
                usage[i - 1] = atof(token);
            } else {
                double time = atof(token);
                total_time += time; // Accumulate total time
                if (j == 3) { // Idle time (4th value in /proc/stat)
                    idle_time += time;
                }
            }
            token = strtok(NULL, " ");
            j++;
        }
        
        // In addition to idle time, get active time (total - idle)
        usage[i - 1] = 100.0 * (total_time - idle_time) / total_time;
    }

    fclose(fp);
}

void display_cpu_usage(double usage[], int count) {
    printf("%-10s%-10s\n", "CPU", "Usage (%)");
    for (int i = 0; i < count; i++) {
        if (usage[i] > 0) {
            printf("CPU%-8d%-10.2f\n", i, usage[i]);
        }
    }
}

void display_current_load(struct sysinfo info) {
    printf("Current Loadavg: %.2f\n", info.loads[0] / 65536.0);
    printf("Free RAM: %lu kB\n", info.freeram / 1024);
    printf("Total RAM: %lu kB\n", info.totalram / 1024);
    printf("Uptime: %ld seconds\n", info.uptime);
}