//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CPU_USAGE_FILE "/proc/stat"
#define TOTAL_CPU_USAGE_FILE "/proc/stat"

int main() {
    FILE *fp;
    char line[1024];
    float cpu_usage;
    float total_cpu_usage;

    // Open CPU usage file
    fp = fopen(CPU_USAGE_FILE, "r");
    if (fp == NULL) {
        printf("Error opening CPU usage file\n");
        exit(1);
    }

    // Read CPU usage
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            sscanf(line, "cpu %*s %f", &cpu_usage);
            break;
        }
    }

    fclose(fp);

    // Open total CPU usage file
    fp = fopen(TOTAL_CPU_USAGE_FILE, "r");
    if (fp == NULL) {
        printf("Error opening total CPU usage file\n");
        exit(1);
    }

    // Read total CPU usage
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            sscanf(line, "cpu %*s %f", &total_cpu_usage);
            break;
        }
    }

    fclose(fp);

    // Calculate CPU usage percentage
    cpu_usage = 100 - (total_cpu_usage - cpu_usage) * 100 / total_cpu_usage;

    // Print CPU usage percentage
    printf("CPU usage: %.2f%%\n", cpu_usage);

    return 0;
}