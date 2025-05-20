//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

struct process {
    int pid; // process id
    int burst_time; // duration of the process in milliseconds
    int arrival_time; // time at which the process arrives to the CPU
    int remaining_time; // remaining time of the process
};

// function to swap two processes
void swap(struct process* p1, struct process* p2) {
    struct process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// function to sort the processes based on arrival time
void sort_processes(struct process* processes, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

// function to execute the processes using Round Robin Scheduling Algorithm
void round_robin_scheduling(struct process* processes, int n, int time_quantum) {
    int i, time = 0, turnaround_time = 0, waiting_time = 0, count = n;
    while (count != 0) {
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > time_quantum) {
                time += time_quantum;
                processes[i].remaining_time -= time_quantum;
            } else if (processes[i].remaining_time > 0) {
                time += processes[i].remaining_time;
                turnaround_time = time - processes[i].arrival_time;
                waiting_time += turnaround_time - processes[i].burst_time;
                processes[i].remaining_time = 0;
                count--;
            }
        }
    }
    printf("Avg turnaround time: %f\nAvg waiting time: %f\n", (float)turnaround_time / n, (float)waiting_time / n);
}

// function to get the processes details from the user
void get_processes(struct process* processes, int n) {
    int i;
    for (i = 0; i< n; i++) {
        printf("Enter process id, arrival time and burst time of process %d: ", i + 1);
        scanf("%d%d%d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }
}

int main() {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process* processes = (struct process*)malloc(n * sizeof(struct process));
    get_processes(processes, n);
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    sort_processes(processes, n);
    round_robin_scheduling(processes, n, time_quantum);
    free(processes);
    return 0;
}