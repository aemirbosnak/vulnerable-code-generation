//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>

#define MAX_CPUS 16
#define SLEEP_DURATION 1

typedef struct {
    int cpu_id;
    double usage_percentage;
    struct timespec last_time;
} CPUInfo;

CPUInfo cpu_info[MAX_CPUS];
volatile sig_atomic_t stop_flag = 0;

void handle_signal(int signal) {
    stop_flag = 1;
}

void *cpu_monitor(void *args) {
    int cpu_id = *(int *)args;
    char filepath[40];
    char line[256];
    unsigned long long total_jiffies1, total_jiffies2;
    unsigned long long idle_jiffies1, idle_jiffies2;
    
    while (!stop_flag) {
        FILE *file;
        sprintf(filepath, "/proc/stat");
        
        file = fopen(filepath, "r");
        if (!file) {
            perror("Failed to open /proc/stat");
            return NULL;
        }

        // Read lines for processor information
        for (int i = 0; i < MAX_CPUS + 1; i++) {
            fgets(line, sizeof(line), file);
            if (i == 0) {
                continue; // Skip the first line (cpu)
            }

            if (i == cpu_id) {
                sscanf(line, "cpu%d %*s %*s %*s %llu %llu %*s %*s %*s", 
                       &cpu_id, &idle_jiffies1, &total_jiffies1);
                break;
            }
        }
        fclose(file);
        
        total_jiffies1 += idle_jiffies1; // Add idle jiffies just got
        sleep(SLEEP_DURATION);
        
        file = fopen(filepath, "r");
        if (!file) {
            perror("Failed to open /proc/stat");
            return NULL;
        }

        for (int i = 0; i < MAX_CPUS + 1; i++) {
            fgets(line, sizeof(line), file);
            if (i == 0) {
                continue; // Skip first line
            }

            if (i == cpu_id) {
                sscanf(line, "cpu%d %*s %*s %*s %llu %llu %*s %*s %*s", 
                       &cpu_id, &idle_jiffies2, &total_jiffies2);
                break;
            }
        }
        fclose(file);

        total_jiffies2 += idle_jiffies2;
        double usage = (1.0 - ((double)(idle_jiffies2 - idle_jiffies1) / (double)(total_jiffies2 - total_jiffies1))) * 100.0;
        cpu_info[cpu_id].usage_percentage = usage;
        
        clock_gettime(CLOCK_MONOTONIC, &cpu_info[cpu_id].last_time);
    }
    
    return NULL;
}

void display_usage() {
    printf("\nCPU Usage Monitor:\n");
    for (int i = 0; i < MAX_CPUS; i++) {
        if (cpu_info[i].usage_percentage >= 0) {
            printf("CPU %d Usage: %.2f%%\n", i, cpu_info[i].usage_percentage);
        }
    }
    printf("\nPress Ctrl+C to end monitoring...\n");
}

int main() {
    signal(SIGINT, handle_signal);
    
    pthread_t threads[MAX_CPUS];
    int cpu_ids[MAX_CPUS];
    
    for (int i = 0; i < MAX_CPUS; i++) {
        cpu_ids[i] = i;
        cpu_info[i].cpu_id = i;
        cpu_info[i].usage_percentage = -1; // Initialize to -1 to indicate unused
        pthread_create(&threads[i], NULL, cpu_monitor, &cpu_ids[i]);
    }

    while (!stop_flag) {
        display_usage();
        sleep(SLEEP_DURATION);
    }

    for (int i = 0; i < MAX_CPUS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nMonitoring stopped. Exiting...\n");
    return 0;
}