//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SAMPLES 10
#define SAMPLE_INTERVAL 1 // in seconds

int main() {
    int i;
    double total_cpu_usage = 0.0;
    double current_cpu_usage = 0.0;
    double cpu_usage[NUM_SAMPLES];

    FILE *fp;
    char filename[50];

    for (i = 0; i < NUM_SAMPLES; i++) {
        cpu_usage[i] = 0.0;
    }

    // Get current CPU usage
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Cannot open /proc/stat!\n");
        exit(1);
    }

    fscanf(fp, "cpu %lf %lf %lf %lf", &total_cpu_usage, &current_cpu_usage, &current_cpu_usage, &current_cpu_usage);

    fclose(fp);

    // Print current CPU usage
    printf("Current CPU usage: %.2f%%\n", current_cpu_usage);

    // Monitor CPU usage
    for (i = 0; i < NUM_SAMPLES; i++) {
        sleep(SAMPLE_INTERVAL);

        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            printf("Error: Cannot open /proc/stat!\n");
            exit(1);
        }

        fscanf(fp, "cpu %lf %lf %lf %lf", &total_cpu_usage, &current_cpu_usage, &current_cpu_usage, &current_cpu_usage);

        fclose(fp);

        cpu_usage[i] = current_cpu_usage;

        printf("CPU usage at %d seconds: %.2f%%\n", i+1, cpu_usage[i]);
    }

    return 0;
}