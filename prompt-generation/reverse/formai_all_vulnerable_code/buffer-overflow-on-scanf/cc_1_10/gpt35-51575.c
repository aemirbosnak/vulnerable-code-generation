//FormAI DATASET v1.0 Category: System boot optimizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct process {
    int priority;
    int memory_usage;
    int cpu_usage;
} process_t;


int compare_processes(const void *a, const void *b) {
    process_t *p1 = (process_t*)a;
    process_t *p2 = (process_t*)b;
    
    // sort by priority first
    if (p1->priority < p2->priority) {
        return 1;
    } else if (p1->priority > p2->priority) {
        return -1;
    }
    
    // if priority is the same, sort by memory usage
    if (p1->memory_usage < p2->memory_usage) {
        return 1;
    } else if (p1->memory_usage > p2->memory_usage) {
        return -1;
    }
    
    // if memory usage is the same, sort by CPU usage
    if (p1->cpu_usage < p2->cpu_usage) {
        return 1;
    } else if (p1->cpu_usage > p2->cpu_usage) {
        return -1;
    }
    
    return 0;
}


int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes;
    int i;
    
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    
    // read in process data
    for (i = 0; i < num_processes; i++) {
        printf("Enter the priority, memory usage, and CPU usage for process %d: ", i+1);
        scanf("%d %d %d", &processes[i].priority, &processes[i].memory_usage, &processes[i].cpu_usage);
    }
    
    // sort processes
    qsort(processes, num_processes, sizeof(process_t), compare_processes);
    
    // print out sorted processes
    printf("Sorted Processes:\n");
    for (i = 0; i < num_processes; i++) {
        printf("Priority: %d, Memory Usage: %d, CPU Usage: %d\n", processes[i].priority, processes[i].memory_usage, processes[i].cpu_usage);
    }
    
    return 0;
}