//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CPU_USAGE_FILE "/proc/stat"

// Function to get CPU usage as a percentage
double get_cpu_usage(void) {
    FILE *file;
    char buffer[1024];
    int total, idle, i;
    double usage;

    if ((file = fopen(CPU_USAGE_FILE, "r")) == NULL) {
        perror("Error opening CPU usage file");
        exit(1);
    }

    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        perror("Error reading CPU usage file");
        exit(1);
    }

    sscanf(buffer, "cpu %d %d %d %d", &total, &idle, &i, &i);
    usage = ((double) (total - idle)) / total * 100;

    fclose(file);

    return usage;
}

// Function to print formatted CPU usage
void print_cpu_usage(double usage) {
    printf("CPU Usage: %.2f%%\n", usage);
}

// Main function
int main(void) {
    double cpu_usage;

    while (1) {
        cpu_usage = get_cpu_usage();
        print_cpu_usage(cpu_usage);
        sleep(1);
    }

    return 0;
}