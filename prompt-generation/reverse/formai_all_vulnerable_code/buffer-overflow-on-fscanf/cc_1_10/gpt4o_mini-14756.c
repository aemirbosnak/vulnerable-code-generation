//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>
#include <signal.h>

#define SAMPLE_INTERVAL 1
#define MAX_SAMPLES 60

volatile sig_atomic_t stop_monitoring = 0;

void handle_signal(int sig) {
    stop_monitoring = 1;
}

void print_usage(double usage) {
    printf("\rCPU Usage: %.2f%%", usage);
    fflush(stdout);
}

double calculate_cpu_usage() {
    FILE *fp;
    unsigned long long idle_time, total_time, prev_idle_time, prev_total_time;

    fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "cpu %*s %*s %*s %llu %*s %*s %*s %*s", &idle_time);
    fclose(fp);
    
    total_time = 0;
    fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    
    unsigned long long user, nice, system, idle, iowait, irq, softirq, steal;
    fscanf(fp, "cpu %llu %llu %llu %llu %llu %llu %llu %llu", 
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
    
    fclose(fp);
    
    total_time = user + nice + system + idle + iowait + irq + softirq + steal;
    
    double usage = ((double)(total_time - idle_time) / total_time) * 100;
    
    return usage;
}

void monitor_cpu_usage() {
    signal(SIGINT, handle_signal);

    printf("Starting CPU Usage Monitor...\n");
    printf("Press Ctrl+C to stop monitoring.\n");

    // Monitor CPU usage for MAX_SAMPLES seconds
    for(int i = 0; i < MAX_SAMPLES && !stop_monitoring; ++i) {
        double cpu_usage = calculate_cpu_usage();
        print_usage(cpu_usage);

        // Sleep for the specified interval
        sleep(SAMPLE_INTERVAL);
    }

    printf("\nMonitoring stopped.\n");
}

int main() {
    monitor_cpu_usage();
    return EXIT_SUCCESS;
}