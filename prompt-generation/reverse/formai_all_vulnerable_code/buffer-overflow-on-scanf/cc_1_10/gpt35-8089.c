//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: innovative
#include <stdio.h>

#define MAX_PROCESS 10

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int remaining_time;
};

// function prototypes
void fcfs(struct process *p, int n);
void sjf(struct process *p, int n);
int min_remaining_time(struct process *p, int n, int current_time);

int main() {
    int n, i;
    struct process p[MAX_PROCESS];
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        p[i].pid = i;
        printf("Process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }
    
    fcfs(p, n);
    sjf(p, n);
    
    return 0;
}

/**
 * First-Come, First-Serve scheduling algorithm
 */
void fcfs(struct process *p, int n) {
    printf("\nFCFS scheduling algorithm:\n");
    int i, current_time = 0;
    float avg_turnaround_time = 0.0, avg_waiting_time = 0.0;
    
    for (i = 0; i < n; i++) {
        if (p[i].arrival_time > current_time) {
            current_time = p[i].arrival_time;
        }
        p[i].completion_time = current_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        avg_turnaround_time += p[i].turnaround_time;
        avg_waiting_time += p[i].waiting_time;
        current_time = p[i].completion_time;
    }
    
    avg_turnaround_time /= n;
    avg_waiting_time /= n;
    
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time,
               p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    printf("Average waiting time: %.2f\n", avg_waiting_time);
}

/**
 * Shortest Job First scheduling algorithm
 */
void sjf(struct process *p, int n) {
    printf("\nSJF scheduling algorithm:\n");
    int i, current_time = 0, remaining_processes = n, current_process;
    float avg_turnaround_time = 0.0, avg_waiting_time = 0.0;
    
    while (remaining_processes > 0) {
        current_process = min_remaining_time(p, n, current_time);
        p[current_process].remaining_time--;
        if (p[current_process].remaining_time == 0) {
            remaining_processes--;
            p[current_process].completion_time = current_time + 1;
            p[current_process].turnaround_time = p[current_process].completion_time - p[current_process].arrival_time;
            p[current_process].waiting_time = p[current_process].turnaround_time - p[current_process].burst_time;
            avg_turnaround_time += p[current_process].turnaround_time;
            avg_waiting_time += p[current_process].waiting_time;
        }
        current_time++;
    }
    
    avg_turnaround_time /= n;
    avg_waiting_time /= n;
    
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time,
               p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    printf("Average waiting time: %.2f\n", avg_waiting_time);
}

/**
 * Returns the index of the process in the array with the minimum remaining time
 */
int min_remaining_time(struct process *p, int n, int current_time) {
    int i, min = -1;
    for (i = 0; i < n; i++) {
        if (p[i].arrival_time <= current_time && p[i].remaining_time > 0) {
            if (min == -1 || p[i].remaining_time < p[min].remaining_time) {
                min = i;
            }
        }
    }
    return min;
}