//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TOTAL_PROCESSORS 8

void print_cpu_usage(double cpu_usage[TOTAL_PROCESSORS]) {
    printf("CPU Usage:\n");
    for (int i = 0; i < TOTAL_PROCESSORS; i++) {
        printf("Processor %d: %.2f%%\n", i, cpu_usage[i]);
    }
}

double read_cpu_usage(int processor_id) {
    char filename[20];
    sprintf(filename, "/proc/%d/stat", processor_id);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char line[100];
    fgets(line, 100, file);
    fclose(file);

    int total_time = 0;
    int idle_time = 0;
    int num_processors = 0;

    sscanf(line, "cpu %d %d %d %d", &total_time, &idle_time, &num_processors, &num_processors);

    double cpu_usage = ((double) (total_time - idle_time)) / (double) total_time * 100.0;

    return cpu_usage;
}

int main() {
    double cpu_usage[TOTAL_PROCESSORS];

    for (int i = 0; i < TOTAL_PROCESSORS; i++) {
        cpu_usage[i] = read_cpu_usage(i);
    }

    print_cpu_usage(cpu_usage);

    return 0;
}