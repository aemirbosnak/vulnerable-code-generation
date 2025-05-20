//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <pthread.h>

#define MAX_LOAD 10
#define SLEEP_INTERVAL 1  // Interval in seconds for updates

volatile sig_atomic_t keep_monitoring = 1;

void handle_sigint(int signum) {
    keep_monitoring = 0; // Stop monitoring on Ctrl+C
}

double get_cpu_usage() {
    static long prev_idle = 0, prev_total = 0;
    long idle, total;
    FILE *fp = fopen("/proc/stat", "r");

    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        fclose(fp);
        return -1;
    }

    fclose(fp);

    long user, nice, system, iowait, irq, softirq, steal, guest, guest_nice;
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
        &user, &nice, &system, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

    idle = iowait + irq + softirq + steal + guest + guest_nice;
    total = user + nice + system + idle;

    double usage = 0.0;
    if (prev_total != 0) {
        long total_delta = total - prev_total;
        long idle_delta = idle - prev_idle;
        usage = 1.0 - (idle_delta / (double) total_delta);
    }

    prev_idle = idle;
    prev_total = total;

    return usage * 100;
}

void* monitor_cpu(void* arg) {
    while (keep_monitoring) {
        double usage = get_cpu_usage();
        if (usage < 0) {
            fprintf(stderr, "Error getting CPU usage\n");
            return NULL;
        }

        printf("\rCPU Usage: %.2f%%", usage);
        fflush(stdout);
        sleep(SLEEP_INTERVAL);
    }
    return NULL;
}

void display_info() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        printf("System Information:\n");
        printf("Uptime: %ld seconds\n", info.uptime);
        printf("Number of processes: %d\n", info.procs);
        printf("Total RAM: %ld MB\n", info.totalram / (1024 * 1024));
        printf("Free RAM: %ld MB\n", info.freeram / (1024 * 1024));
    } else {
        perror("sysinfo");
    }
}

int main() {
    // Register signal handler for graceful shutdown
    signal(SIGINT, handle_sigint);

    printf("Starting CPU usage monitor...\n");
    display_info();
    
    pthread_t monitor_thread;
    if (pthread_create(&monitor_thread, NULL, monitor_cpu, NULL) != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    // Wait for the monitoring thread to finish when signaled to stop
    pthread_join(monitor_thread, NULL);

    printf("\nExiting CPU usage monitor.\n");
    return EXIT_SUCCESS;
}