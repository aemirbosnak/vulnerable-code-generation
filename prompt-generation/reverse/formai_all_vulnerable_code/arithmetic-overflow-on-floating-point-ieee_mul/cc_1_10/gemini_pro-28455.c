//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

// Get CPU usage in percentage
float get_cpu_usage() {
    FILE *fp;
    char line[1024];
    char *p;
    float cpu_usage;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        return -1;
    }

    fgets(line, sizeof(line), fp);
    p = line;
    p += 5;  // Skip "cpu "
    sscanf(p, "%f", &cpu_usage);
    fclose(fp);
    
    return cpu_usage;
}

int main() {
    struct timeval start, end;
    float elapsed_time, cpu_usage_start, cpu_usage_end, cpu_usage;

    // Get start time and CPU usage
    gettimeofday(&start, NULL);
    cpu_usage_start = get_cpu_usage();

    // Sleep for 1 second
    sleep(1);

    // Get end time and CPU usage
    gettimeofday(&end, NULL);
    cpu_usage_end = get_cpu_usage();

    // Calculate elapsed time and CPU usage
    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    cpu_usage = (cpu_usage_end - cpu_usage_start) / elapsed_time * 100;

    // Print CPU usage
    printf("CPU usage: %.2f%%\n", cpu_usage);

    return 0;
}