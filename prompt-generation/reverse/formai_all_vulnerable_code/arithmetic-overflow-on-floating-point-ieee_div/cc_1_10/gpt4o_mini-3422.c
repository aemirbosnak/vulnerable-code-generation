//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>

volatile sig_atomic_t stop;
void handle_sigint(int signo) {
    stop = 1;
}

typedef struct {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;
} cpu_usage_t;

void read_cpu_usage(cpu_usage_t *cpu_usage) {
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    
    fscanf(file, "cpu %llu %llu %llu %llu %llu %llu %llu %llu", 
           &cpu_usage->user, 
           &cpu_usage->nice, 
           &cpu_usage->system, 
           &cpu_usage->idle, 
           &cpu_usage->iowait, 
           &cpu_usage->irq, 
           &cpu_usage->softirq, 
           &cpu_usage->steal);
    
    fclose(file);
}

double calculate_cpu_usage(cpu_usage_t *prev, cpu_usage_t *curr) {
    unsigned long long total_prev = prev->user + prev->nice + prev->system + prev->idle + 
                                     prev->iowait + prev->irq + prev->softirq + prev->steal;
    unsigned long long total_curr = curr->user + curr->nice + curr->system + curr->idle + 
                                     curr->iowait + curr->irq + curr->softirq + curr->steal;

    unsigned long long total_idle = prev->idle - curr->idle;

    unsigned long long total_used = (total_curr - total_prev) - total_idle;

    return ((double)total_used / (total_curr - total_prev)) * 100.0;
}

void *monitor_cpu_usage(void *arg) {
    int interval = *((int *)arg);
    cpu_usage_t prev, curr;
    
    read_cpu_usage(&prev);
    
    while (!stop) {
        sleep(interval);
        read_cpu_usage(&curr);
        
        double usage = calculate_cpu_usage(&prev, &curr);
        printf("CPU Usage: %.2f%%\n", usage);

        prev = curr;
    }
    return NULL;
}

int main() {
    signal(SIGINT, handle_sigint);
    
    int interval = 1;  // set the interval to monitor every 1 second
    pthread_t thread_id;

    if (pthread_create(&thread_id, NULL, monitor_cpu_usage, &interval) != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    pthread_join(thread_id, NULL);
    
    printf("Monitoring stopped.\n");
    return EXIT_SUCCESS;
}