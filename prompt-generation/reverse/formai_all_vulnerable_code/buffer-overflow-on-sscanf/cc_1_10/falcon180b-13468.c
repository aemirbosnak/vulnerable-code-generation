//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESS_NUM 100
#define MAX_PROCESS_NAME_LEN 50
#define MAX_PROCESS_MEM_LEN 20

typedef struct {
    char name[MAX_PROCESS_NAME_LEN];
    int pid;
    char mem[MAX_PROCESS_MEM_LEN];
} Process;

int main() {
    int i, j, num_processes = 0;
    char line[1024];
    Process *processes = (Process*)malloc(MAX_PROCESS_NUM * sizeof(Process));
    FILE *fp;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/self/status\n");
        exit(1);
    }

    // Read the name and memory usage of the current process
    fgets(line, 1024, fp);
    sscanf(line, "Name: %s", processes[num_processes].name);
    fgets(line, 1024, fp);
    sscanf(line, "VmSize: %d kB", &processes[num_processes].pid);
    fclose(fp);

    // Read the list of running processes
    fp = fopen("/proc/self/task/", "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/self/task/\n");
        exit(1);
    }

    while (fgets(line, 1024, fp)!= NULL) {
        if (num_processes >= MAX_PROCESS_NUM) {
            printf("Error: Maximum number of processes exceeded\n");
            exit(1);
        }
        sscanf(line, "%d", &processes[num_processes].pid);
        sprintf(processes[num_processes].mem, "%d kB", processes[num_processes].pid);
        num_processes++;
    }

    fclose(fp);

    printf("Process Name\t\tPID\t\tMemory Usage\n");
    printf("---------------------------------------------------\n");

    // Print the name, PID, and memory usage of each process
    for (i = 0; i < num_processes; i++) {
        printf("%-50s %-10d %-20s\n", processes[i].name, processes[i].pid, processes[i].mem);
    }

    free(processes);
    return 0;
}