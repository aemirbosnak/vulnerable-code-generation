//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct {
    float cpu_usage;
    float mem_usage;
    float disk_usage;
} SystemStats;

SystemStats stats;

void* update_stats(void* arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        // Get CPU usage
        FILE* fp = fopen("/proc/stat", "r");
        if (fp != NULL) {
            fgets(buffer, sizeof(buffer), fp);
            fclose(fp);
            float idle, total;
            sscanf(buffer, "cpu %*s %*s %*s %f", &idle);
            total = idle + (float)sysconf(_SC_NPROCESSORS_ONLN) * 100;
            stats.cpu_usage = 100 * (total - idle) / total;
        }

        // Get Memory usage
        fp = fopen("/proc/meminfo", "r");
        if (fp != NULL) {
            float mem_total, mem_free;
            fgets(buffer, sizeof(buffer), fp);
            sscanf(buffer, "MemTotal: %f kB", &mem_total);
            fgets(buffer, sizeof(buffer), fp);
            sscanf(buffer, "MemFree: %f kB", &mem_free);
            fclose(fp);
            stats.mem_usage = 100 * (mem_total - mem_free) / mem_total;
        }

        // Get Disk usage
        long long total_blocks = 0, free_blocks = 0;
        fp = popen("df --block-size=1K / | grep / | awk '{ print $2, $4 }'", "r");
        if (fp != NULL) {
            fscanf(fp, "%lld %lld", &total_blocks, &free_blocks);
            pclose(fp);
            stats.disk_usage = 100 * (1 - (float)free_blocks / total_blocks);
        }

        usleep(1000000); // Sleep for 1 second
    }
    return NULL;
}

void display_stats() {
    printf("\033[H\033[J"); // clear screen
    printf("System Monitoring Tool\n");
    printf("=========================\n");
    printf("CPU Usage: %.2f%%\n", stats.cpu_usage);
    printf("Memory Usage: %.2f%%\n", stats.mem_usage);
    printf("Disk Usage: %.2f%%\n", stats.disk_usage);
}

int main() {
    pthread_t thread_id;

    // Create a thread to update statistics
    if (pthread_create(&thread_id, NULL, update_stats, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    while (1) {
        display_stats();
        usleep(1000000); // Sleep for 1 second before refreshing display
    }

    pthread_join(thread_id, NULL);
    return 0;
}