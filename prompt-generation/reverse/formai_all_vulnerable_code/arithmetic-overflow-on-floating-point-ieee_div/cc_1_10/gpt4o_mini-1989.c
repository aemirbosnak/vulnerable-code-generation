//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <string.h>

#define NUM_THREADS 2
#define MONITOR_INTERVAL 2 // in seconds

pthread_mutex_t lock;
float cpu_usage = 0.0;
float mem_usage = 0.0;

void* monitor_cpu(void* arg) {
    while (1) {
        // Simulating CPU usage retrieval, normally you'd pull from /proc/stat or similar
        FILE *fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            perror("Error opening /proc/stat");
            return NULL;
        }

        char line[256];
        if (fgets(line, sizeof(line), fp)) {
            char cpu[5];
            long user, nice, system, idle;
            sscanf(line, "%s %ld %ld %ld %ld", cpu, &user, &nice, &system, &idle);
            long total = user + nice + system + idle;
            cpu_usage = (float)(total - idle) / total * 100;
        }
        fclose(fp);
        
        pthread_mutex_lock(&lock);
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        pthread_mutex_unlock(&lock);
        
        sleep(MONITOR_INTERVAL);
    }
    return NULL;
}

void* monitor_memory(void* arg) {
    while (1) {
        // Getting total and free memory
        struct sysinfo memInfo;
        sysinfo(&memInfo);
        long total_mem = memInfo.totalram;
        long free_mem = memInfo.freeram;
        mem_usage = (float)(total_mem - free_mem) / total_mem * 100;

        pthread_mutex_lock(&lock);
        printf("Memory Usage: %.2f%%\n", mem_usage);
        pthread_mutex_unlock(&lock);
        
        sleep(MONITOR_INTERVAL);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    
    // Mutex initialization
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("Mutex initialization failed");
        return 1;
    }
    
    // Create threads for CPU and Memory monitoring
    if (pthread_create(&threads[0], NULL, monitor_cpu, NULL) != 0) {
        perror("Failed to create CPU monitor thread");
        return 1;
    }
    if (pthread_create(&threads[1], NULL, monitor_memory, NULL) != 0) {
        perror("Failed to create Memory monitor thread");
        return 1;
    }
    
    // Wait for threads to finish (they won't, as they run forever)
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Mutex destroy (cleanup, not reached in this example)
    pthread_mutex_destroy(&lock);
    return 0;
}