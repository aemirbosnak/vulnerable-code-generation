//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define TOTAL_SAMPLES 10

typedef struct {
    int pid;
    char name[16];
    int cpu_usage;
} process_info;

void get_process_info(process_info *processes, int num_processes) {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= num_processes)
            break;

        token = strtok(line, " ");
        sscanf(token, "%d", &processes[i].pid);

        token = strtok(NULL, " ");
        strncpy(processes[i].name, token, 15);
        processes[i].name[15] = '\0';

        token = strtok(NULL, " ");
        processes[i].cpu_usage = atoi(token);

        i++;
    }

    fclose(fp);
}

double calculate_cpu_usage(int total_ticks, int idle_ticks) {
    return (double) (total_ticks - idle_ticks) / (double) total_ticks * 100.0;
}

int main() {
    int i;
    process_info processes[TOTAL_SAMPLES];

    get_process_info(processes, TOTAL_SAMPLES);

    for (i = 0; i < TOTAL_SAMPLES; i++) {
        printf("Process %s (PID: %d) is using %.2f%% CPU\n", processes[i].name, processes[i].pid, calculate_cpu_usage(processes[i].cpu_usage, 0));
    }

    return 0;
}