//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUM_CPU_FIELDS 10
#define BUFFER_SIZE 1024

#define CPUSTAT_FILE "/proc/stat"

// Function to calculate CPU usage
void calculateCpuUsage(float* user_usage, float* nice_usage, float* system_usage,
                       float* idle_usage, float* total_usage) {
    FILE* fp;
    int cpu_values[NUM_CPU_FIELDS];
    int total, user, nice, system, idle;

    fp = fopen(CPUSTAT_FILE, "r");
    if(fp == NULL) {
        perror("Error opening CPU file");
        exit(EXIT_FAILURE);
    }

    // Get values from first line of CPUSTAT_FILE
    fscanf(fp, "%*s %d %d %d %d %d %d %d %d %d %d\n", &cpu_values[0],
           &cpu_values[1], &cpu_values[2], &cpu_values[3], &cpu_values[4],
           &cpu_values[5], &cpu_values[6], &cpu_values[7], &cpu_values[8],
           &cpu_values[9]);

    fclose(fp);

    // Calculate usage values
    user = cpu_values[0] - cpu_values[1];
    nice = cpu_values[2];
    system = cpu_values[3] - cpu_values[2];
    idle = cpu_values[4];
    total = user + nice + system + idle;

    *user_usage = ((float) user / total) * 100.0;
    *nice_usage = ((float) nice / total) * 100.0;
    *system_usage = ((float) system / total) * 100.0;
    *idle_usage = ((float) idle / total) * 100.0;
    *total_usage = 100.0 - *idle_usage;
}

int main() {
    float user_usage1, nice_usage1, system_usage1, idle_usage1, total_usage1;
    float user_usage2, nice_usage2, system_usage2, idle_usage2, total_usage2;
    // Clear console
    system("clear");

    printf("----CPU Usage Monitor----\n");

    while(1) {
        calculateCpuUsage(&user_usage1, &nice_usage1, &system_usage1, &idle_usage1, &total_usage1);
        usleep(1000000);
        calculateCpuUsage(&user_usage2, &nice_usage2, &system_usage2, &idle_usage2, &total_usage2);

        float total_diff = total_usage2 - total_usage1;
        float user_diff = user_usage2 - user_usage1;
        float nice_diff = nice_usage2 - nice_usage1;
        float system_diff = system_usage2 - system_usage1;

        printf("Total Usage: %.2f%%\n", total_usage2);
        printf("\tUser Usage: %.2f%%\tChange: %.2f%%\n", user_usage2, user_diff);
        printf("\tNice Usage: %.2f%%\tChange: %.2f%%\n", nice_usage2, nice_diff);
        printf("\tSystem Usage: %.2f%%\tChange: %.2f%%\n", system_usage2, system_diff);
        printf("\tIdle Usage: %.2f%%\n", idle_usage2);
        printf("\tTotal Change: %.2f%%\n", total_diff);
    }

    return 0;
}