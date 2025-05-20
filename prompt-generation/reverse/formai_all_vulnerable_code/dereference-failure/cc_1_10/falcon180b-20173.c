//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_PROCESSES 1024
#define PROCESS_DATA_SIZE 4096

typedef struct {
    int pid;
    char name[64];
    int status;
    int cpu_usage;
    int memory_usage;
    time_t start_time;
    time_t end_time;
    double cpu_time;
    double elapsed_time;
} ProcessData;

ProcessData *processes = NULL;
int num_processes = 0;

void read_processes() {
    FILE *fp;
    char filename[64];
    snprintf(filename, sizeof(filename), "/proc/%d/stat", getpid());
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open %s\n", filename);
        exit(1);
    }
    char line[PROCESS_DATA_SIZE];
    while (fgets(line, PROCESS_DATA_SIZE, fp)!= NULL) {
        ProcessData *data = (ProcessData *)malloc(sizeof(ProcessData));
        sscanf(line, "%d %s %d %d %d %ld %ld %ld %ld %ld", &data->pid, data->name, &data->status, &data->cpu_usage, &data->memory_usage, &data->start_time, &data->end_time, &data->cpu_time, &data->elapsed_time);
        if (num_processes >= MAX_PROCESSES) {
            printf("Error: Maximum number of processes reached\n");
            exit(1);
        }
        processes[num_processes++] = *data;
        free(data);
    }
    fclose(fp);
}

void print_processes() {
    printf("PID\tName\tStatus\tCPU Usage\tMemory Usage\tStart Time\tEnd Time\tCPU Time\tElapsed Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\t%d%%\t%d%%\t%s\t%s\t%.2f\t%.2f\n", processes[i].pid, processes[i].name, processes[i].status, processes[i].cpu_usage, processes[i].memory_usage, ctime(&processes[i].start_time), ctime(&processes[i].end_time), processes[i].cpu_time, processes[i].elapsed_time);
    }
}

void main() {
    read_processes();
    print_processes();
}