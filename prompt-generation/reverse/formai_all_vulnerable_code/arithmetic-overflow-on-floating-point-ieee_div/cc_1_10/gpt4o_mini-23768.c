//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

#define MAX_CPU 100.0

// Function to calculate the CPU usage
double calculate_cpu_usage() {
    FILE *file;
    long double a[4], b[4];
    double loadavg;

    // Reading CPU statistics from /proc/stat
    file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Could not open /proc/stat");
        return -1;
    }

    fscanf(file, "cpu %Lf %Lf %Lf %Lf", &a[0], &a[1], &a[2], &a[3]);
    fclose(file);

    // Sleep for a second to measure CPU usage over time
    sleep(1);

    file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Could not open /proc/stat");
        return -1;
    }
    
    fscanf(file, "cpu %Lf %Lf %Lf %Lf", &b[0], &b[1], &b[2], &b[3]);
    fclose(file);

    // Calculation of CPU usage
    double total_a = a[0] + a[1] + a[2] + a[3];
    double total_b = b[0] + b[1] + b[2] + b[3];

    double total_diff = total_b - total_a;
    double idle_diff = b[3] - a[3];

    loadavg = ((total_diff - idle_diff) / total_diff) * MAX_CPU;

    return loadavg;
}

// Function to present CPU usage in a Sherlock Holmes style
void sherlock_presentation(double cpu_usage) {
    // A most gentlemanly presentation of findings
    printf("Ah, Watson! It appears the CPU is laboring quite industriously!\n");
    printf("CPU Usage: %.2f%%\n", cpu_usage);
    if(cpu_usage > 75.0) 
        printf("We must investigate further, it seems our computations are quite taxing!\n");
    else if(cpu_usage > 40.0)
        printf("A fair amount of activity, we may need to optimize our methods.\n");
    else 
        printf("Rest assured, the great detective CPU is lounging comfortably.\n");
}

// Main function to execute the CPU monitor
int main() {
    printf("Elementary, my dear Watson. The CPU usage shall now be monitored.\n");

    while (1) {
        double cpu_usage = calculate_cpu_usage();
        if (cpu_usage < 0) {
            return -1;  // Error encountered
        }
        
        sherlock_presentation(cpu_usage);

        // Pause for a moment, we wouldn't want to overwhelm our senses.
        sleep(5);
    }

    return 0;
}