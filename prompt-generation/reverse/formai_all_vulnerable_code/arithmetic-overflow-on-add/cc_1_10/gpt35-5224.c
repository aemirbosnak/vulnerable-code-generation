//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_PROCESSES 20

struct Process {
    int pid; // process id
    int arrival_time; // time process arrives
    int burst_time; // time process needs to complete
    int completion_time; // time process completes
    int turnaround_time; // time process completes - time process arrives
    int waiting_time; // time process spends waiting
    bool is_completed; // is process completed?
};

int compareProcessesByArrivalTime(const void* p1, const void* p2) {
    const struct Process *x = *((const struct Process **) p1);
    const struct Process *y = *((const struct Process **) p2);
    return x->arrival_time - y->arrival_time;
}

int compareProcessesByBurstTime(const void* p1, const void* p2) {
    const struct Process *x = *((const struct Process **) p1);
    const struct Process *y = *((const struct Process **) p2);
    return x->burst_time - y->burst_time;
}

void fcfs(struct Process* processes[], int num_processes) {
    int current_time = processes[0]->arrival_time;
    for (int i = 0; i < num_processes; i++) {
        struct Process* process = processes[i];
        if (process->arrival_time > current_time) {
            current_time = process->arrival_time;
        }
        process->completion_time = current_time + process->burst_time;
        process->turnaround_time = process->completion_time - process->arrival_time;
        process->waiting_time = process->turnaround_time - process->burst_time;
        current_time = process->completion_time;
    }
}

void sjf(struct Process* processes[], int num_processes) {
    int current_time = processes[0]->arrival_time;
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < num_processes; i++) {
        remaining_time[i] = processes[i]->burst_time;
    }
    int complete = 0;
    while (complete != num_processes) {
        int shortest_index = -1;
        int shortest_burst_time = INT_MAX;
        for (int i = 0; i < num_processes; i++) {
            struct Process* process = processes[i];
            if (process->arrival_time <= current_time && !process->is_completed && remaining_time[i] < shortest_burst_time) {
                shortest_index = i;
                shortest_burst_time = remaining_time[i];
            }
        }
        if (shortest_index == -1) {
            current_time++;
        } else {
            struct Process* process = processes[shortest_index];
            process->completion_time = current_time + process->burst_time;
            process->turnaround_time = process->completion_time - process->arrival_time;
            process->waiting_time = process->turnaround_time - process->burst_time;
            process->is_completed = true;
            remaining_time[shortest_index] = INT_MAX;
            current_time = process->completion_time;
            complete++;
        }
    }
}

int main() {
    printf("Enter the number of processes: ");
    int num_processes;
    scanf("%d", &num_processes);
    struct Process* processes[num_processes];
    for (int i = 0; i < num_processes; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        processes[i] = malloc(sizeof(struct Process));
        scanf("%d%d", &processes[i]->arrival_time, &processes[i]->burst_time);
        processes[i]->pid = i + 1;
        processes[i]->is_completed = false;
    }
    qsort(processes, num_processes, sizeof(struct Process*), compareProcessesByArrivalTime);
    fcfs(processes, num_processes);
    printf("\nFirst-Come, First-Served (FCFS):\n");
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < num_processes; i++) {
        struct Process* process = processes[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process->pid, process->arrival_time, process->burst_time, process->completion_time, process->turnaround_time, process->waiting_time);
        free(process);
    }
    printf("\nEnter the number of processes: ");
    scanf("%d", &num_processes);
    for (int i = 0; i < num_processes; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        processes[i] = malloc(sizeof(struct Process));
        scanf("%d%d", &processes[i]->arrival_time, &processes[i]->burst_time);
        processes[i]->pid = i + 1;
        processes[i]->is_completed = false;
    }
    qsort(processes, num_processes, sizeof(struct Process*), compareProcessesByArrivalTime);
    sjf(processes, num_processes);
    printf("\nShortest Job First (SJF):\n");
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < num_processes; i++) {
        struct Process* process = processes[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process->pid, process->arrival_time, process->burst_time, process->completion_time, process->turnaround_time, process->waiting_time);
        free(process);
    }
    return 0;
}