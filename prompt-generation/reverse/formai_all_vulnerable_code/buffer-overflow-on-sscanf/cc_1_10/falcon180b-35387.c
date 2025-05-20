//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LEN 50

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LEN];
    int memory_usage;
} Process;

void get_processes(Process *processes, int *num_processes) {
    FILE *fp;
    char line[1024];
    char name[MAX_PROCESS_NAME_LEN];
    int pid, memory_usage;

    *num_processes = 0;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (sscanf(line, "Name: %s", name) == 1) {
            sscanf(line, "Name: %s\nVmSize: %d kB", name, &memory_usage);
            pid = getpid();

            if (*num_processes >= MAX_PROCESSES) {
                break;
            }

            processes[*num_processes].pid = pid;
            strncpy(processes[*num_processes].name, name, MAX_PROCESS_NAME_LEN);
            processes[*num_processes].memory_usage = memory_usage;

            (*num_processes)++;
        }
    }

    fclose(fp);
}

void print_processes(Process *processes, int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%d: %-50s %10d KB\n", processes[i].pid, processes[i].name, processes[i].memory_usage);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes;

    get_processes(processes, &num_processes);
    print_processes(processes, num_processes);

    return 0;
}