//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define NUM_SAMPLES 10

struct sample {
    double cpu_usage;
    time_t timestamp;
};

double get_cpu_usage() {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Error opening /proc/stat");
        exit(1);
    }

    int total_ticks, idle_ticks, user_ticks, system_ticks;
    if (fscanf(file, "cpu %d %d %d %d", &total_ticks, &idle_ticks, &user_ticks, &system_ticks)!= 4) {
        fprintf(stderr, "Error parsing /proc/stat\n");
        exit(1);
    }

    double cpu_usage = (100.0 * (total_ticks - idle_ticks)) / (total_ticks + 1);
    fclose(file);
    return cpu_usage;
}

int main() {
    struct sample samples[NUM_SAMPLES];
    int num_samples = 0;

    time_t start_time = time(NULL);

    while (num_samples < NUM_SAMPLES) {
        struct sample sample = { get_cpu_usage(), time(NULL) };
        samples[num_samples++] = sample;
        sleep(1);
    }

    double avg_cpu_usage = 0.0;
    for (int i = 0; i < NUM_SAMPLES; i++) {
        avg_cpu_usage += samples[i].cpu_usage;
    }
    avg_cpu_usage /= NUM_SAMPLES;

    printf("Average CPU usage over the last %d seconds: %.2f%%\n", NUM_SAMPLES, avg_cpu_usage);

    return 0;
}