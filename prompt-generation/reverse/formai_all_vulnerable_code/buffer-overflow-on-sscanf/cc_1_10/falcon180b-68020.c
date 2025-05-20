//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
    char name[20];
    int pid;
    int parent_pid;
    int cpu_usage;
    int memory_usage;
} process;

void read_processes(process *processes) {
    char line[1024];
    char *token;
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }
    fgets(line, sizeof(line), fp);
    fclose(fp);
    sscanf(line, "cpu %d %d %d %d", &processes[0].cpu_usage, &processes[0].cpu_usage, &processes[0].cpu_usage, &processes[0].cpu_usage);
    fp = fopen("/proc/self/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/self/stat\n");
        exit(1);
    }
    fgets(line, sizeof(line), fp);
    sscanf(line, "%d %s %d %d %d %d %d %d %d %d", &processes[0].pid, processes[0].name, &processes[0].pid, &processes[0].parent_pid, &processes[0].cpu_usage, &processes[0].cpu_usage, &processes[0].cpu_usage, &processes[0].cpu_usage, &processes[0].cpu_usage, &processes[0].cpu_usage);
    fclose(fp);
}

void print_processes(process *processes) {
    printf("Process Name\tPID\tParent PID\tCPU Usage\tMemory Usage\n");
    for (int i = 0; i < 1; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].parent_pid, processes[i].cpu_usage, processes[i].cpu_usage);
    }
}

int main() {
    process processes[1];
    read_processes(processes);
    print_processes(processes);
    return 0;
}