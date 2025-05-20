//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/sysinfo.h>
#include <signal.h>

volatile sig_atomic_t stop_signal = 0;

void handle_sigint(int sig) {
    stop_signal = 1;
}

void get_cpu_usage(double *cpu_usage) {
    FILE *fp;
    char buffer[1024];
    long double a[4], b[4];
    static long double prev_idle, prev_total;

    // Open the file to read CPU usage information
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line that starts with 'cpu'
    fscanf(fp, "%s %Lf %Lf %Lf %Lf", buffer, &a[0], &a[1], &a[2], &a[3]);
    fclose(fp);

    // Calculate total and idle CPU time
    long double total = a[0] + a[1] + a[2] + a[3];
    long double idle = a[3];

    // Calculate the CPU usage
    double total_delta = total - prev_total;
    double idle_delta = idle - prev_idle;

    if (total_delta > 0) {
        *cpu_usage = (total_delta - idle_delta) / total_delta * 100.0;
    } else {
        *cpu_usage = 0.0;
    }

    // Store the current values for the next calculation
    prev_idle = idle;
    prev_total = total;
}

void *monitor_cpu_usage(void *interval) {
    double cpu_usage;
    int sleep_time = *((int *)interval);

    while (!stop_signal) {
        get_cpu_usage(&cpu_usage);
        printf("Current CPU Usage: %.2f%%\n", cpu_usage);
        fflush(stdout);
        sleep(sleep_time);
    }
    return NULL;
}

int main() {
    signal(SIGINT, handle_sigint);

    int interval = 1; // Default interval in seconds
    printf("CPU Usage Monitor (Press Ctrl+C to stop)\n");

    // Create a thread for monitoring CPU usage
    pthread_t monitor_thread;

    // Create the thread to monitor CPU usage
    if (pthread_create(&monitor_thread, NULL, monitor_cpu_usage, &interval) != 0) {
        perror("Failed to create thread");
        exit(EXIT_FAILURE);
    }

    // Wait for the monitor thread to finish
    pthread_join(monitor_thread, NULL);

    printf("CPU Usage Monitor stopped.\n");
    return 0;
}