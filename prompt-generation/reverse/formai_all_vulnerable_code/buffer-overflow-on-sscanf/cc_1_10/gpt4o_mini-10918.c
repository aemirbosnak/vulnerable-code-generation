//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <pthread.h>
#include <signal.h>

#define MAX_LINE_LENGTH 256
#define UPDATE_INTERVAL 1  // seconds

typedef struct {
    double total_cpu_usage;
    double idle_cpu_percentage;
    double usage_percentage;
} CPUUsage;

CPUUsage cpu_usage = {0.0, 0.0, 0.0};
volatile int running = 1;

void signal_handler(int signal) {
    if (signal == SIGINT) {
        running = 0;
    }
}

void *calculate_cpu_usage(void *arg) {
    while (running) {
        // Read the file /proc/stat
        FILE *fp = fopen("/proc/stat", "r");
        if (!fp) {
            perror("Failed to read /proc/stat");
            return NULL;
        }

        char line[MAX_LINE_LENGTH];
        if (fgets(line, sizeof(line), fp) != NULL) {
            // Parsing the CPU usage statistics
            char cpu_label[5];
            int user, nice, system, idle, iowait, irq, softirq, total;

            sscanf(line, "%s %d %d %d %d %d %d %d", cpu_label, &user, &nice, &system, &idle, &iowait, &irq, &softirq);
            total = user + nice + system + idle + iowait + irq + softirq;

            // Calculate the usage
            cpu_usage.idle_cpu_percentage = (double) idle / total * 100.0;
            cpu_usage.usage_percentage = 100.0 - cpu_usage.idle_cpu_percentage;
            cpu_usage.total_cpu_usage = total;

            printf("User CPU Usage: %.2f%%\n", cpu_usage.usage_percentage);
        }
        
        fclose(fp);
        sleep(UPDATE_INTERVAL); // Wait for the defined interval
    }
    return NULL;
}

void print_usage() {
    printf("CPU Usage Monitor\n");
    printf("Press Ctrl+C to stop the monitor.\n");
}

int main() {
    signal(SIGINT, signal_handler); // Catch SIGINT (Ctrl+C)

    pthread_t cpu_thread;
    print_usage();

    if (pthread_create(&cpu_thread, NULL, calculate_cpu_usage, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    pthread_join(cpu_thread, NULL); // Wait for the thread to finish
    printf("\nExiting...\n");
    return 0;
}