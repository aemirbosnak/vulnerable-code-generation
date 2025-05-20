//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/sysinfo.h>
#include <stdbool.h>

#define CPUINFO_FILE "/proc/stat"
#define BUFFER_SIZE 256

volatile sig_atomic_t keep_running = true;

void intHandler(int sig) {
    keep_running = false;
}

void get_cpu_usage(float *usage) {
    FILE *file = fopen(CPUINFO_FILE, "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        *usage = -1.0;
        return;
    }

    char line[BUFFER_SIZE];
    if (fgets(line, sizeof(line), file) == NULL) {
        perror("Failed to read from /proc/stat");
        fclose(file);
        *usage = -1.0;
        return;
    }

    fclose(file);

    long user, nice, system, idle, iowait, irq, softirq;
    sscanf(line, "cpu %ld %ld %ld %ld %ld %ld %ld",
           &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    long total = user + nice + system + idle + iowait + irq + softirq;
    long active = total - idle;

    *usage = (float)active / total * 100.0;
}

void display_cpu_usage() {
    float usage;
    get_cpu_usage(&usage);

    if (usage < 0) {
        printf("Error fetching CPU usage\n");
        return;
    }

    printf("Current CPU Usage: %.2f%%\n", usage);
}

int main() {
    signal(SIGINT, intHandler);

    printf("Starting CPU Usage Monitor...\n");
    printf("Press Ctrl+C to exit.\n");

    while (keep_running) {
        display_cpu_usage();
        sleep(1);
    }

    printf("Exiting CPU Usage Monitor...\n");
    return 0;
}