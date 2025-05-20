//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int start_time;
    int end_time;
    int waiting_time;
    int response_time;
    int turnaround_time;
};

int compare_arrival_time(const void *a, const void *b) {
    struct process *pa = (struct process *) a;
    struct process *pb = (struct process *) b;
    return pa->arrival_time - pb->arrival_time;
}

int compare_priority(const void *a, const void *b) {
    struct process *pa = (struct process *) a;
    struct process *pb = (struct process *) b;
    return pb->priority - pa->priority;
}

int main() {
    int n, algorithm;
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    struct process p[n];
    printf("Enter the details of each process (pid, burst_time, arrival_time, priority):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &p[i].pid, &p[i].burst_time, &p[i].arrival_time, &p[i].priority);
    }
    printf("Choose a CPU scheduling algorithm (1-FCFS, 2-SJF, 3-Priority): ");
    scanf("%d", &algorithm);
    if (algorithm == 1) { // First Come First Serve
        qsort(p, n, sizeof(struct process), compare_arrival_time);
        int current_time = 0;
        for (int i = 0; i < n; i++) {
            p[i].start_time = current_time;
            p[i].end_time = current_time + p[i].burst_time;
            p[i].waiting_time = current_time - p[i].arrival_time;
            p[i].response_time = current_time - p[i].arrival_time;
            p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
            current_time = p[i].end_time;
        }
    } else if (algorithm == 2) { // Shortest Job First
        qsort(p, n, sizeof(struct process), compare_arrival_time);
        int current_time = 0;
        bool done[n];
        for (int i = 0; i < n; i++) done[i] = false;
        while (true) {
            int shortest_job = -1;
            for (int i = 0; i < n; i++) {
                if (!done[i] && p[i].arrival_time <= current_time && (shortest_job == -1 || p[i].burst_time < p[shortest_job].burst_time)) {
                    shortest_job = i;
                }
            }
            if (shortest_job == -1) break;
            p[shortest_job].start_time = current_time;
            p[shortest_job].end_time = current_time + p[shortest_job].burst_time;
            p[shortest_job].waiting_time = current_time - p[shortest_job].arrival_time;
            p[shortest_job].response_time = current_time - p[shortest_job].arrival_time;
            p[shortest_job].turnaround_time = p[shortest_job].waiting_time + p[shortest_job].burst_time;
            current_time = p[shortest_job].end_time;
            done[shortest_job] = true;
        }
    } else if (algorithm == 3) { // Priority Scheduling
        qsort(p, n, sizeof(struct process), compare_priority);
        int current_time = 0;
        bool done[n];
        for (int i = 0; i < n; i++) done[i] = false;
        while (true) {
            int highest_priority = -1;
            for (int i = 0; i < n; i++) {
                if (!done[i] && p[i].arrival_time <= current_time && (highest_priority == -1 || p[i].priority > p[highest_priority].priority)) {
                    highest_priority = i;
                }
            }
            if (highest_priority == -1) break;
            p[highest_priority].start_time = current_time;
            p[highest_priority].end_time = current_time + p[highest_priority].burst_time;
            p[highest_priority].waiting_time = current_time - p[highest_priority].arrival_time;
            p[highest_priority].response_time = current_time - p[highest_priority].arrival_time;
            p[highest_priority].turnaround_time = p[highest_priority].waiting_time + p[highest_priority].burst_time;
            current_time = p[highest_priority].end_time;
            done[highest_priority] = true;
        }
    }
    printf("\nPID\tBurst Time\tArrival Time\tPriority\tStart Time\tEnd Time\tWaiting Time\tResponse Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].priority, p[i].start_time, p[i].end_time, p[i].waiting_time, p[i].response_time, p[i].turnaround_time);
    }
    return 0;
}