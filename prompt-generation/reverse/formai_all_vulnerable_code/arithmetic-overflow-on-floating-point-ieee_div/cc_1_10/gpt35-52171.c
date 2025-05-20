//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// function to calculate CPU utilization
float calculate_cpu_utilization(unsigned long long int* idle_time, unsigned long long int* total_time) {
    float cpu_utilization;
    unsigned long long int new_idle_time, new_total_time, idle, total;

    // read the current values from /proc/stat
    FILE* fp = fopen("/proc/stat","r");
    fscanf(fp,"%*s %llu %llu %llu %llu %llu %llu %llu",&new_total_time, &idle, &idle, &idle, &idle, &idle, &new_idle_time);
    fclose(fp);

    // calculate the difference in idle time and total time since we last checked
    total = new_total_time - *total_time;
    idle = new_idle_time - *idle_time;

    // calculate the cpu utilization percentage
    cpu_utilization = (total - idle) * 100.0 / total;

    // update the idle and total time
    *idle_time = new_idle_time;
    *total_time = new_total_time;

    return cpu_utilization;
}

int main() {
    unsigned long long int idle_time, total_time;
    float cpu_utilization;
    time_t current_time, start_time;

    // read the initial values from /proc/stat
    FILE* fp = fopen("/proc/stat","r");
    fscanf(fp,"%*s %llu %llu %llu %llu %llu %llu %llu",&total_time, &idle_time, &idle_time, &idle_time, &idle_time, &idle_time, &idle_time);
    fclose(fp);

    // get the start time
    time(&start_time);

    while(1) {
        // calculate the current CPU utilization
        cpu_utilization = calculate_cpu_utilization(&idle_time, &total_time);

        // get current time
        time(&current_time);

        // print the CPU utilization and time
        printf("CPU utilization: %.2f%%\t\tTime: %s", cpu_utilization, ctime(&current_time));

        // sleep for 1 second
        sleep(1);
    }

    return 0;
}