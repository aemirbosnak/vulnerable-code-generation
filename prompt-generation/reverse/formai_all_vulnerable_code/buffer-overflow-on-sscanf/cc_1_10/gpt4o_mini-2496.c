//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to read the CPU usage from the /proc/stat file
float calculate_cpu_usage() {
    FILE *fp;
    char buffer[1024];
    unsigned long long int user, nice, system, idle, iowait, irq, softirq, steal;
    unsigned long long int total, prev_total, prev_idle, total_diff, idle_diff;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to read /proc/stat");
        return -1;
    }

    // Read the first line containing CPU information
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    // Parse the CPU statistics from the line
    sscanf(buffer, "cpu  %llu %llu %llu %llu %llu %llu %llu %llu", 
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);

    total = user + nice + system + idle + iowait + irq + softirq + steal;

    // Calculate idle time and total time
    idle_diff = idle;
    total_diff = total;

    // The CPU usage percentage calculation
    return 100.0 * (1.0 - (double)idle_diff / total_diff);
}

// The main function to serve as the brain of this little mystery
int main() {
    printf("Welcome to the CPU Usage Monitor, inspired by the indomitable spirit of Sherlock Holmes.\n");
    printf("We are about to delve into the enigmatic realm of CPU utilization.\n\n");

    float current_usage = 0;
    // Initial run to establish a reference point
    current_usage = calculate_cpu_usage();

    if (current_usage < 0) {
        return 1;
    }

    printf("Initial CPU usage: %.2f%%\n\n", current_usage);

    while (1) {
        sleep(1); // Wait for 1 second before checking again

        float new_usage = calculate_cpu_usage();
        if (new_usage < 0) {
            return 1;
        }

        // Display the found CPU usage results in a dramatic, Holmes-esque fashion
        printf("Elementary, dear Watson! Current CPU usage: %.2f%%\n", new_usage);
        
        if (new_usage > current_usage) {
            printf("Aha! The CPU is working harder than before, a most curious case...\n");
        } else if (new_usage < current_usage) {
            printf("Indeed, the CPU has moments of tranquility, what a relief!\n");
        } else {
            printf("Ah, a steady state! The CPU maintains its composure.\n");
        }

        current_usage = new_usage; // Update for next round
    }

    return 0;
}