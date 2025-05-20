//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <pthread.h>
#include <signal.h>

#define NUM_THREADS 5
#define INTERVAL 2

volatile sig_atomic_t stop;
pthread_mutex_t lock;

void handle_sigint(int sig) {
    stop = 1;
}

void* cpu_usage_monitor(void* arg) {
    while (!stop) {
        struct sysinfo sys_info;
        if (sysinfo(&sys_info) == 0) {
            long total_time = sys_info.uptime;
            long free_mem = sys_info.freeram / (1024 * 1024);
            long total_mem = sys_info.totalram / (1024 * 1024);
            double cpu_usage = ((total_time - free_mem) / (double)total_time) * 100;

            pthread_mutex_lock(&lock);
            printf("CPU Usage: %.2f%%, Free Memory: %ld MB, Total Memory: %ld MB\n", cpu_usage, free_mem, total_mem);
            pthread_mutex_unlock(&lock);
        } else {
            perror("sysinfo");
        }
        sleep(INTERVAL);
    }
    return NULL;
}

void* memory_usage_monitor(void* arg) {
    while (!stop) {
        struct sysinfo sys_info;
        if (sysinfo(&sys_info) == 0) {
            long used_mem = (sys_info.totalram - sys_info.freeram) / (1024 * 1024);
            pthread_mutex_lock(&lock);
            printf("Used Memory: %ld MB\n", used_mem);
            pthread_mutex_unlock(&lock);
        } else {
            perror("sysinfo");
        }
        sleep(INTERVAL);
    }
    return NULL;
}

void* uptime_monitor(void* arg) {
    while (!stop) {
        struct sysinfo sys_info;
        if (sysinfo(&sys_info) == 0) {
            pthread_mutex_lock(&lock);
            printf("System Uptime: %ld seconds\n", sys_info.uptime);
            pthread_mutex_unlock(&lock);
        } else {
            perror("sysinfo");
        }
        sleep(INTERVAL);
    }
    return NULL;
}

void* load_average_monitor(void* arg) {
    while (!stop) {
        double loadavg[3];
        if (getloadavg(loadavg, 3) != -1) {
            pthread_mutex_lock(&lock);
            printf("Load Average: 1min: %.2f, 5min: %.2f, 15min: %.2f\n", loadavg[0], loadavg[1], loadavg[2]);
            pthread_mutex_unlock(&lock);
        } else {
            perror("getloadavg");
        }
        sleep(INTERVAL);
    }
    return NULL;
}

int main() {
    signal(SIGINT, handle_sigint);
    pthread_t threads[NUM_THREADS];
    
    pthread_mutex_init(&lock, NULL);

    if (pthread_create(&threads[0], NULL, cpu_usage_monitor, NULL) != 0) {
        perror("Failed to create CPU monitor thread");
        return EXIT_FAILURE;
    }
    if (pthread_create(&threads[1], NULL, memory_usage_monitor, NULL) != 0) {
        perror("Failed to create Memory monitor thread");
        return EXIT_FAILURE;
    }
    if (pthread_create(&threads[2], NULL, uptime_monitor, NULL) != 0) {
        perror("Failed to create Uptime monitor thread");
        return EXIT_FAILURE;
    }
    if (pthread_create(&threads[3], NULL, load_average_monitor, NULL) != 0) {
        perror("Failed to create Load Average monitor thread");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join threads");
        }
    }
    
    pthread_mutex_destroy(&lock);
    printf("Monitoring stopped.\n");
    return EXIT_SUCCESS;
}