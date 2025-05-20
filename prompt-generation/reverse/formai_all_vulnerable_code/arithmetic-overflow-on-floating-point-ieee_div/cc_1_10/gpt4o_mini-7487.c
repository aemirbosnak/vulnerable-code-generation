//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 128

void get_cpu_usage(float *usage) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    unsigned long total_user, total_user_nice, total_sys, total_idle, total_iowait, total_steal;
    unsigned long total;

    file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to read /proc/stat");
        exit(EXIT_FAILURE);
    }
    
    fgets(buffer, BUFFER_SIZE, file);
    fclose(file);

    sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu %lu",
           &total_user, &total_user_nice, &total_sys, &total_idle,
           &total_iowait, &total_steal);

    total = total_user + total_user_nice + total_sys + total_idle + total_iowait + total_steal;

    // Calculating the CPU usage
    // Total time used = total - idle time
    unsigned long total_time = total_user + total_user_nice + total_sys;
    unsigned long idle_time = total_idle;

    *usage = (float)(total_time) / (float)(total) * 100.0f;
}

void display_usage(float usage) {
    printf("\rCPU Usage: %.2f%%", usage);
    fflush(stdout);
}

int main() {
    float cpu_usage;

    printf("Welcome to the CPU Usage Monitor!\n");
    printf("Press Ctrl+C to exit the program.\n");

    while (1) {
        get_cpu_usage(&cpu_usage);
        display_usage(cpu_usage);
        sleep(1);
    }

    return 0;
}