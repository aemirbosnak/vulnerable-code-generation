//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#define NUM_SAMPLES 10
#define SAMPLE_INTERVAL 1 // in seconds

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    if (pid <= 0) {
        fprintf(stderr, "Invalid PID\n");
        return 1;
    }

    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage)!= 0) {
        fprintf(stderr, "Failed to get initial CPU usage\n");
        return 1;
    }

    double total_cpu_time[NUM_SAMPLES] = {0};
    int i;
    for (i = 0; i < NUM_SAMPLES; i++) {
        sleep(SAMPLE_INTERVAL);
        if (getrusage(RUSAGE_SELF, &usage)!= 0) {
            fprintf(stderr, "Failed to get CPU usage for sample %d\n", i+1);
            return 1;
        }
        total_cpu_time[i] = (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) +
                             (usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1000000.0;
    }

    double avg_cpu_time = 0;
    for (i = 0; i < NUM_SAMPLES; i++) {
        avg_cpu_time += total_cpu_time[i];
    }
    avg_cpu_time /= NUM_SAMPLES;

    double cpu_usage = 100 - ((avg_cpu_time / (double)SAMPLE_INTERVAL) * 100);

    printf("Average CPU usage for PID %d is %.2f%%\n", pid, cpu_usage);

    return 0;
}