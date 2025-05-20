//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NUM_PROCESSES 10
#define MAX_LINE_LENGTH 256

int parse_cpu_usage(const char *line) {
    int user_time, nice_time, system_time, idle_time;
    
    // Scan the line for relevant times
    if (sscanf(line, "cpu  %d %d %d %d", &user_time, &nice_time, &system_time, &idle_time) != 4) {
        return -1;
    }
    
    // Calculate total usage and return it (excluding idle time)
    return user_time + nice_time + system_time;
}

void display_usage(int *cpu_usage) {
    printf("CPU Usage Monitor:\n");
    printf("CPU Utilization:\n");
    
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("CPU #%d: %d%%\n", i, cpu_usage[i]);
    }
    printf("\n");
}

void read_cpu_usage(int *cpu_usage) {
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int index = 0;

    // Read relevant lines, limiting to NUM_PROCESSES
    while (fgets(line, sizeof(line), file) && index < NUM_PROCESSES) {
        if (strncmp(line, "cpu", 3) == 0) {
            cpu_usage[index] = parse_cpu_usage(line);
            index++;
        }
    }
    fclose(file);
}

void calculate_usage(int *prev_usage, int *current_usage, float *cpu_percents) {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (prev_usage[i] != 0) {
            cpu_percents[i] = ((float)(current_usage[i] - prev_usage[i])) / prev_usage[i] * 100;
        } else {
            cpu_percents[i] = 0;
        }
    }
}

void monitor_cpu() {
    int prev_usage[NUM_PROCESSES] = {0};
    int current_usage[NUM_PROCESSES];
    float cpu_percents[NUM_PROCESSES];

    while (1) {
        read_cpu_usage(current_usage);
        
        // If we have valid previous usage, calculate the usage percentage
        if (prev_usage[0] != 0) {
            calculate_usage(prev_usage, current_usage, cpu_percents);
            display_usage((int *)cpu_percents);
        }
        
        // Update previous usage for the next iteration
        memcpy(prev_usage, current_usage, sizeof(prev_usage));
        
        // Sleep for a second
        sleep(1);
    }
}

int main() {
    printf("=== Welcome to the CPU Usage Monitor ===\n");
    monitor_cpu();
    
    return 0;
}