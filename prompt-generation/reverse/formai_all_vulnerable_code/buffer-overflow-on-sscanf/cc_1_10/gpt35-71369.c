//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void display_cpu_usage() {
    char buffer[1024];
    long double idle[8], total[8];
    static short int cpu_usage = -1;

    FILE* file_pointer = fopen("/proc/stat", "r");

    if (file_pointer == NULL) {
        printf("Error: Could not open /proc/stat file.\n");
        return;
    }

    fgets(buffer, sizeof(buffer), file_pointer);
    sscanf(buffer, "cpu %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf",
        &total[0], &idle[0], &total[1], &total[2], &total[3], &total[4], &total[5], &total[6]);

    long double usage = 0;

    if (cpu_usage >= 0) {
        long double total_diff = total[0] + total[1] + total[2] + total[3] + total[4] + total[5] + total[6] - (total[cpu_usage] + idle[cpu_usage]);
        long double idle_diff = idle[0] - idle[cpu_usage];
        usage = (total_diff > 0) ? (100.0 * (total_diff - idle_diff) / total_diff) : 0;
    }

    cpu_usage++;

    if (cpu_usage > 7) {
        cpu_usage = 0;
    }

    printf("CPU usage: %.2Lf%%\n", usage);

    fclose(file_pointer);
}

int main() {
    printf("Monitoring CPU usage...\n");

    while (1) {
        display_cpu_usage();
        sleep(1);
    }

    return 0;
}