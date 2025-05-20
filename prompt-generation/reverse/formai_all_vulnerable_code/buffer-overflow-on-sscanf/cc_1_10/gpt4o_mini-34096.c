//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/sysinfo.h>
#include <time.h>

volatile sig_atomic_t running = 1;

void handle_signal(int sig) {
    running = 0;
}

void calculate_cpu_usage(double *usage) {
    FILE *fp;
    long double idle, total;

    fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer) - 1, fp);
    fclose(fp);

    long double user, nice, system, iowait, irq, softirq, steal;
    sscanf(buffer, "cpu %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf",
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);

    total = user + nice + system + iowait + irq + softirq + steal + idle;
    
    *usage = (total - idle) / total * 100.0;
}

void print_usage(double usage) {
    printf("Current CPU Usage: %.2lf%%\n", usage);
}

void monitor_cpu_usage() {
    double cpu_usage;
    struct timespec sleep_time = {1, 0}; // 1 second sleep

    while (running) {
        calculate_cpu_usage(&cpu_usage);
        print_usage(cpu_usage);
        nanosleep(&sleep_time, NULL);
    }
}

int main() {
    // Signal handling for clean exit
    signal(SIGINT, handle_signal);

    printf("CPU Usage Monitor\n");
    printf("Press Ctrl+C to stop the monitor...\n");

    monitor_cpu_usage();

    printf("Monitor stopped. Exiting...\n");
    return 0;
}