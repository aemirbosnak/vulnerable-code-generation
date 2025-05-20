//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#define MAX_PROCESSES 100
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    long memoryUsage;
} ProcessInfo;

ProcessInfo processes[MAX_PROCESSES];
int processCount = 0;
volatile sig_atomic_t running = 1;

void sigint_handler(int signum) {
    running = 0;
}

void* monitor_memory_usage(void* arg) {
    while (running) {
        FILE* file = fopen("/proc/meminfo", "r");
        if (!file) {
            perror("Failed to open /proc/meminfo");
            return NULL;
        }

        char line[BUFFER_SIZE];
        long totalMemory = 0;
        long freeMemory = 0;
        
        while (fgets(line, sizeof(line), file)) {
            if (sscanf(line, "MemTotal: %ld kB", &totalMemory) == 1) continue;
            if (sscanf(line, "MemAvailable: %ld kB", &freeMemory) == 1) continue;
        }
        fclose(file);

        long usedMemory = totalMemory - freeMemory;
        printf("Total Memory: %ld kB, Used Memory: %ld kB\n", totalMemory, usedMemory);

        sleep(2); // sleep for 2 seconds before checking again
    }
    return NULL;
}

void* get_process_memory_info(void* arg) {
    while (running) {
        for (int i = 1; i <= MAX_PROCESSES; i++) {
            char path[BUFFER_SIZE];
            snprintf(path, sizeof(path), "/proc/%d/statm", i);
            FILE* file = fopen(path, "r");

            if (file) {
                long size, resident;
                if (fscanf(file, "%ld %ld", &size, &resident) == 2) {
                    ProcessInfo info;
                    info.pid = i;
                    info.memoryUsage = resident * 4; // Convert from pages to KB
                    snprintf(info.name, sizeof(info.name), "Process %d", i);
                    processes[processCount++] = info;
                    printf("PID: %d, Memory Usage: %ld KB\n", info.pid, info.memoryUsage);
                }
                fclose(file);
            }
        }
        sleep(5); // pause for 5 seconds before scanning processes again
    }
    return NULL;
}

void print_usage() {
    printf("\nMemory Usage Monitor\n");
    printf("Press Ctrl+C to stop the monitor.\n");
}

int main() {
    signal(SIGINT, sigint_handler);
    print_usage();

    pthread_t memoryMonitorThread, processMemoryThread;

    if (pthread_create(&memoryMonitorThread, NULL, monitor_memory_usage, NULL) != 0) {
        perror("Failed to create memory monitor thread");
        return EXIT_FAILURE;
    }

    if (pthread_create(&processMemoryThread, NULL, get_process_memory_info, NULL) != 0) {
        perror("Failed to create process memory information thread");
        return EXIT_FAILURE;
    }

    pthread_join(memoryMonitorThread, NULL);
    pthread_join(processMemoryThread, NULL);

    printf("Memory usage monitoring has stopped.\n");

    return EXIT_SUCCESS;
}