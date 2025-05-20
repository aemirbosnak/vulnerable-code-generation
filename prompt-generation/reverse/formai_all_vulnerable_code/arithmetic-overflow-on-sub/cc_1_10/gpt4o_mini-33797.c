//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>             // Include standard input/output header
#include <stdlib.h>            // Include standard library for system calls
#include <string.h>            // Include string manipulation header
#include <unistd.h>           // Include standard symbolic constants and types
#include <sys/sysinfo.h>       // Include Linux system information header
#include <time.h>              // Include time utilities header

// Define the structure for CPU usage data
typedef struct CPUUsage {
    long idle_time;          // Idle time of CPU
    long total_time;         // Total time of CPU
} CPUUsage;

// Function to calculate CPU usage
float calculate_cpu_usage(CPUUsage *prev_usage, CPUUsage *curr_usage) {
    long idle_delta = curr_usage->idle_time - prev_usage->idle_time;      // Idle time difference
    long total_delta = curr_usage->total_time - prev_usage->total_time;    // Total time difference

    if (total_delta == 0) return 0.0;  // Prevent division by zero
    return (1.0f - (float)idle_delta / (float)total_delta) * 100.0f; // CPU usage percentage
}

// Function to retrieve current CPU times
CPUUsage get_cpu_usage() {
    FILE *file = fopen("/proc/stat", "r");  // Open the /proc/stat file
    CPUUsage usage;
    
    if (file) {
        long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice; 
        fscanf(file, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld", 
               &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
        
        usage.idle_time = idle;    // Capture idle time
        usage.total_time = user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice; // Total time calculation
        
        fclose(file);             // Close the file
    } else {
        perror("Failed to open /proc/stat"); // Error handling
    }
    
    return usage;               // Return the cpu usage data
}

// Function to display CPU usage
void display_cpu_usage(float usage) {
    printf("Current CPU Usage: %.2f%%\n", usage); // Print formatted CPU usage
}

int main() {
    const int interval = 1;      // Time interval in seconds
    
    CPUUsage prev_usage = get_cpu_usage(); // Get initial CPU usage
    sleep(interval);               // Sleep for a defined interval
    CPUUsage curr_usage = get_cpu_usage(); // Get CPU usage again after the interval
    
    // Calculate CPU usage
    float cpu_usage = calculate_cpu_usage(&prev_usage, &curr_usage);
    
    // Display the calculated CPU usage
    display_cpu_usage(cpu_usage);
    
    return 0;                    // End of the program
}