//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_CPUS 64

void display_usage(float cpu_usage[], int num_cpus);
void monitor_cpu_usage(int interval);

int main() {
    // Welcome Message
    printf("🌟🌼 Welcome to the Happy CPU Usage Monitor! 🌼🌟\n");
    printf("Let's keep track of your CPU usage in a joyful manner! 🎉\n");
    
    int interval = 1; // Default to 1 second intervals
    monitor_cpu_usage(interval);
    
    return 0;
}

void display_usage(float cpu_usage[], int num_cpus) {
    printf("🌈 CPU Usage Monitor 🌈\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_cpus; i++) {
        printf("🌟 CPU %d: %.2f%% 🌟\n", i, cpu_usage[i]);
    }
    printf("--------------------------------------------------\n");
}

void monitor_cpu_usage(int interval) {
    FILE *fp;
    char buffer[256];
    float cpu_usage[MAX_CPUS];
    int num_cpus = sysconf(_SC_NPROCESSORS_ONLN); // Get the number of CPUs
    
    while (1) {
        // Open the file to read CPU statistics
        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            perror("Failed to open /proc/stat");
            continue;
        }

        // Read the first line which contains aggregate CPU info
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            long long user, nice, system, idle, iowait, irq, softirq, steal;
            sscanf(buffer, "cpu %lld %lld %lld %lld %lld %lld %lld %lld",
                   &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);

            long long total = user + nice + system + idle + iowait + irq + softirq + steal;
            long long active = total - idle;
            float usage = (float) active / total * 100.0;

            for (int i = 0; i < num_cpus; i++) {
                cpu_usage[i] = usage;
            }

            // Display CPU Usage
            display_usage(cpu_usage, num_cpus);
        }

        fclose(fp);
        printf("💤 Sleeping for %d seconds... Zzz\n", interval);
        sleep(interval); // Wait for the specified interval before refreshing
    }
}