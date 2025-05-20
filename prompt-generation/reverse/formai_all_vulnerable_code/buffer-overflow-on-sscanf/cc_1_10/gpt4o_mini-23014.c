//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <time.h>

// Function to read the CPU usage from /proc/stat
void get_cpu_usage(float *user, float *nice, float *system, float *idle) {
    FILE *fp;
    char buffer[256];
    long u, n, s, id, iowait, irq, softirq;
    
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld", &u, &n, &s, &id, &iowait, &irq, &softirq);
    fclose(fp);

    *user = (float)u;
    *nice = (float)n;
    *system = (float)s;
    *idle = (float)id;
}

// Function to calculate CPU usage percentage
float calculate_cpu_usage(float old_user, float old_nice, float old_system, float old_idle, 
                          float new_user, float new_nice, float new_system, float new_idle) {
    float total_old = old_user + old_nice + old_system + old_idle;
    float total_new = new_user + new_nice + new_system + new_idle;

    float used_old  = total_old - old_idle;
    float used_new  = total_new - new_idle;

    return ((used_new - used_old) / (total_new - total_old)) * 100.0f;
}

int main() {
    float old_user, old_nice, old_system, old_idle;
    float new_user, new_nice, new_system, new_idle;
    struct timespec req = {1, 0};  // 1 second sleep time

    // Initial CPU values
    get_cpu_usage(&old_user, &old_nice, &old_system, &old_idle);

    printf("Monitoring CPU usage...\n");
    printf("-------------------------------------\n");
    printf("%-10s %-10s %-10s\n", "Usage", "User", "System");
    printf("-------------------------------------\n");

    while (1) {
        // Perform sleep for specified time
        nanosleep(&req, NULL);

        // Fetch new CPU values
        get_cpu_usage(&new_user, &new_nice, &new_system, &new_idle);

        // Calculate usage percentage
        float cpu_usage = calculate_cpu_usage(old_user, old_nice, old_system, old_idle, 
                                               new_user, new_nice, new_system, new_idle);

        // Print CPU usage details
        printf("%-10.2f %-10.2f %-10.2f\n", cpu_usage, new_user, new_system);

        // Update old values for next iteration
        old_user = new_user;
        old_nice = new_nice;
        old_system = new_system;
        old_idle = new_idle;
    }
    
    return 0;
}