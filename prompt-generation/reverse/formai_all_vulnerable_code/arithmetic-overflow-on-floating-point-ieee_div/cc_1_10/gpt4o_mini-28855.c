//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void print_gratitude(void) {
    printf("========================================\n");
    printf("  Thank you for using the CPU Monitor!  \n");
    printf("   We appreciate your system's hard work! \n");
    printf("========================================\n\n");
}

void get_cpu_usage(float *cpu_usage, float *total_time, float *idle_time) {
    FILE *fp;
    char buffer[1024];
    char cpu[5];
    unsigned long long user, nice, system, idle, iowait, irq, softirq, steal;

    *total_time = 0;
    *idle_time = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "%s %llu %llu %llu %llu %llu %llu %llu %llu", 
           cpu, &user, &nice, &system, &idle, 
           &iowait, &irq, &softirq, &steal);

    fclose(fp);

    *total_time = user + nice + system + idle + iowait + irq + softirq + steal;
    *idle_time = idle;

    *cpu_usage = 100.0 * (1 - (*idle_time / *total_time));
}

int main(void) {
    print_gratitude();

    while (1) {
        float cpu_usage = 0.0;
        float total_time = 0.0;
        float idle_time = 0.0;

        get_cpu_usage(&cpu_usage, &total_time, &idle_time);

        printf("Current CPU Usage: %.2f%%\n", cpu_usage);
        printf("Total Time: %.0f jiffy(s)\n", total_time);
        printf("Idle Time: %.0f jiffy(s)\n", idle_time);
        printf("----------------------------------------\n");

        sleep(2);
    }

    return 0;
}