//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int turnaround_time;
    int waiting_time;
    int response_time;
    int remaining_time;
};

void round_robin(struct process p[], int n) {
    int time = p[0].arrival_time;
    int completed = 0;
    int current_process = 0;
    int time_quantum = TIME_QUANTUM;
    int is_completed[MAX_PROCESSES] = {0};

    printf("\nExecuting Round Robin Scheduling Algorithm\n");
    printf("------------------------------------------\n");

    while (completed < n) {
        if (p[current_process].remaining_time <= time_quantum && !is_completed[current_process]) {
            time += p[current_process].remaining_time;
            p[current_process].remaining_time = 0;
            is_completed[current_process] = 1;
            completed++;
            p[current_process].turnaround_time = time - p[current_process].arrival_time;
            p[current_process].waiting_time = p[current_process].turnaround_time - p[current_process].burst_time;
            p[current_process].response_time = p[current_process].turnaround_time - p[current_process].burst_time;
        } else if (!is_completed[current_process]) {
            time += time_quantum;
            p[current_process].remaining_time -= time_quantum;
        }

        current_process++;
        if (current_process == n) {
            current_process = 0;
            time_quantum++;
        }
    }
}

void priority_scheduling(struct process p[], int n) {
    int time = p[0].arrival_time;
    int completed = 0;
    int current_process = 0;
    int is_completed[MAX_PROCESSES] = {0};

    printf("\nExecuting Priority Scheduling Algorithm\n");
    printf("---------------------------------------\n");

    while (completed < n) {
        int highest_priority = 1000;
        int highest_priority_process = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time && !is_completed[i]) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    highest_priority_process = i;
                }
            }
        }

        if (highest_priority_process != -1) {
            time += p[highest_priority_process].burst_time;
            p[highest_priority_process].turnaround_time = time - p[highest_priority_process].arrival_time;
            p[highest_priority_process].waiting_time = p[highest_priority_process].turnaround_time - p[highest_priority_process].burst_time;
            p[highest_priority_process].response_time = p[highest_priority_process].turnaround_time - p[highest_priority_process].burst_time;
            is_completed[highest_priority_process] = 1;
            current_process = highest_priority_process;
            completed++;
        } else {
            time++;
        }
    }
}

void print_results(struct process p[], int n) {
    float avg_turnaround_time = 0;
    float avg_waiting_time = 0;
    float avg_response_time = 0;

    printf("\n");
    printf("Process ID\tArrival Time\tBurst Time\tPriority\tTurnaround Time\tWaiting Time\tResponse Time\n");
    printf("----------\t------------\t----------\t--------\t---------------\t------------\t-------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].turnaround_time, p[i].waiting_time, p[i].response_time);
        avg_turnaround_time += p[i].turnaround_time;
        avg_waiting_time += p[i].waiting_time;
        avg_response_time += p[i].response_time;
    }

    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time / n);
    printf("\nAverage Waiting Time: %.2f", avg_waiting_time / n);
    printf("\nAverage Response Time: %.2f", avg_response_time / n);
}

int main() {
    int n;
    struct process p[MAX_PROCESSES];

    printf("Enter the number of processes (<= 10): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        p[i].pid = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
        p[i].remaining_time = p[i].burst_time;
    }

    round_robin(p, n);
    priority_scheduling(p, n);
    print_results(p, n);

    return 0;
}