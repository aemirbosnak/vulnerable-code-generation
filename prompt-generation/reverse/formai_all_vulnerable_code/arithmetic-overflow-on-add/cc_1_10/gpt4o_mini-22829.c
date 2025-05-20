//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define READ_BUFFER_SIZE 256
#define CPU_INFO_FILE "/proc/stat"

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
} CPUUsage;

// Function to read the CPU statistics from /proc/stat
CPUUsage read_cpu_usage() {
    CPUUsage cpu_usage;

    FILE *file = fopen(CPU_INFO_FILE, "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[READ_BUFFER_SIZE];
    if (fgets(buffer, READ_BUFFER_SIZE, file) == NULL) {
        perror("Failed to read from /proc/stat");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);

    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
           &cpu_usage.user, &cpu_usage.nice, &cpu_usage.system,
           &cpu_usage.idle, &cpu_usage.iowait, &cpu_usage.irq,
           &cpu_usage.softirq, &cpu_usage.steal, &cpu_usage.guest,
           &cpu_usage.guest_nice);

    return cpu_usage;
}

// Function to calculate CPU usage ratio
double calculate_cpu_usage(CPUUsage previous, CPUUsage current) {
    long previous_total = previous.user + previous.nice + previous.system + 
                          previous.idle + previous.iowait + previous.irq + 
                          previous.softirq + previous.steal + previous.guest + 
                          previous.guest_nice;

    long current_total = current.user + current.nice + current.system + 
                         current.idle + current.iowait + current.irq + 
                         current.softirq + current.steal + current.guest + 
                         current.guest_nice;

    long idle_diff = current.idle - previous.idle;
    long total_diff = current_total - previous_total;

    if (total_diff == 0) {
        return 0.0;
    }

    return (1.0 - (double)idle_diff / (double)total_diff) * 100.0;
}

// Function to display the CPU usage
void print_cpu_usage(double usage) {
    printf("\rCPU Usage: %.2f%%", usage);
    fflush(stdout);
}

// Main function to monitor CPU usage
int main() {
    CPUUsage previous_cpu = read_cpu_usage();
    sleep(1); // Wait for 1 second
    CPUUsage current_cpu = read_cpu_usage();

    while (1) {
        double cpu_usage = calculate_cpu_usage(previous_cpu, current_cpu);
        print_cpu_usage(cpu_usage);
        
        previous_cpu = current_cpu; // Update previous CPU stats
        sleep(1); // Wait for 1 second
        current_cpu = read_cpu_usage(); // Get current CPU stats
    }

    return 0;
}