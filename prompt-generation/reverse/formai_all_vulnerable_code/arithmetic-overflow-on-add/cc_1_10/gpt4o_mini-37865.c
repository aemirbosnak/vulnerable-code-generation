//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_CPUS 16

typedef struct {
    long user;
    long nice;
    long system;
    long idle;
    long iowait;
    long irq;
    long softirq;
} CPUUsage;

void getCPUUsage(CPUUsage *cpuUsage) {
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Could not open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[256];
    
    // Read the first line starting with "cpu "
    if (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "cpu %ld %ld %ld %ld %ld %ld %ld",
               &cpuUsage->user, &cpuUsage->nice, &cpuUsage->system,
               &cpuUsage->idle, &cpuUsage->iowait, &cpuUsage->irq,
               &cpuUsage->softirq);
    }

    fclose(file);
}

double calculateCPUPercentage(CPUUsage *prev, CPUUsage *curr) {
    long prevIdle = prev->idle + prev->iowait;
    long currIdle = curr->idle + curr->iowait;
    
    long prevNonIdle = prev->user + prev->nice + prev->system + prev->irq + prev->softirq;
    long currNonIdle = curr->user + curr->nice + curr->system + curr->irq + curr->softirq;
    
    long prevTotal = prevIdle + prevNonIdle;
    long currTotal = currIdle + currNonIdle;

    long totalDiff = currTotal - prevTotal;
    long idleDiff = currIdle - prevIdle;

    return (totalDiff == 0) ? 0.0 : (totalDiff - idleDiff) * 100.0 / totalDiff;
}

void *monitorCPU(void *arg) {
    CPUUsage prevUsage = {0};
    CPUUsage currUsage = {0};

    while (1) {
        getCPUUsage(&currUsage);
        double cpuUsagePercentage = calculateCPUPercentage(&prevUsage, &currUsage);

        printf("\rCPU Usage: %.2f%%    ", cpuUsagePercentage);
        fflush(stdout);

        prevUsage = currUsage;
        usleep(1000000);  // Sleep for 1 second
    }

    return NULL;
}

int main() {
    pthread_t cpu_thread;

    // Create a thread to monitor CPU usage
    if (pthread_create(&cpu_thread, NULL, monitorCPU, NULL)) {
        perror("Error creating thread");
        return EXIT_FAILURE;
    }

    // Join the CPU monitor thread
    pthread_join(cpu_thread, NULL);

    return EXIT_SUCCESS;
}