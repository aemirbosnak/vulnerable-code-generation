//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <pthread.h>

#define NUM_THREADS 2 // Number of threads to be created

// Struct for CPU state information
typedef struct {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;
    unsigned long long guest;
    unsigned long long guest_nice;
} cpu_state;

// Struct for thread arguments
typedef struct {
    int id; // Thread ID
    cpu_state *prev_cpu;
} thread_args;

// Function to calculate CPU usage percentage
float calculate_cpu_usage(cpu_state *prev, cpu_state *current) {
    unsigned long long prev_idle, current_idle, prev_total, current_total;
    float usage;

    prev_idle = prev->idle + prev->iowait;
    current_idle = current->idle + current->iowait;
    prev_total = prev->user + prev->nice + prev->system + prev->irq + prev->softirq + prev->steal;
    current_total = current->user + current->nice + current->system + current->irq + current->softirq + current->steal;
    usage = (float)(current_total - prev_total) / (current_total + current_idle - prev_total - prev_idle) * 100;

    return usage;
}

void *thread_func(void *args) {
    thread_args *t_args = (thread_args *)args;
    cpu_state *prev_cpu, *current_cpu;

    prev_cpu = (cpu_state *)malloc(sizeof(cpu_state));
    current_cpu = (cpu_state *)malloc(sizeof(cpu_state));

    // Get initial CPU state
    FILE *stat_file = fopen("/proc/stat", "r");
    fscanf(stat_file, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
            &prev_cpu->user, &prev_cpu->nice, &prev_cpu->system, &prev_cpu->idle, &prev_cpu->iowait,
            &prev_cpu->irq, &prev_cpu->softirq, &prev_cpu->steal, &prev_cpu->guest, &prev_cpu->guest_nice);
    fclose(stat_file);

    while (1) {
        usleep(500000); // Sleep for 500 milliseconds

        // Get current CPU state
        stat_file = fopen("/proc/stat", "r");
        fscanf(stat_file, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
                &current_cpu->user, &current_cpu->nice, &current_cpu->system, &current_cpu->idle, &current_cpu->iowait,
                &current_cpu->irq, &current_cpu->softirq, &current_cpu->steal, &current_cpu->guest, &current_cpu->guest_nice);
        fclose(stat_file);

        // Calculate and print CPU usage percentage
        printf("Thread %d: %.1f%%\n", t_args->id, calculate_cpu_usage(prev_cpu, current_cpu));

        // Copy current CPU state to previous CPU state for next iteration
        memcpy(t_args->prev_cpu, current_cpu, sizeof(cpu_state));
    }

    free(prev_cpu);
    free(current_cpu);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_args t_args[NUM_THREADS];
    cpu_state prev_cpu_main;

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        t_args[i].id = i;
        t_args[i].prev_cpu = &prev_cpu_main;
        pthread_create(&threads[i], NULL, thread_func, (void *)&t_args[i]);
    }

    // Get initial CPU state for main thread
    FILE *stat_file = fopen("/proc/stat", "r");
    fscanf(stat_file, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
            &prev_cpu_main.user, &prev_cpu_main.nice, &prev_cpu_main.system, &prev_cpu_main.idle, &prev_cpu_main.iowait,
            &prev_cpu_main.irq, &prev_cpu_main.softirq, &prev_cpu_main.steal, &prev_cpu_main.guest, &prev_cpu_main.guest_nice);
    fclose(stat_file);

    // Wait for threads to exit
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}