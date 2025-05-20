//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <pthread.h>

#define INTERVAL 1
#define MAX_SAMPLES 100

typedef struct {
    double usage_data[MAX_SAMPLES];
    int count;
    pthread_mutex_t lock;
    int running;
} RamUsageData;

RamUsageData ram_data = {.count = 0, .lock = PTHREAD_MUTEX_INITIALIZER, .running = 1};

void capture_ram_usage() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        // Gets total and free memory
        double total_ram = info.totalram;
        double free_ram = info.freeram;
        double used_ram = total_ram - free_ram;

        pthread_mutex_lock(&ram_data.lock);
        if (ram_data.count < MAX_SAMPLES) {
            ram_data.usage_data[ram_data.count++] = (used_ram / total_ram) * 100.0; // Store usage percentage
        }
        pthread_mutex_unlock(&ram_data.lock);
    } else {
        perror("sysinfo");
    }
}

void* monitor_ram_usage(void* arg) {
    while (ram_data.running) {
        capture_ram_usage();
        sleep(INTERVAL);
    }
    return NULL;
}

void display_ram_usage() {
    pthread_mutex_lock(&ram_data.lock);
    printf("\nRAM Usage Percentage:\n");
    for (int i = 0; i < ram_data.count; i++) {
        printf("Sample %d: %.2f%%\n", i + 1, ram_data.usage_data[i]);
    }
    pthread_mutex_unlock(&ram_data.lock);
}

void handle_signals(int signal) {
    if (signal == SIGINT) {
        printf("\nStopping RAM usage monitor...\n");
        ram_data.running = 0;
    }
    if (signal == SIGUSR1) {
        display_ram_usage();
    }
}

int main() {
    signal(SIGINT, handle_signals);
    signal(SIGUSR1, handle_signals);
    
    pthread_t monitor_thread;
    if (pthread_create(&monitor_thread, NULL, monitor_ram_usage, NULL) != 0) {
        perror("Failed to create monitor thread");
        return EXIT_FAILURE;
    }

    // Main loop waits for signals
    while (ram_data.running) {
        pause(); // Wait for signals to be handled
    }

    pthread_join(monitor_thread, NULL);
    display_ram_usage();

    return EXIT_SUCCESS;
}