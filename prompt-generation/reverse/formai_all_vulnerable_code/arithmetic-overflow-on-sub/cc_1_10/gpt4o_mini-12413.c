//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define CPU_INFO_PATH "/proc/stat"
#define SAMPLE_INTERVAL 1 // in seconds

typedef struct {
    long user;
    long nice;
    long system;
    long idle;
    long iowait;
    long irq;
    long softirq;
    long steal;
    long guest;
    long guest_nice;
} CPUInfo;

CPUInfo get_cpu_info() {
    CPUInfo cpu_info = {0};
    FILE *file = fopen(CPU_INFO_PATH, "r");
    if (file) {
        char buffer[256];
        fgets(buffer, sizeof(buffer), file); // Read the first line
        sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
               &cpu_info.user, &cpu_info.nice, &cpu_info.system,
               &cpu_info.idle, &cpu_info.iowait, &cpu_info.irq,
               &cpu_info.softirq, &cpu_info.steal, &cpu_info.guest,
               &cpu_info.guest_nice);
        fclose(file);
    }
    return cpu_info;
}

void calculate_cpu_usage(CPUInfo old_info, CPUInfo new_info, double *usage) {
    long total_old = old_info.user + old_info.nice + old_info.system + old_info.idle + 
                     old_info.iowait + old_info.irq + old_info.softirq + old_info.steal;
    long total_new = new_info.user + new_info.nice + new_info.system + new_info.idle + 
                     new_info.iowait + new_info.irq + new_info.softirq + new_info.steal;

    long usage_diff = (total_new - total_old) - (new_info.idle - old_info.idle);
    long total_diff = total_new - total_old;

    if (total_diff > 0) {
        *usage = (double)usage_diff / total_diff * 100.0;
    } else {
        *usage = 0.0;
    }
}

void *cpu_monitor(void *args) {
    CPUInfo old_info = get_cpu_info();
    double usage = 0.0;

    while (1) {
        sleep(SAMPLE_INTERVAL);
        CPUInfo new_info = get_cpu_info();
        calculate_cpu_usage(old_info, new_info, &usage);
        old_info = new_info;
        
        printf("CPU Usage: %.2f%%\n", usage);
    }
    return NULL;
}

int main() {
    pthread_t monitor_thread;

    if (pthread_create(&monitor_thread, NULL, cpu_monitor, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return EXIT_FAILURE;
    }
    
    // Main thread could perform other tasks or handle user input
    while (1) {
        // In a real application, you'd probably allow clean exit
        sleep(100);
    }

    // Clean up (though unreachable here)
    pthread_join(monitor_thread, NULL);
    return EXIT_SUCCESS;
}