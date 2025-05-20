//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <math.h>

#define MAX_PROCESSES 10
#define MAX_PRIORITY 10

struct process {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

int compare_priority(const void *a, const void *b) {
    struct process *p1 = (struct process *)a;
    struct process *p2 = (struct process *)b;

    if (p1->priority > p2->priority) {
        return -1;
    } else if (p1->priority < p2->priority) {
        return 1;
    } else {
        return 0;
    }
}

void calculate_turnaround_time(struct process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void execute_processes(struct process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Executing process %d with burst time %d\n", processes[i].id, processes[i].burst_time);
        sleep(processes[i].burst_time);
        printf("Process %d completed execution\n", processes[i].id);
    }
}

void print_processes(struct process *processes, int num_processes) {
    printf("Process ID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].priority, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    // Initialize process array
    struct process processes[MAX_PROCESSES];

    // Get number of processes from user
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Get process details from user
    for (int i = 0; i < num_processes; i++) {
        printf("Enter process details for process %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &processes[i].id);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    // Sort processes based on priority
    qsort(processes, num_processes, sizeof(struct process), compare_priority);

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < num_processes; i++) {
        processes[i].waiting_time = 0;
        for (int j = 0; j < i; j++) {
            processes[i].waiting_time += processes[j].burst_time;
        }
    }

    calculate_turnaround_time(processes, num_processes);

    // Print process details
    printf("Process Details:\n");
    print_processes(processes, num_processes);

    // Execute processes
    execute_processes(processes, num_processes);

    return 0;
}