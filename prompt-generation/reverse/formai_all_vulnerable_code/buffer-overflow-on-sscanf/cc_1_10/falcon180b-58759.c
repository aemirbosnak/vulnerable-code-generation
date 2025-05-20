//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SAMPLES 100

struct sample {
    double cpu_usage;
    time_t timestamp;
};

double get_cpu_usage() {
    FILE *fp;
    char line[1024];
    double idle, total;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Unable to open /proc/stat\n");
        exit(1);
    }

    if (fgets(line, sizeof(line), fp) == NULL) {
        printf("Error: Unable to read /proc/stat\n");
        exit(1);
    }

    sscanf(line, "cpu %lu %lu %lu %lu", &total, &idle, &idle, &idle);

    fclose(fp);

    return (total - idle) / total;
}

int main() {
    int i, j, num_samples = 0;
    double cpu_usage, avg_cpu_usage = 0.0;
    struct sample samples[MAX_SAMPLES];
    time_t start_time, end_time, curr_time;

    start_time = time(NULL);

    while (num_samples < MAX_SAMPLES) {
        curr_time = time(NULL);
        if (difftime(curr_time, start_time) >= 1) {
            cpu_usage = get_cpu_usage();
            samples[num_samples].cpu_usage = cpu_usage;
            samples[num_samples].timestamp = curr_time;
            num_samples++;
            start_time = curr_time;
        }
        usleep(100000); // Sleep for 0.1 seconds
    }

    printf("CPU usage samples:\n");
    for (i = 0; i < num_samples; i++) {
        printf("Timestamp: %s\n", ctime(&samples[i].timestamp));
        printf("CPU usage: %.2f%%\n\n", samples[i].cpu_usage * 100.0);
    }

    avg_cpu_usage = 0.0;
    for (i = 0; i < num_samples; i++) {
        avg_cpu_usage += samples[i].cpu_usage;
    }
    avg_cpu_usage /= num_samples;

    printf("Average CPU usage: %.2f%%\n", avg_cpu_usage * 100.0);

    return 0;
}