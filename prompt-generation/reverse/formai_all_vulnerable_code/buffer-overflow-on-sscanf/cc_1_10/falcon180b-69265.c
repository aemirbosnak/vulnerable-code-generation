//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUF_SIZE 1024
#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char name[64];
    char state;
    int cpu_time;
    int memory_usage;
    int priority;
} Process;

int read_processes(Process processes[], int max_processes) {
    char buffer[BUF_SIZE];
    FILE *fp;
    int count = 0;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        return -1;
    }

    while (fgets(buffer, BUF_SIZE, fp)!= NULL) {
        if (count >= max_processes) {
            break;
        }

        sscanf(buffer, "Name:\t%s\n", processes[count].name);
        processes[count].pid = getpid();
        processes[count].state = 'R';
        count++;
    }

    fclose(fp);

    return count;
}

void print_processes(Process processes[], int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("PID:\t%d\tName:\t%s\tState:\t%c\tCPU Time:\t%d\tMemory Usage:\t%d\tPriority:\t%d\n",
               processes[i].pid, processes[i].name, processes[i].state, processes[i].cpu_time, processes[i].memory_usage, processes[i].priority);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes;

    num_processes = read_processes(processes, MAX_PROCESSES);

    print_processes(processes, num_processes);

    return 0;
}