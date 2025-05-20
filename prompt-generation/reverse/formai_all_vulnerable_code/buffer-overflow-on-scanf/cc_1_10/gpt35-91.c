//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 4

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int remaining_time;
};

void round_robin(struct process processes[], int n);
void shortest_job_first(struct process processes[], int n);
void priority_scheduling(struct process processes[], int n);

int main() {
    int n, i;
    struct process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        printf("Enter process %d's arrival time: ", i+1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter process %d's burst time: ", i+1);
        scanf("%d", &processes[i].burst_time);

        printf("Enter process %d's priority: ", i+1);
        scanf("%d", &processes[i].priority);

        processes[i].pid = i+1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\nRound Robin Scheduling:\n");
    round_robin(processes, n);

    printf("\nShortest Job First Scheduling:\n");
    shortest_job_first(processes, n);

    printf("\nPriority Scheduling:\n");
    priority_scheduling(processes, n);

    return 0;
}

void round_robin(struct process processes[], int n) {
    int i, time = 0, remaining_processes = n;
    int quantum = TIME_QUANTUM;

    printf("PID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (remaining_processes > 0) {
        for (i=0; i<n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= time) {
                if (processes[i].remaining_time <= quantum) {
                    time += processes[i].remaining_time;
                    quantum = TIME_QUANTUM;
                    processes[i].remaining_time = 0;
                    remaining_processes--;
                    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, time, time - processes[i].arrival_time, time - processes[i].arrival_time - processes[i].burst_time);
                } else {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                    printf("%d\t\t%d\t\t%d\t\t%d\t\t-\t\t\t-\t\t\t-\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority);
                }
            } else {
                printf("-\t\t-\t\t-\t\t-\t\t-\t\t\t-\t\t\t-\n");
            }
        }
    }
}

void shortest_job_first(struct process processes[], int n) {
    int i, j, time = 0, total_time = 0;
    struct process temp;

    printf("PID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    for (i=0; i<n; i++) {
        total_time += processes[i].burst_time;
    }

    while (time < total_time) {
        int shortest_job = -1;
        for (i=0; i<n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                if (shortest_job == -1) {
                    shortest_job = i;
                } else if (processes[i].burst_time < processes[shortest_job].burst_time) {
                    shortest_job = i;
                }
            }
        }

        if (shortest_job == -1) {
            time++;
            continue;
        }

        processes[shortest_job].remaining_time--;
        time++;

        if (processes[shortest_job].remaining_time == 0) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", processes[shortest_job].pid, processes[shortest_job].arrival_time, processes[shortest_job].burst_time, processes[shortest_job].priority, time, time - processes[shortest_job].arrival_time, time - processes[shortest_job].arrival_time - processes[shortest_job].burst_time);
        } else {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t-\t\t\t-\t\t\t-\n", processes[shortest_job].pid, processes[shortest_job].arrival_time, processes[shortest_job].burst_time, processes[shortest_job].priority);
        }
    }
}

void priority_scheduling(struct process processes[], int n) {
    int i, j, time = 0, total_time = 0;
    struct process temp;

    printf("PID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    for (i=0; i<n; i++) {
        total_time += processes[i].burst_time;
    }

    while (time < total_time) {
        int highest_priority = -1;
        for (i=0; i<n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                if (highest_priority == -1) {
                    highest_priority = i;
                } else if (processes[i].priority < processes[highest_priority].priority) {
                    highest_priority = i;
                }
            }
        }

        if (highest_priority == -1) {
            time++;
            continue;
        }

        processes[highest_priority].remaining_time--;
        time++;

        if (processes[highest_priority].remaining_time == 0) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", processes[highest_priority].pid, processes[highest_priority].arrival_time, processes[highest_priority].burst_time, processes[highest_priority].priority, time, time - processes[highest_priority].arrival_time, time - processes[highest_priority].arrival_time - processes[highest_priority].burst_time);
        } else {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t-\t\t\t-\t\t\t-\n", processes[highest_priority].pid, processes[highest_priority].arrival_time, processes[highest_priority].burst_time, processes[highest_priority].priority);
        }
    }
}