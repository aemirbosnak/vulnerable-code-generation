//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 20

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

int compare_arrival_time(const void* a, const void* b) {
    process *p1 = (process*)a;
    process *p2 = (process*)b;
    return p1->arrival_time - p2->arrival_time;
}

int compare_burst_time(const void* a, const void* b) {
    process *p1 = (process*)a;
    process *p2 = (process*)b;
    return p1->burst_time - p2->burst_time;
}

void print_table(process processes[], int n) {
    printf("PID\tARRIVAL\tBURST\tWAITING\tTURNAROUND\n");
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time,
               processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("Average waiting time: %.2f\n", (float)total_waiting_time / n);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time / n);
}

void fcfs(process processes[], int n) {
    qsort(processes, n, sizeof(process), compare_arrival_time);
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
    }
    print_table(processes, n);
}

void sjf_non_preemptive(process processes[], int n) {
    qsort(processes, n, sizeof(process), compare_arrival_time);
    int current_time = 0;
    int completed = 0;
    while (completed < n) {
        int shortest_job_index = -1;
        int shortest_job_burst_time = 1000000;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].burst_time < shortest_job_burst_time && processes[i].turnaround_time == 0) {
                shortest_job_index = i;
                shortest_job_burst_time = processes[i].burst_time;
            }
        }
        if (shortest_job_index != -1) {
            processes[shortest_job_index].waiting_time = current_time - processes[shortest_job_index].arrival_time;
            processes[shortest_job_index].turnaround_time = processes[shortest_job_index].waiting_time + processes[shortest_job_index].burst_time;
            current_time += processes[shortest_job_index].burst_time;
            completed++;
        } else {
            current_time++;
        }
    }
    print_table(processes, n);
}

void sjf_preemptive(process processes[], int n) {
    qsort(processes, n, sizeof(process), compare_arrival_time);
    int current_time = 0;
    int completed = 0;
    int remaining_burst_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }
    bool job_completed[MAX_PROCESSES] = {false};
    while (completed < n) {
        int shortest_job_index = -1;
        int shortest_job_burst_time = 1000000;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && remaining_burst_time[i] < shortest_job_burst_time && job_completed[i] == false) {
                shortest_job_index = i;
                shortest_job_burst_time = remaining_burst_time[i];
            }
        }
        if (shortest_job_index != -1) {
            remaining_burst_time[shortest_job_index] -= 1;
            if (remaining_burst_time[shortest_job_index] == 0) {
                processes[shortest_job_index].waiting_time = current_time - processes[shortest_job_index].arrival_time - processes[shortest_job_index].burst_time + 1;
                processes[shortest_job_index].turnaround_time = processes[shortest_job_index].waiting_time + processes[shortest_job_index].burst_time;
                completed++;
                job_completed[shortest_job_index] = true;
            }
        } else {
            current_time++;
        }
    }
    print_table(processes, n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    process processes[MAX_PROCESSES];
    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        processes[i].pid = i + 1;
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }
    printf("Select CPU scheduling algorithm:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF) - Non Preemptive\n");
    printf("3. Shortest Job First (SJF) - Preemptive\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            fcfs(processes, n);
            break;
        case 2:
            sjf_non_preemptive(processes, n);
            break;
        case 3:
            sjf_preemptive(processes, n);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}