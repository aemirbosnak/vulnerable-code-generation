//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_LENGTH 100

int main() {
    long double prev_total_cpu_time = 0.0, prev_idle_cpu_time = 0.0;
    char buffer[MAX_LENGTH];
    int num_cpu_cores;

    FILE* file = fopen("/proc/stat", "r");

    // Get number of CPU cores in the system
    while (fgets(buffer, MAX_LENGTH, file)) {
      if (strncmp(buffer, "cpu", 3) != 0) {
        break;
      }
      num_cpu_cores++;
    }

    fclose(file);

    while (1) {
        long double total_cpu_time = 0.0, idle_cpu_time = 0.0;
        file = fopen("/proc/stat", "r");

        // Parse the CPU usage data
        fgets(buffer, MAX_LENGTH, file);
        char* token = strtok(buffer, " ");
        for (int i = 0; i < num_cpu_cores + 1; i++) {
            token = strtok(NULL, " ");
            total_cpu_time += atof(token);
            if (i == 3) {
                idle_cpu_time = atof(token);
            }
        }

        fclose(file);

        // Calculate CPU usage percentage
        long double diff_total_cpu_time = total_cpu_time - prev_total_cpu_time;
        long double diff_idle_cpu_time = idle_cpu_time - prev_idle_cpu_time;
        long double usage_percentage = (diff_total_cpu_time - diff_idle_cpu_time) / diff_total_cpu_time * 100;

        printf("CPU Usage: %.2Lf%%\n", usage_percentage);

        prev_total_cpu_time = total_cpu_time;
        prev_idle_cpu_time = idle_cpu_time;

        sleep(1);
    }

    return 0;
}