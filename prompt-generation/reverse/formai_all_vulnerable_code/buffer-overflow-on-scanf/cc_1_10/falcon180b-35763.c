//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_PROCESS_NAME 20

typedef struct {
    char name[MAX_PROCESS_NAME];
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int cpu_time;
    int priority;
} Process;

int compare_priority(const void *a, const void *b) {
    int priority_a = (*(Process *)a).priority;
    int priority_b = (*(Process *)b).priority;
    if (priority_a > priority_b) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process processes[MAX_PROCESSES];
    for (int i = 0; i < num_processes; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", processes[i].name);
        printf("Enter the burst time of process %s: ", processes[i].name);
        scanf("%d", &processes[i].burst_time);
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].cpu_time = 0;
        processes[i].priority = rand() % 10; // Assign random priority
    }

    qsort(processes, num_processes, sizeof(Process), compare_priority);

    printf("\nProcess Name\tBurst Time\tPriority\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t\t%d\t\t%d\n", processes[i].name, processes[i].burst_time, processes[i].priority);
    }

    int quantum = 2;
    int current_time = 0;
    int completed_processes = 0;
    int context_switches = 0;
    while (completed_processes < num_processes) {
        int i;
        for (i = 0; i < num_processes; i++) {
            if (processes[i].burst_time > 0) {
                if (processes[i].cpu_time + quantum <= processes[i].burst_time) {
                    processes[i].cpu_time += quantum;
                    processes[i].burst_time -= quantum;
                    current_time += quantum;
                    printf("%s executed for %d time units. Current time: %d\n", processes[i].name, quantum, current_time);
                } else {
                    processes[i].cpu_time += processes[i].burst_time % quantum;
                    processes[i].burst_time = 0;
                    completed_processes++;
                    printf("%s completed execution. Context switches: %d\n", processes[i].name, context_switches);
                }
            } else {
                continue;
            }
        }
        if (i == num_processes) {
            current_time += quantum;
        }
    }

    return 0;
}