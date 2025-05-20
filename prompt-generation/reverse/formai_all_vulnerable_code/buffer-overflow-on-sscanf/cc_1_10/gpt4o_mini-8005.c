//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define BUFFER_SIZE 1024

void get_cpu_usage(double *cpu_usage) {
    FILE *fp;
    char buffer[BUFFER_SIZE];

    // Open the /proc/stat file to read CPU information
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    // Process the information to compute CPU usage
    long user, nice, system, idle, iowait, irq, softirq, steal;
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
    
    // Total CPU time
    long total = user + nice + system + idle + iowait + irq + softirq + steal;
    long total_idle = idle + iowait;

    // Calculating CPU usage percentage
    *cpu_usage = 100.0 * (total - total_idle) / total;
}

void display_cpu_usage() {
    double cpu_usage;
    printf("🚀 CPU Usage Monitor 🚀\n");
    printf("--------------------------------\n");

    while (1) {
        get_cpu_usage(&cpu_usage);
        printf("\rCurrent CPU Usage: %.2f%%", cpu_usage);
        fflush(stdout); // Ensure the output is printed immediately
        sleep(1); // Update every second
    }
}

int main() {
    printf("🖥️ Welcome to the CPU Usage Monitor! 🖥️\n");
    printf("Let's keep an eye on that CPU! 🔍\n");

    display_cpu_usage();

    return 0; // Never reached but good practice
}