//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: accurate
#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void fcfs(struct Process proc[], int n) {
    int i, sum_waiting_time = 0, sum_turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;

    // Waiting time for first process is 0
    proc[0].waiting_time = 0;

    // Calculate waiting time for each process
    for (i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
        sum_waiting_time += proc[i].waiting_time;
    }

    // Calculate turnaround time for each process
    for (i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
        sum_turnaround_time += proc[i].turnaround_time;
    }

    // Calculate average waiting time and turnaround time
    avg_waiting_time = (float)sum_waiting_time / (float)n;
    avg_turnaround_time = (float)sum_turnaround_time / (float)n;

    // Display result
    printf("\nFCFS Scheduling\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrival_time,
               proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }

    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

void sjf(struct Process proc[], int n) {
    int i, j, pos;
    struct Process temp;
    int sum_waiting_time = 0, sum_turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;

    // Sort processes by burst time in ascending order using selection sort
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (proc[j].burst_time < proc[pos].burst_time) {
                pos = j;
            }
        }
        temp = proc[i];
        proc[i] = proc[pos];
        proc[pos] = temp;
    }

    // Waiting time for first process is 0
    proc[0].waiting_time = 0;

    // Calculate waiting time for each process
    for (i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
        sum_waiting_time += proc[i].waiting_time;
    }

    // Calculate turnaround time for each process
    for (i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
        sum_turnaround_time += proc[i].turnaround_time;
    }

    // Calculate average waiting time and turnaround time
    avg_waiting_time = (float)sum_waiting_time / (float)n;
    avg_turnaround_time = (float)sum_turnaround_time / (float)n;

    // Display result
    printf("\nSJF Scheduling\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrival_time,
               proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }

    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

int main(void) {
    int i, n;
    struct Process proc[10];

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    printf("Enter process details\n");

    for (i = 0; i < n; i++) {
        printf("Enter process id: ");
        scanf("%d", &proc[i].pid);

        printf("Enter arrival time: ");
        scanf("%d", &proc[i].arrival_time);

        printf("Enter burst time: ");
        scanf("%d", &proc[i].burst_time);
    }

    fcfs(proc, n);
    sjf(proc, n);

    return 0;
}