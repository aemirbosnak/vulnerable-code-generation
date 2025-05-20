//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <unistd.h>
#define INTERVAL 1

/* Function to calculate the CPU usage percentage */
float calculate_cpu_usage(unsigned long long int idle_time, unsigned long long int total_time) {
    float cpu_usage = 100.0 - (((float)idle_time * 100.0) / (float)total_time);
    return cpu_usage;
}

int main() {
    /* Initializing the variables */
    unsigned long long int prev_idle_time = 0, prev_total_time = 0;
    unsigned long long int idle_time = 0, total_time = 0;
    char cpu_usage_text[10];

    while(1) {
        /* Opening the /proc/stat file to read the CPU utilization stats */
        FILE* stat_file = fopen("/proc/stat", "r");
        if(stat_file == NULL) {
            printf("Error in opening the stat file!\n");
            return -1;
        }

        /* Skipping the "cpu" word in the first line */
        char cpu_name[10];
        fscanf(stat_file, "%s", cpu_name);

        /* Reading the CPU utilization stats */
        unsigned long long int user_time, nice_time, system_time, idle, iowait, irq, softirq, steal, guest, guest_nice;
        fscanf(stat_file, "%llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &user_time, &nice_time, &system_time, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

        /* Closing the stat file */
        fclose(stat_file);

        /* Calculating the total CPU time and idle time */
        idle_time = idle + iowait;
        total_time = user_time + nice_time + system_time + idle_time + irq + softirq + steal;
        
        if(prev_idle_time != 0 && prev_total_time != 0) {
            /* Calculating the CPU usage percentage */
            float cpu_usage = calculate_cpu_usage((idle_time - prev_idle_time), (total_time - prev_total_time));

            /* Updating the terminal text */
            snprintf(cpu_usage_text, sizeof(cpu_usage_text), "%.2f %%", cpu_usage);
            printf("CPU Usage: %s\n", cpu_usage_text);
        }

        /* Updating the previous idle time and total time */
        prev_idle_time = idle_time;
        prev_total_time = total_time;

        /* Waiting for the specified interval */
        sleep(INTERVAL);
    }

    return 0;
}