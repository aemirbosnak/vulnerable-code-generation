//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define MAX_SAMPLES 100
#define SAMPLE_INTERVAL 1 // seconds

struct sample {
    double cpu_percent;
    time_t timestamp;
};

void get_cpu_usage(double *cpu_percent) {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    *cpu_percent = (double)usage.ru_utime.tv_sec + (double)usage.ru_stime.tv_sec;
}

void add_sample(struct sample *samples, int index, double cpu_percent, time_t timestamp) {
    if (index >= MAX_SAMPLES) {
        index = 0;
    }
    samples[index].cpu_percent = cpu_percent;
    samples[index].timestamp = timestamp;
}

double calculate_average(struct sample *samples, int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += samples[i].cpu_percent;
    }
    return sum / count;
}

int main() {
    struct sample samples[MAX_SAMPLES];
    int sample_count = 0;
    double current_cpu_percent;
    time_t current_timestamp;

    srand(time(NULL));
    for (int i = 0; i < MAX_SAMPLES; i++) {
        samples[i].cpu_percent = rand() % 101;
        samples[i].timestamp = time(NULL) - (i * SAMPLE_INTERVAL);
    }

    while (1) {
        sleep(SAMPLE_INTERVAL);
        get_cpu_usage(&current_cpu_percent);
        current_timestamp = time(NULL);

        add_sample(samples, sample_count % MAX_SAMPLES, current_cpu_percent, current_timestamp);
        sample_count++;

        printf("Current CPU usage: %.2f%%\n", current_cpu_percent);
        printf("Average CPU usage over the last %d seconds: %.2f%%\n", SAMPLE_INTERVAL, calculate_average(samples, MAX_SAMPLES));
        printf("\n");
    }

    return 0;
}