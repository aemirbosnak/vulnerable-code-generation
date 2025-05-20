//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CPU_FIELDS 10
#define BUFFER_SIZE 256

void get_cpu_usage(long *idle_time, long *total_time) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    
    fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        long cpu_times[CPU_FIELDS] = {0};
        sscanf(buffer + 5, "%ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
               &cpu_times[0], &cpu_times[1], &cpu_times[2], 
               &cpu_times[3], &cpu_times[4], &cpu_times[5], 
               &cpu_times[6], &cpu_times[7], &cpu_times[8], 
               &cpu_times[9]);
        
        *total_time = 0;
        for (int i = 0; i < CPU_FIELDS; i++) {
            *total_time += cpu_times[i];
        }
        *idle_time = cpu_times[3];  // Idle time is the fourth field
    }
    
    fclose(fp);
}

int main() {
    long prev_idle, prev_total;
    long idle, total;
    
    printf("Monitoring CPU Usage...\n");
    
    get_cpu_usage(&prev_idle, &prev_total);
    
    while (1) {
        sleep(1);  // Sample every second
        get_cpu_usage(&idle, &total);
        
        long diff_idle = idle - prev_idle;
        long diff_total = total - prev_total;
        
        double usage = 100.0 * (1.0 - (double)diff_idle / (double)diff_total);
        
        printf("CPU Usage: %.2f%%\n", usage);
        
        prev_idle = idle;
        prev_total = total;
    }

    return 0;
}