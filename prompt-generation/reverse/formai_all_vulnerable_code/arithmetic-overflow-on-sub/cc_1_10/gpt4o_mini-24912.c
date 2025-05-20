//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>

#define MAX_CPUS 128
#define SAMPLE_INTERVAL 1 // in seconds
#define BUFFER_SIZE 1024

typedef struct {
    int cpu_id;
    double usage_percentage;
} CPUInfo;

void get_cpu_usage(CPUInfo *cpu_info, int *num_cpus) {
    FILE *fp;
    char line[BUFFER_SIZE];
    *num_cpus = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) && *num_cpus < MAX_CPUS) {
        if (strncmp(line, "cpu", 3) == 0) {
            int user, nice, system, idle, iowait, irq, softirq, steal;
            sscanf(line, "cpu%d %d %d %d %d %d %d %d %d",
                   &cpu_info[*num_cpus].cpu_id,
                   &user, &nice, &system, &idle,
                   &iowait, &irq, &softirq, &steal);

            int total_time = user + nice + system + idle + iowait + irq + softirq + steal;
            cpu_info[*num_cpus].usage_percentage = 100.0 * (total_time - idle) / total_time;
            (*num_cpus)++;
        }
    }
    
    fclose(fp);
}

void display_cpu_usage(CPUInfo *cpu_info, int num_cpus) {
    printf("\n");
    printf("CPU Usage Monitor\n");
    printf("-------------------\n");
    for (int i = 0; i < num_cpus; i++) {
        printf("CPU %d: %.2f%%\n", cpu_info[i].cpu_id, cpu_info[i].usage_percentage);
    }
    printf("\n");
}

int main() {
    int num_cpus = 0;
    CPUInfo cpu_info[MAX_CPUS];
    time_t start_time, current_time;

    while (1) {
        start_time = time(NULL);
        get_cpu_usage(cpu_info, &num_cpus);
        display_cpu_usage(cpu_info, num_cpus);
        
        current_time = time(NULL);
        while (difftime(current_time, start_time) < SAMPLE_INTERVAL) {
            current_time = time(NULL);
            // To create a futuristic feel, simply sleep for a brief moment
            usleep(50000); // Sleep for 50 milliseconds
        }
    }
    
    return 0;
}