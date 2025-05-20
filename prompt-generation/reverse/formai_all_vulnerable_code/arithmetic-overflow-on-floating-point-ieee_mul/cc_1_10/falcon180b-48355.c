//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <fcntl.h>

#define CPU_USAGE_INTERVAL 5 // in seconds

typedef struct {
    double cpu_usage;
    time_t timestamp;
} CpuUsage;

void get_cpu_usage(CpuUsage *cpu_usage) {
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        printf("Error: could not open /proc/stat\n");
        exit(1);
    }

    char line[1024];
    if (fgets(line, sizeof(line), file) == NULL) {
        printf("Error: could not read line from /proc/stat\n");
        fclose(file);
        exit(1);
    }

    fclose(file);

    char *token = strtok(line, " ");
    while (token!= NULL) {
        if (strcmp(token, "cpu") == 0) {
            token = strtok(NULL, " ");
            cpu_usage->cpu_usage = atof(token) / (double)sysconf(_SC_CLK_TCK);
            break;
        }
        token = strtok(NULL, " ");
    }

    cpu_usage->timestamp = time(NULL);
}

void print_cpu_usage(CpuUsage cpu_usage) {
    printf("CPU usage: %.2f%%\n", cpu_usage.cpu_usage * 100);
}

int main() {
    CpuUsage current_cpu_usage, previous_cpu_usage;
    get_cpu_usage(&previous_cpu_usage);

    while (1) {
        sleep(CPU_USAGE_INTERVAL);
        get_cpu_usage(&current_cpu_usage);

        double delta_cpu_usage = current_cpu_usage.cpu_usage - previous_cpu_usage.cpu_usage;
        printf("Delta CPU usage: %.2f%%\n", delta_cpu_usage * 100);

        print_cpu_usage(current_cpu_usage);

        previous_cpu_usage = current_cpu_usage;
    }

    return 0;
}