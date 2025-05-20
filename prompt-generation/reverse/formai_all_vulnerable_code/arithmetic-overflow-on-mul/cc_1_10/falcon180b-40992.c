//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_CPU_USAGE 100
#define SLEEP_TIME 1
#define NUM_THREADS 5

struct cpu_usage {
    int cpu_percent;
    time_t timestamp;
};

void *monitor_cpu_usage(void *arg) {
    int cpu_percent;
    struct timespec ts;
    struct cpu_usage *usage = (struct cpu_usage *) arg;

    while (1) {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
        cpu_percent = (int) (ts.tv_sec * 100);

        if (cpu_percent > MAX_CPU_USAGE) {
            cpu_percent = MAX_CPU_USAGE;
        }

        usage->cpu_percent = cpu_percent;
        usage->timestamp = time(NULL);

        sleep(SLEEP_TIME);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct cpu_usage usage[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, monitor_cpu_usage, &usage[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}