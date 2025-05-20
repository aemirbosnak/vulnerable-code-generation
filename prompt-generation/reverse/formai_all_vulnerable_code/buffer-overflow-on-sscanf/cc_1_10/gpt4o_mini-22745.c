//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 128

// Function to read the CPU statistics
void read_cpu_stats(long *user, long *nice, long *system, long *idle) {
    FILE *fp;
    char buffer[BUFFER_SIZE];

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Could not open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line
    fgets(buffer, BUFFER_SIZE, fp);
    sscanf(buffer, "cpu %ld %ld %ld %ld", user, nice, system, idle);

    fclose(fp);
}

// Function to calculate CPU usage
double calculate_cpu_usage(long old_user, long old_nice, long old_system, long old_idle,
                            long new_user, long new_nice, long new_system, long new_idle) {
    long total_old = old_user + old_nice + old_system + old_idle;
    long total_new = new_user + new_nice + new_system + new_idle;

    long total_diff = total_new - total_old;
    long idle_diff = new_idle - old_idle;

    return 100.0 * (total_diff - idle_diff) / total_diff;
}

int main() {
    long user1, nice1, system1, idle1;
    long user2, nice2, system2, idle2;

    // Initial read
    read_cpu_stats(&user1, &nice1, &system1, &idle1);
    sleep(1); // Wait for 1 second

    while (1) {
        // Read CPU stats again
        read_cpu_stats(&user2, &nice2, &system2, &idle2);
        
        // Calculate CPU usage
        double cpu_usage = calculate_cpu_usage(user1, nice1, system1, idle1, 
                                                user2, nice2, system2, idle2);

        // Display CPU usage
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        
        // Update previous values
        user1 = user2;
        nice1 = nice2;
        system1 = system2;
        idle1 = idle2;

        // Sleep for a while to limit the output frequency
        sleep(1);
    }

    return 0;
}