//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
} Process;

void fcfs_scheduling(Process *p, int n) {
    int cnt = 0, total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        p[i].waiting_time = cnt;
        cnt += p[i].burst_time;
        p[i].turnaround_time = cnt;
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    printf("\n***First Come First Serve Scheduling***\n\n");
    printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("\nAverage waiting time: %.2f\n", (float)total_waiting_time/n);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time/n);
}

void sjf_scheduling(Process *p, int n) {
    int cnt = 0, total_waiting_time = 0, total_turnaround_time = 0;
    bool *visited = (bool *)calloc(n, sizeof(bool));
    for (int i = 0; i < n; i++) {
        int idx = -1, min_time = 0x3f3f3f3f;
        for (int j = 0; j < n; j++) {
            if(!visited[j] && p[j].burst_time < min_time) {
                idx = j;
                min_time = p[j].burst_time;
            }
        }
        visited[idx] = true;
        p[idx].waiting_time = cnt;
        cnt += p[idx].burst_time;
        p[idx].turnaround_time = cnt;
        total_waiting_time += p[idx].waiting_time;
        total_turnaround_time += p[idx].turnaround_time;
    }
    printf("\n***Shortest Job First Scheduling***\n\n");
    printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("\nAverage waiting time: %.2f\n", (float)total_waiting_time/n);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time/n);
    free(visited);
}

void round_robin_scheduling(Process *p, int n, int quantum) {
    int cnt = 0, total_waiting_time = 0, total_turnaround_time = 0, completed = 0;
    int *remaining_time = (int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        remaining_time[i] = p[i].burst_time;
    }
    while (true) {
        bool all_completed = true;
        for (int i = 0; i < n; i++) {
            if(remaining_time[i] > 0) {
                all_completed = false;
                if (remaining_time[i] <= quantum) {
                    cnt += remaining_time[i];
                    p[i].turnaround_time = cnt;
                    remaining_time[i] = 0;
                    completed++;
                } else {
                    cnt += quantum;
                    remaining_time[i] -= quantum;
                }
                p[i].waiting_time = cnt - p[i].burst_time;
                total_waiting_time += p[i].waiting_time;
                total_turnaround_time += p[i].turnaround_time;
            }
        }
        if (all_completed) break;
    }
    printf("\n***Round Robin Scheduling***\n\n");
    printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("\nAverage waiting time: %.2f\n", (float)total_waiting_time/n);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time/n);
    free(remaining_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process *p = (Process *)malloc(n*sizeof(Process));
    printf("\nEnter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }
    fcfs_scheduling(p, n);
    sjf_scheduling(p, n);
    int quantum;
    printf("\nEnter the quantum time for Round Robin Scheduling: ");
    scanf("%d", &quantum);
    round_robin_scheduling(p, n, quantum);
    free(p);
    return 0;
}