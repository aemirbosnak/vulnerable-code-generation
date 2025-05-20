//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Get CPU usage in milliseconds
int get_cpu_usage() {
    FILE *fp;
    char buffer[1024];
    int user, nice, system, idle, iowait, irq, softirq, steal;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        return -1;
    }

    // Read the first line of the file
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        perror("Error reading from /proc/stat");
        fclose(fp);
        return -1;
    }

    // Parse the line
    if (sscanf(buffer, "cpu %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal) != 8) {
        perror("Error parsing /proc/stat");
        fclose(fp);
        return -1;
    }

    fclose(fp);

    // Calculate the CPU usage in milliseconds
    int total = user + nice + system + idle + iowait + irq + softirq + steal;
    int idle_time = idle + iowait;
    int busy_time = total - idle_time;
    int cpu_usage = (busy_time * 1000) / total;

    return cpu_usage;
}

int main(int argc, char **argv) {
    // Get the CPU usage every second
    while (1) {
        int cpu_usage = get_cpu_usage();
        printf("CPU usage: %d%%\n", cpu_usage);
        sleep(1);
    }

    return 0;
}