//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 256
#define INTERVAL 1

typedef struct {
    long user;
    long nice;
    long system;
    long idle;
    long iowait;
    long irq;
    long softirq;
} CpuUsage;

void getCpuUsage(CpuUsage *cpuUsage) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld", 
              &cpuUsage->user, 
              &cpuUsage->nice, 
              &cpuUsage->system, 
              &cpuUsage->idle, 
              &cpuUsage->iowait, 
              &cpuUsage->irq, 
              &cpuUsage->softirq);
    }
    fclose(fp);
}

double calculateCpuUsage(CpuUsage *prev, CpuUsage *curr) {
    long totalPrev = prev->user + prev->nice + prev->system + prev->idle + prev->iowait + prev->irq + prev->softirq;
    long totalCurr = curr->user + curr->nice + curr->system + curr->idle + curr->iowait + curr->irq + curr->softirq;

    long totalIdlePrev = prev->idle;
    long totalIdleCurr = curr->idle;

    long totalDiff = totalCurr - totalPrev;
    long idleDiff = totalIdleCurr - totalIdlePrev;

    double usage = (1.0 - (double)idleDiff / totalDiff) * 100;

    return usage;
}

void *monitorCpuUsage(void *arg) {
    CpuUsage prevUsage, currUsage;

    getCpuUsage(&prevUsage);

    while (1) {
        sleep(INTERVAL);
        getCpuUsage(&currUsage);
        double cpuUsage = calculateCpuUsage(&prevUsage, &currUsage);
        printf("CPU Usage: %.2f%%\n", cpuUsage);
        prevUsage = currUsage;
    }
    return NULL;
}

int main() {
    printf("🚀 Welcome to the Enthusiastic CPU Usage Monitor! 🚀\n");
    printf("👀 Monitoring your CPU usage in real-time!\n");
    printf("Press Ctrl+C to exit the monitor.\n");

    pthread_t monitorThread;
    if (pthread_create(&monitorThread, NULL, monitorCpuUsage, NULL) != 0) {
        perror("Failed to create thread");
        return EXIT_FAILURE;
    }

    pthread_join(monitorThread, NULL);
    return 0;
}