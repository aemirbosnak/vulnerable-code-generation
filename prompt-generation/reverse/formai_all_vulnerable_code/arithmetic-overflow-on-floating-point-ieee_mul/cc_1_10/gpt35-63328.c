//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 128
#define SAMPLES 10

double sample_cpu_usage() {
    char buf[BUF_SIZE];
    FILE *fp;
    double user, nice, sys, idle, iowait, irq, sirq;
    double cpu_usage;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    fgets(buf, BUF_SIZE, fp);

    sscanf(buf, "cpu %lf %lf %lf %lf %lf %lf %lf", &user, &nice, &sys, &idle, &iowait, &irq, &sirq);

    fclose(fp);

    static double prev_idle = 0, prev_total = 0;
    double total = user + nice + sys + idle + iowait + irq + sirq;
    double idle_diff = idle - prev_idle;
    double total_diff = total - prev_total;
    cpu_usage = 100 * (1 - (idle_diff / total_diff));

    prev_idle = idle;
    prev_total = total;

    return cpu_usage;
}

int main() {
    double cpu_usage_samples[SAMPLES];
    double cpu_usage_avg;
    int i;

    printf("CPU Usage Monitor\n\n");

    for (i = 0; i < SAMPLES; i++) {
        cpu_usage_samples[i] = sample_cpu_usage();
        printf("Sample %d: CPU Usage = %.2f%%\n", i+1, cpu_usage_samples[i]);
        sleep(1);
    }

    cpu_usage_avg = 0;
    for (i = 0; i < SAMPLES; i++) {
        cpu_usage_avg += cpu_usage_samples[i];
    }
    cpu_usage_avg /= SAMPLES;

    printf("\nAverage CPU Usage = %.2f%%\n", cpu_usage_avg);

    return 0;
}