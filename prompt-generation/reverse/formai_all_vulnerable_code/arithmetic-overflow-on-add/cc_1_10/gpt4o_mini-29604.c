//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

#define CPU_USAGE_FILE "/proc/stat"
#define SAMPLE_INTERVAL 1

typedef struct CPUUsage {
    long user;
    long nice;
    long system;
    long idle;
    long iowait;
    long irq;
    long softirq;
    long steal;
    long total;
} CPUUsage;

void readCPUUsage(CPUUsage *cpu) {
    FILE *fp = fopen(CPU_USAGE_FILE, "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        exit(EXIT_FAILURE);
    }
    
    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);
    
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld", 
           &cpu->user,
           &cpu->nice,
           &cpu->system,
           &cpu->idle,
           &cpu->iowait,
           &cpu->irq,
           &cpu->softirq,
           &cpu->steal);
           
    cpu->total = cpu->user + cpu->nice + cpu->system + cpu->idle +
                 cpu->iowait + cpu->irq + cpu->softirq + cpu->steal;
                 
    fclose(fp);
}

void displayCPUUsage(CPUUsage *start, CPUUsage *end) {
    long idleDiff = end->idle - start->idle;
    long totalDiff = end->total - start->total;
    double usage = 1.0 - (double)idleDiff / (double)totalDiff;

    printf("CPU Usage: %.2f%%\n", usage * 100);
}

int main() {
    CPUUsage startUsage, endUsage;
    
    while (1) {
        readCPUUsage(&startUsage);
        sleep(SAMPLE_INTERVAL);
        readCPUUsage(&endUsage);
        
        displayCPUUsage(&startUsage, &endUsage);
        
        printf("Monitoring CPU usage...\n");
    }
    
    return 0;
}