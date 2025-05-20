//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 20

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int ram_usage;
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void add_process(int pid, char* name) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    strncpy(processes[num_processes].name, name, MAX_PROCESS_NAME_LENGTH);
    processes[num_processes].pid = pid;
    processes[num_processes].ram_usage = 0;

    num_processes++;
}

void update_ram_usage() {
    FILE* fp;
    char line[1024];
    int pid;
    int ram_usage;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/self/status.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (sscanf(line, "VmSize: %d kB", &ram_usage) == 1) {
            break;
        }
    }

    fclose(fp);

    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid == getpid()) {
            processes[i].ram_usage = ram_usage;
            break;
        }
    }
}

void print_processes() {
    printf("PID\tName\tRAM Usage (kB)\n");

    for (int i = 0; i < num_processes; i++) {
        if (processes[i].ram_usage > 0) {
            printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].ram_usage);
        }
    }
}

int main() {
    add_process(getpid(), "Main Process");

    while (1) {
        update_ram_usage();
        print_processes();
        sleep(1);
    }

    return 0;
}