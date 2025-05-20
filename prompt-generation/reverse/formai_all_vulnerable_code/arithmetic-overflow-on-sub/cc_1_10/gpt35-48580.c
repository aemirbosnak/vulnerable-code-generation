//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void FCFS(struct process p[], int n) {
    int i, total_waiting_time = 0, total_turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;

    p[0].waiting_time = 0;

    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }

    for (i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }

    avg_waiting_time = (float) total_waiting_time / n;
    avg_turnaround_time = (float) total_turnaround_time / n;

    printf("\n\n----- First-Come-First-Serve (FCFS) Algorithm -----\n");
    printf("PID \tArrival Time \tBurst Time \tPriority \tWaiting Time \tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d \t%d \t\t%d \t\t%d \t\t%d \t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
    }

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

void SJF(struct process p[], int n) {
    int i, j, min_idx;
    struct process temp;
    int total_waiting_time = 0, total_turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < n; j++) {
            if (p[j].burst_time < p[min_idx].burst_time) {
                min_idx = j;
            }
        }

        temp = p[min_idx];
        p[min_idx] = p[i];
        p[i] = temp;
    }

    p[0].waiting_time = 0;

    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }

    for (i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }

    avg_waiting_time = (float) total_waiting_time / n;
    avg_turnaround_time = (float) total_turnaround_time / n;

    printf("\n\n----- Shortest-Job-First (SJF) Algorithm -----\n");
    printf("PID \tArrival Time \tBurst Time \tPriority \tWaiting Time \tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d \t%d \t\t%d \t\t%d \t\t%d \t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
    }

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

void Priority(struct process p[], int n) {
    int i, j, max_idx;
    struct process temp;
    int total_waiting_time = 0, total_turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;

    for (i = 0; i < n - 1; i++) {
        max_idx = i;

        for (j = i + 1; j < n; j++) {
            if (p[j].priority > p[max_idx].priority) {
                max_idx = j;
            }
        }

        temp = p[max_idx];
        p[max_idx] = p[i];
        p[i] = temp;
    }

    p[0].waiting_time = 0;

    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }

    for (i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }

    avg_waiting_time = (float) total_waiting_time / n;
    avg_turnaround_time = (float) total_turnaround_time / n;

    printf("\n\n----- Priority Algorithm -----\n");
    printf("PID \tArrival Time \tBurst Time \tPriority \tWaiting Time \tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d \t%d \t\t%d \t\t%d \t\t%d \t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
    }

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int i, n, choice;
    struct process p[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the details of process %d:\n", i + 1);
        printf("PID: ");
        scanf("%d", &p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        printf("Priority (1-5): ");
        scanf("%d", &p[i].priority);
        printf("\n");
    }

    printf("Which CPU scheduling algorithm do you want to use?\n");
    printf("1. First-Come-First-Serve (FCFS)\n");
    printf("2. Shortest-Job-First (SJF)\n");
    printf("3. Priority\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            FCFS(p, n);
            break;
        case 2:
            SJF(p, n);
            break;
        case 3:
            Priority(p, n);
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            exit(0);
    }

    return 0;
}