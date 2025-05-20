//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Process structure
struct process {
    int pid;
    int arrival_time;
    int burst_time;
};

// Function to sort processes based on their arrival time
void sort_processes(struct process *processes, int size) {
    int i, j;
    struct process temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (processes[j].arrival_time > processes[j+1].arrival_time) {
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

// Function to execute processes using FCFS scheduling algorithm
void fcfs_scheduler(struct process *processes, int size) {
    int i, current_time = 0, total_waiting_time = 0;
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\n");
    for (i = 0; i < size; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        total_waiting_time += current_time - processes[i].arrival_time;
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, current_time - processes[i].arrival_time);
        current_time += processes[i].burst_time;
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time/size);
}

// Function to execute processes using SJF scheduling algorithm
void sjf_scheduler(struct process *processes, int size) {
    int i, j, current_time = 0, total_waiting_time = 0;
    struct process temp;
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\n");
    for (i = 0; i < size; i++) {
        for (j = i+1; j < size; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
        total_waiting_time += current_time - processes[i].arrival_time;
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, current_time - processes[i].arrival_time);
        current_time += processes[i].burst_time;
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time/size);
}

int main() {
    int i, size, algorithm;
    struct process *processes;
    printf("Enter the number of processes: ");
    scanf("%d", &size);
    processes = (struct process*)malloc(size * sizeof(struct process));
    // Getting process details from user
    for (i = 0; i < size; i++) {
        printf("Enter details of process %d:\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i+1;
    }
    // Sorting processes based on arrival time
    sort_processes(processes, size);
    // Getting scheduling algorithm from user
    printf("Choose a scheduling algorithm:\n");
    printf("1. FCFS\n2. SJF\n");
    scanf("%d", &algorithm);
    switch(algorithm) {
        // FCFS algorithm
        case 1:
            fcfs_scheduler(processes, size);
            break;
        // SJF algorithm
        case 2:
            sjf_scheduler(processes, size);
            break;
        default:
            printf("Invalid choice!\n");
    }
    free(processes);
    return 0;
}