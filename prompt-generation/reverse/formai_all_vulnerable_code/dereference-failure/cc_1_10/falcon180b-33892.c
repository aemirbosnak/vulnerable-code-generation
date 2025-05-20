//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <pthread.h>

// Define the number of CPUs
#define NUM_CPUS 4

// Define the time interval for CPU usage monitoring (in seconds)
#define TIME_INTERVAL 5

// Define the structure for storing CPU usage information
typedef struct {
    int cpu_number;
    float cpu_usage;
} cpu_usage_t;

// Function for getting CPU usage
void *get_cpu_usage(void *arg) {
    int cpu_number = *(int *) arg;
    cpu_usage_t *cpu_usage = (cpu_usage_t *) malloc(sizeof(cpu_usage_t));

    while (1) {
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        cpu_usage->cpu_usage = (float) usage.ru_utime.tv_sec + (float) usage.ru_utime.tv_usec / 1000000;
        cpu_usage->cpu_number = cpu_number;
        printf("CPU %d usage: %.2f%%\n", cpu_number, cpu_usage->cpu_usage * 100);
        sleep(TIME_INTERVAL);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_CPUS];

    // Create threads for monitoring CPU usage
    for (int i = 0; i < NUM_CPUS; i++) {
        pthread_create(&threads[i], NULL, get_cpu_usage, (void *) &i);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_CPUS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}