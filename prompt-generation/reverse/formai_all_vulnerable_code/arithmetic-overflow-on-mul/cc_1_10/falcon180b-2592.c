//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TOTAL_NUM_PROCESSES 1024
#define DELTA_TIME 5

int main() {
    int num_processes = 0;
    int process_ids[TOTAL_NUM_PROCESSES];
    char process_names[TOTAL_NUM_PROCESSES][16];
    int i, j, k;
    int max_cpu_usage = 0;
    int max_cpu_usage_pid = 0;
    int max_cpu_usage_time = 0;
    int current_time = 0;
    int prev_time = 0;
    int cpu_usage_time = 0;
    float cpu_percentage = 0.0;

    // Get the number of processes running
    FILE* fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }
    fscanf(fp, "cpu %d", &num_processes);
    fclose(fp);

    // Get the process IDs and names
    for (i = 0; i < num_processes; i++) {
        sprintf(process_names[i], "process_%d", i);
        process_ids[i] = i;
    }

    // Open /proc/stat for reading
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    // Read the first line of /proc/stat
    fscanf(fp, "cpu %d", &num_processes);

    // Loop through the rest of the lines in /proc/stat
    while (fscanf(fp, "cpu%d %d %d %d %d", &i, &j, &k, &j, &k) == 5) {
        // Calculate the CPU usage for each process
        for (int l = 0; l < num_processes; l++) {
            cpu_usage_time = ((j - prev_time) * 100) / DELTA_TIME;
            cpu_percentage = (float)cpu_usage_time / (float)DELTA_TIME * 100.0;
            if (cpu_percentage > max_cpu_usage) {
                max_cpu_usage = cpu_percentage;
                max_cpu_usage_pid = process_ids[l];
                max_cpu_usage_time = cpu_usage_time;
            }
            printf("%s: %d%%\n", process_names[l], cpu_percentage);
        }
        prev_time = j;
    }

    fclose(fp);

    // Print the process with the highest CPU usage
    printf("Process with highest CPU usage: %s (%d)\n", process_names[max_cpu_usage_pid], max_cpu_usage_time);

    return 0;
}