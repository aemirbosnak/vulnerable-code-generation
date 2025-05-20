//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>
#include <signal.h>
#include <string.h>

#define SAMPLE_INTERVAL 1
#define SAMPLE_COUNT 60

// Function to calculate CPU usage
void calculate_cpu_usage(double *cpu_usage) {
    FILE *file;
    unsigned long long int total_user, total_user_nice, total_system, total_idle, total_iowait, total_steal, total_softirq;
    unsigned long long int total;
    static unsigned long long int prev_total = 0, prev_idle = 0;

    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line
    fscanf(file, "cpu %llu %llu %llu %llu %llu %llu %llu", 
           &total_user, &total_user_nice, &total_system, 
           &total_idle, &total_iowait, &total_steal, &total_softirq);
    fclose(file);

    total = total_user + total_user_nice + total_system + total_idle + total_iowait + total_steal + total_softirq;

    if (prev_total != 0) {
        unsigned long long int total_delta = total - prev_total;
        unsigned long long int idle_delta = total_idle - prev_idle;
        *cpu_usage = 100.0 * (total_delta - idle_delta) / total_delta;
    }

    prev_total = total;
    prev_idle = total_idle;
}

// Signal handler for graceful shutdown
void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("\nMonitor stopped. Exiting program.\n");
        exit(0);
    }
}

int main() {
    signal(SIGINT, signal_handler);
    
    double cpu_usage;
    time_t start_time, current_time;

    printf("Starting CPU Usage Monitor...\n");
    printf("Monitoring CPU usage for %d seconds with %d second intervals...\n", SAMPLE_COUNT, SAMPLE_INTERVAL);
    
    start_time = time(NULL);
    
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        calculate_cpu_usage(&cpu_usage);
        time(&current_time);
        
        printf("Time: %sCPU Usage: %.2f%%\n", ctime(&current_time), cpu_usage);
        
        sleep(SAMPLE_INTERVAL);
    }

    printf("Monitoring complete. Exiting program.\n");
    return 0;
}