//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

#define MAX_CPUS 32

void get_cpu_usage(double *cpu_usage, int num_cpus) {
    FILE *file;
    char line[256];
    long unsigned int user, nice, system, idle, iowait, irq, softirq, total;
    
    if (!(file = fopen("/proc/stat", "r"))) {
        perror("Could not open /proc/stat");
        return;
    }

    // Read the first line
    fgets(line, sizeof(line), file);
    sscanf(line, "cpu %lu %lu %lu %lu %lu %lu %lu %lu", 
           &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    fclose(file);

    total = user + nice + system + idle + iowait + irq + softirq;
    *cpu_usage = ((double)(total - idle) / total) * 100;
}

void print_usage(double *cpu_usages, int num_cpus) {
    printf("\nCPU Usage:\n");
    for (int i = 0; i < num_cpus; i++) {
        printf("CPU %d: %.2f%%\n", i, cpu_usages[i]);
    }
    printf("\n");
}

int main() {
    int num_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    double cpu_usages[MAX_CPUS] = {0};

    if (num_cpus > MAX_CPUS) {
        fprintf(stderr, "Error: More CPUs than expected!\n");
        num_cpus = MAX_CPUS;
    }

    while (1) {
        // Get CPU usage for each CPU
        for (int i = 0; i < num_cpus; i++) {
            get_cpu_usage(&cpu_usages[i], num_cpus);
        }

        print_usage(cpu_usages, num_cpus);

        // Sleep for 1 second
        sleep(1);

        // Clear the console for next update
        printf("\033[H\033[J");
        
        // Notify the user to exit
        printf("Press Ctrl+C to exit the program...\n");
    }

    return 0;
}