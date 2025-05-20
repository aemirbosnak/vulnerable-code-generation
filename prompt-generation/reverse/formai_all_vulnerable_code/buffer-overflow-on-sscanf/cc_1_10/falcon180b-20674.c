//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define NUM_SAMPLES 100
#define SAMPLE_INTERVAL 1

struct sample {
    double cpu_usage;
    time_t timestamp;
};

double get_cpu_usage() {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        return -1;
    }

    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        fclose(fp);
        return -1;
    }

    double total = 0, idle = 0;
    sscanf(line, "cpu %lu %lu %lu %lu", &total, &idle, NULL, NULL);

    fclose(fp);
    return (100.0 - idle) / total * 100.0;
}

int main() {
    struct sample samples[NUM_SAMPLES];
    int i;

    for (i = 0; i < NUM_SAMPLES; ++i) {
        samples[i].cpu_usage = get_cpu_usage();
        samples[i].timestamp = time(NULL);

        if (samples[i].cpu_usage == -1) {
            printf("Error getting CPU usage\n");
            exit(1);
        }

        sleep(SAMPLE_INTERVAL);
    }

    printf("Timestamp\tCPU Usage (%)\n");
    for (i = 0; i < NUM_SAMPLES; ++i) {
        printf("%ld\t%.2f\n", samples[i].timestamp, samples[i].cpu_usage);
    }

    return 0;
}