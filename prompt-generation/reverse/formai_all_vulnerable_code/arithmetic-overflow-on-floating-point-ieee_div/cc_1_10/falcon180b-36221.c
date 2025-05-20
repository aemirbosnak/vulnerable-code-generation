//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <math.h>

#define MAX_NUM_SAMPLES 100

struct sample {
    double time;
    double cpu_percent;
};

double get_cpu_percent(int pid) {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        perror("getrusage");
        exit(EXIT_FAILURE);
    }
    return (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0;
}

int main(int argc, char *argv[]) {
    int num_samples = 0;
    struct sample samples[MAX_NUM_SAMPLES];
    double sum_cpu_percent = 0.0;
    double avg_cpu_percent = 0.0;
    double max_cpu_percent = 0.0;
    double min_cpu_percent = 100.0;
    int max_index = 0;
    int min_index = 0;

    pid_t pid = getpid();

    while (num_samples < MAX_NUM_SAMPLES) {
        struct timeval start_time;
        gettimeofday(&start_time, NULL);

        usleep(100000); // Sleep for 100ms

        struct timeval end_time;
        gettimeofday(&end_time, NULL);

        double time_diff = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

        double cpu_percent = get_cpu_percent(pid) / time_diff;

        samples[num_samples].time = time_diff;
        samples[num_samples].cpu_percent = cpu_percent;

        sum_cpu_percent += cpu_percent;

        if (cpu_percent > max_cpu_percent) {
            max_cpu_percent = cpu_percent;
            max_index = num_samples;
        }

        if (cpu_percent < min_cpu_percent) {
            min_cpu_percent = cpu_percent;
            min_index = num_samples;
        }

        num_samples++;
    }

    avg_cpu_percent = sum_cpu_percent / num_samples;

    printf("Average CPU usage: %.2f%%\n", avg_cpu_percent);
    printf("Maximum CPU usage: %.2f%%\n", max_cpu_percent);
    printf("Minimum CPU usage: %.2f%%\n", min_cpu_percent);

    return 0;
}