//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define CPU_THRESHOLD 80
#define MEMORY_THRESHOLD 80
#define SLEEP_TIME 5

void* monitor_cpu(void* arg) {
    while (1) {
        FILE* fp;
        char buffer[256];
        int total_user, total_kernel, total_idle, total_steal, total;

        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            perror("fopen");
            return NULL;
        }
        fgets(buffer, sizeof(buffer), fp);
        sscanf(buffer, "cpu %d %*d %d %d %d %*d %*d %d", 
               &total_user, &total_kernel, &total_idle, &total_steal);
        fclose(fp);
        
        total = total_user + total_kernel + total_idle + total_steal;
        float cpu_usage = (100.0 * (total_user + total_kernel - total_idle)) / total;

        printf("Current CPU Usage: %.2f%%\n", cpu_usage);
        if (cpu_usage > CPU_THRESHOLD) {
            printf("Warning: CPU usage exceeded threshold!\n");
        }
        sleep(SLEEP_TIME);
    }
    return NULL;
}

void* monitor_memory(void* arg) {
    while (1) {
        FILE* fp;
        char buffer[256];
        int total_memory, free_memory;

        fp = fopen("/proc/meminfo", "r");
        if (fp == NULL) {
            perror("fopen");
            return NULL;
        }
        fgets(buffer, sizeof(buffer), fp);
        sscanf(buffer, "MemTotal: %d kB", &total_memory);
        fgets(buffer, sizeof(buffer), fp);
        sscanf(buffer, "MemFree: %d kB", &free_memory);
        fclose(fp);
        
        float memory_usage = 100.0 * (total_memory - free_memory) / total_memory;

        printf("Current Memory Usage: %.2f%%\n", memory_usage);
        if (memory_usage > MEMORY_THRESHOLD) {
            printf("Warning: Memory usage exceeded threshold!\n");
        }
        sleep(SLEEP_TIME);
    }
    return NULL;
}

int main() {
    pthread_t cpu_thread, memory_thread;

    // Create threads for monitoring CPU and Memory usage
    if (pthread_create(&cpu_thread, NULL, monitor_cpu, NULL) != 0) {
        perror("Failed to create CPU monitoring thread");
        return 1;
    }

    if (pthread_create(&memory_thread, NULL, monitor_memory, NULL) != 0) {
        perror("Failed to create Memory monitoring thread");
        return 1;
    }

    // Wait for threads to finish (they won't, in this case)
    pthread_join(cpu_thread, NULL);
    pthread_join(memory_thread, NULL);

    return 0;
}