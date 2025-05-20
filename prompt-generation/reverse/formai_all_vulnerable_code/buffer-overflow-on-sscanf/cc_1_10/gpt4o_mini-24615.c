//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

volatile int running = 1;

void* cpu_usage_monitor(void* arg) {
    char buffer[256];
    unsigned long user, nice, sys, idle, iowait, irq, softirq, steal, total, idle_time, last_total, last_idle;
    double usage;

    last_total = 0;
    last_idle = 0;

    while (running) {
        FILE *fp = fopen("/proc/stat", "r");
        if (!fp) {
            perror("Failed to open /proc/stat");
            exit(EXIT_FAILURE);
        }
        if (fgets(buffer, sizeof(buffer), fp)) {
            sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu %lu %lu", 
                   &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal);
                   
            total = user + nice + sys + idle + iowait + irq + softirq + steal;
            idle_time = idle;

            if (last_total > 0 && last_idle > 0) {
                usage = 100.0 * (1.0 - (double)(idle_time - last_idle) / (double)(total - last_total));
                printf("\rCPU Usage: %.2f%%", usage);
                fflush(stdout);
            }

            last_total = total;
            last_idle = idle_time;
        }
        fclose(fp);
        usleep(100000); // Sleep for 100 ms
    }
    return NULL;
}

void* user_input_listener(void* arg) {
    char command;
    while (running) {
        command = getchar();
        if (command == 'q' || command == 'Q') {
            running = 0;
        }
    }
    return NULL;
}

int main() {
    pthread_t monitor_thread, input_thread;

    // Create the CPU usage monitor thread
    if (pthread_create(&monitor_thread, NULL, cpu_usage_monitor, NULL)) {
        fprintf(stderr, "Error creating CPU monitor thread\n");
        return EXIT_FAILURE;
    }

    // Create the input listener thread
    if (pthread_create(&input_thread, NULL, user_input_listener, NULL)) {
        fprintf(stderr, "Error creating input listener thread\n");
        return EXIT_FAILURE;
    }

    // Wait for the threads to finish
    pthread_join(monitor_thread, NULL);
    pthread_join(input_thread, NULL);

    printf("\nMonitoring stopped. Exiting program.\n");
    return EXIT_SUCCESS;
}