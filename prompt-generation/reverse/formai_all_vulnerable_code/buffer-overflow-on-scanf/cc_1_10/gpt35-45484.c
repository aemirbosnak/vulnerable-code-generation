//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Process structure for storing process information
struct process {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
    int wait_time;
    int turnaround_time;
    int remaining_time;
    int completion_time;
};

// Function to sort processes by arrival time
void sort_processes(struct process *p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Function to find process with highest priority
int get_highest_priority_process(struct process *p, int n) {
    int min_priority = 1000;
    int min_index = -1;
    for (int i = 0; i < n; i++) {
        if (p[i].remaining_time > 0 && p[i].priority < min_priority) {
            min_priority = p[i].priority;
            min_index = i;
        }
    }
    return min_index;
}

// Function to perform Round Robin scheduling
void round_robin(struct process *p, int n, int quantum) {
    int time = 0;
    int remaining_processes = n;
    int waiting_time = 0;
    int turnaround_time = 0;
    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0) {
                if (p[i].remaining_time <= quantum) {
                    time += p[i].remaining_time;
                    p[i].remaining_time = 0;
                    p[i].completion_time = time;
                    p[i].wait_time = p[i].completion_time - p[i].burst_time - p[i].arrival_time;
                    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                    waiting_time += p[i].wait_time;
                    turnaround_time += p[i].turnaround_time;
                    remaining_processes--;
                }
                else {
                    time += quantum;
                    p[i].remaining_time -= quantum;
                }
            }
        }
    }
    printf("Round Robin Scheduling\n");
    printf("Average Waiting Time = %f\n", (float) waiting_time / (float) n);
    printf("Average Turnaround Time = %f\n", (float) turnaround_time / (float) n);
}

// Function to perform Priority scheduling
void priority_scheduling(struct process *p, int n) {
    int time = 0;
    int waiting_time = 0;
    int turnaround_time = 0;
    int remaining_processes = n;
    while (remaining_processes > 0) {
        int index = get_highest_priority_process(p, n);
        if (index == -1) {
            time++;
        }
        else {
            time += p[index].burst_time;
            p[index].remaining_time = 0;
            p[index].completion_time = time;
            p[index].wait_time = p[index].completion_time - p[index].burst_time - p[index].arrival_time;
            p[index].turnaround_time = p[index].completion_time - p[index].arrival_time;
            waiting_time += p[index].wait_time;
            turnaround_time += p[index].turnaround_time;
            remaining_processes--;
        }
    }
    printf("Priority Scheduling\n");
    printf("Average Waiting Time = %f\n", (float) waiting_time / (float) n);
    printf("Average Turnaround Time = %f\n", (float) turnaround_time / (float) n);
}

// Main function
int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time, burst time and priority of process %d: ", i+1);
        scanf("%d%d%d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
        p[i].remaining_time = p[i].burst_time;
        p[i].process_id = i+1;
    }
    printf("Enter time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);
    sort_processes(p, n);
    round_robin(p, n, quantum);
    priority_scheduling(p, n);
    return 0;
}