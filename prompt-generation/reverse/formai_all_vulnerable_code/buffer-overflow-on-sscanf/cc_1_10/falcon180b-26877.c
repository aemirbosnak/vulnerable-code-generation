//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LEN 20

typedef struct {
    char name[MAX_PROCESS_NAME_LEN];
    unsigned int pid;
    unsigned long int mem_usage;
} process_t;

void get_processes(process_t *processes) {
    FILE *fp;
    char line[1024];
    char name[MAX_PROCESS_NAME_LEN];
    char state;
    unsigned int pid;
    unsigned long int mem_usage;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "Name: %19[^\n]", name);
        sscanf(line, "State: %c", &state);
        sscanf(line, "Pid: %d", &pid);
        sscanf(line, "VmSize: %lu kB", &mem_usage);

        strncpy(processes[0].name, name, MAX_PROCESS_NAME_LEN - 1);
        processes[0].name[MAX_PROCESS_NAME_LEN - 1] = '\0';
        processes[0].pid = pid;
        processes[0].mem_usage = mem_usage;

        break;
    }

    fclose(fp);
}

void print_processes(process_t *processes, int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%-20s %5d %10lu kB\n", processes[i].name, processes[i].pid, processes[i].mem_usage);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    get_processes(processes);
    num_processes = 1;

    while (1) {
        sleep(5);
        get_processes(processes);

        if (num_processes < MAX_PROCESSES) {
            num_processes++;
        }

        print_processes(processes, num_processes);
    }

    return 0;
}