//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 16

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    unsigned int pid;
    unsigned long long int ram_usage;
} process_t;

void print_header() {
    printf("PID\tProcess Name\tRAM Usage (Bytes)\n");
}

void print_process(process_t* process) {
    printf("%d\t%s\t%llu\n", process->pid, process->name, process->ram_usage);
}

void print_processes(process_t* processes, int num_processes) {
    print_header();
    for (int i = 0; i < num_processes; i++) {
        print_process(&processes[i]);
    }
}

int compare_processes(const void* a, const void* b) {
    process_t* process_a = (process_t*)a;
    process_t* process_b = (process_t*)b;

    if (process_a->ram_usage > process_b->ram_usage) {
        return -1;
    } else if (process_a->ram_usage < process_b->ram_usage) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char command[100];
    FILE* pipe = popen("ps axo pid,comm", "r");
    if (pipe == NULL) {
        printf("Error: Failed to open pipe.\n");
        return 1;
    }

    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    while (fscanf(pipe, "%d %s", &processes[num_processes].pid, processes[num_processes].name)!= EOF) {
        if (num_processes >= MAX_PROCESSES) {
            printf("Error: Maximum number of processes reached.\n");
            pclose(pipe);
            return 1;
        }
        num_processes++;
    }

    pclose(pipe);

    char* endptr;
    FILE* fp;
    unsigned long long int ram_usage;

    for (int i = 0; i < num_processes; i++) {
        sprintf(command, "cat /proc/%d/status | grep VmSize", processes[i].pid);
        fp = popen(command, "r");
        if (fp == NULL) {
            printf("Error: Failed to open pipe.\n");
            return 1;
        }

        fscanf(fp, "VmSize: %llu kB", &ram_usage);
        pclose(fp);

        processes[i].ram_usage = ram_usage;
    }

    qsort(processes, num_processes, sizeof(process_t), compare_processes);

    print_processes(processes, num_processes);

    return 0;
}