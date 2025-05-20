//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define PROCESS_NAME_MAX 16

struct process_info {
    pid_t pid;
    char name[PROCESS_NAME_MAX];
    unsigned long long start_time;
    unsigned long long cpu_time;
};

void print_process_info(struct process_info *process) {
    printf("PID: %d\n", process->pid);
    printf("Name: %s\n", process->name);
    printf("Start Time: %llu\n", process->start_time);
    printf("CPU Time: %llu\n", process->cpu_time);
    printf("\n");
}

void print_cpu_usage(struct process_info *processes, int num_processes) {
    unsigned long long total_cpu_time = 0;
    for (int i = 0; i < num_processes; i++) {
        total_cpu_time += processes[i].cpu_time;
    }

    printf("Total CPU Time: %llu\n", total_cpu_time);
    printf("Average CPU Time: %llu\n", total_cpu_time / num_processes);
}

int main() {
    struct process_info processes[MAX_PROCESSES];
    int num_processes = 0;

    FILE *fp;
    char line[1024];
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            sscanf(line, "cpu %llu %llu %llu %llu",
                   &processes[num_processes].start_time,
                   &processes[num_processes].cpu_time,
                   &processes[num_processes].start_time,
                   &processes[num_processes].cpu_time);
            num_processes++;
        }
    }

    fclose(fp);

    printf("Process ID\tName\tStart Time\tCPU Time\n");
    for (int i = 0; i < num_processes; i++) {
        print_process_info(&processes[i]);
    }

    print_cpu_usage(processes, num_processes);

    return 0;
}