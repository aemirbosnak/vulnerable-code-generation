//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <time.h>

#define TOTAL_PROCESSORS 4
#define PROCESSOR_USAGE_THRESHOLD 75
#define SLEEP_INTERVAL 5

int main() {
    int i, j, num_processors = sysconf(_SC_NPROCESSORS_ONLN);
    struct rusage usage;
    double cpu_usage;

    if (num_processors <= 0) {
        printf("Error: Failed to get number of processors.\n");
        return 1;
    }

    if (num_processors > TOTAL_PROCESSORS) {
        num_processors = TOTAL_PROCESSORS;
    }

    printf("Welcome to the CPU Usage Monitor!\n");
    printf("Press enter to start monitoring...\n");
    getchar();

    while (1) {
        for (i = 0; i < num_processors; i++) {
            getrusage(RUSAGE_SELF, &usage);
            cpu_usage = 100.0 * (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec +
                                 (usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1000000.0) /
                       (double)SLEEP_INTERVAL;

            if (cpu_usage >= PROCESSOR_USAGE_THRESHOLD) {
                printf("\a");
            }

            for (j = 0; j < 50; j++) {
                printf("\r");
            }

            printf("[%d] CPU Usage: %.2f%%", i + 1, cpu_usage);
        }

        fflush(stdout);
        usleep(150000);
    }

    return 0;
}