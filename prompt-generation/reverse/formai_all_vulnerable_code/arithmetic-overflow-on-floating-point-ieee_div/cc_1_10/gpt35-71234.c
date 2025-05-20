//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define INTERVAL 1 // Interval (in seconds) between CPU usage checks

volatile int keepRunning = 1; // Flag to keep the program running

// Signal handler to stop the program when the user presses Ctrl+C
void intHandler(int dummy) {
    keepRunning = 0;
}

// Function to get the CPU usage percentage
float getCpuUsage() {
    FILE* file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Error opening /proc/stat");
        exit(1);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);

    // Format: cpu  user  nice  system  idle  iowait  irq  softirq  steal  guest  guest_nice
    long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

    // Calculation of CPU usage percentage
    long prev_idle = idle - (guest + guest_nice);
    long prev_non_idle = user + nice + system + irq + softirq + steal;
    long prev_total = prev_idle + prev_non_idle;

    sleep(INTERVAL); // Wait for INTERVAL seconds before checking CPU usage again

    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Error opening /proc/stat");
        exit(1);
    }

    fgets(buffer, sizeof(buffer), file);
    fclose(file);

    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

    long idle_delta = idle - (guest + guest_nice) - prev_idle;
    long total_delta = (idle - (guest + guest_nice) + user + nice + system + irq + softirq + steal) - prev_total;

    return ((float)total_delta / (float)(total_delta + idle_delta)) * 100.0;
}

// Asynchronous CPU usage monitor function
void* monitorCpuUsageAsync(void* arg) {
    while (keepRunning) { // Keep monitoring until the user presses Ctrl+C
        printf("CPU usage : %.2f%%\n", getCpuUsage());
    }
    pthread_exit(NULL);
}

int main() {
    signal(SIGINT, intHandler); // Register the signal handler for Ctrl+C

    pthread_t thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&thread, &attr, monitorCpuUsageAsync, NULL); // Start the async monitor function

    while (keepRunning)
        sleep(1); // Sleep the main thread and keep it alive

    pthread_join(thread, NULL); // Wait for the async thread to finish before exiting
    printf("Program stopped.\n");
    return 0;
}