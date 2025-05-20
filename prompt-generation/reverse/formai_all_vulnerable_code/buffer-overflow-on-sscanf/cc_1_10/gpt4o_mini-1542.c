//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define NUM_CPU 4   // Number of CPUs to display

void get_cpu_usage(long cpu_data[NUM_CPU][4]) {
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Could not open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int cpu_index = 0;

    while (cpu_index < NUM_CPU && fgets(line, sizeof(line), file)) {
        if (sscanf(line, "cpu%d %ld %ld %ld %ld", &cpu_index, 
                   &cpu_data[cpu_index][0], 
                   &cpu_data[cpu_index][1], 
                   &cpu_data[cpu_index][2], 
                   &cpu_data[cpu_index][3]) < 5) {
            break;
        }
        cpu_index++;
    }
    fclose(file);
}

void calculate_and_display_usage(long cpu_data[NUM_CPU][4], long prev_data[NUM_CPU][4]) {
    for (int i = 0; i < NUM_CPU; i++) {
        long total_idle = cpu_data[i][3] - prev_data[i][3];
        long total_working = (cpu_data[i][0] + cpu_data[i][1] + cpu_data[i][2]) - 
                             (prev_data[i][0] + prev_data[i][1] + prev_data[i][2]);
        long total_time = total_idle + total_working;

        double usage_percent = (total_working * 100.0) / (total_time == 0 ? 1 : total_time);
        
        printf("CPU %d usage: %.2f%%\n", i, usage_percent);
    }
}

int main() {
    long cpu_data[NUM_CPU][4] = {{0}};
    long prev_data[NUM_CPU][4] = {{0}};

    while (1) {
        get_cpu_usage(cpu_data);
        if (prev_data[0][0] != 0) { // Ensure it's not the first iteration
            calculate_and_display_usage(cpu_data, prev_data);
        }
        
        // Store current data for next iteration
        memcpy(prev_data, cpu_data, sizeof(cpu_data));
        
        // Sleep for 1 second before the next update
        sleep(1);
        printf("---------------------------\n");
    }

    return 0;
}