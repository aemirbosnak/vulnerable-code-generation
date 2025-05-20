//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

typedef struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void fcfs(Process *processes, int n) {
    int time = 0;
    float avg_wait_time = 0.0, avg_turnaround_time = 0.0;

    for (int i = 0; i < n; i++) {
        time += processes[i].burst_time;
        processes[i].turnaround_time = time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        avg_wait_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nFCFS Scheduling Algorithm\n");
    printf("----------------------------\n");
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, 
            processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("Average Waiting Time: %.2f\n", avg_wait_time/n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time/n);
}

void sjf(Process *processes, int n) {
    int time = 0;
    float avg_wait_time = 0.0, avg_turnaround_time = 0.0;

    for (int i = 0; i < n; i++) {
        int shortest = i;
        for (int j = i+1; j < n; j++) {
            if (processes[j].burst_time < processes[shortest].burst_time) {
                shortest = j;
            }
        }
        Process temp = processes[i];
        processes[i] = processes[shortest];
        processes[shortest] = temp;
    }

    for (int i = 0; i < n; i++) {
        time += processes[i].burst_time;
        processes[i].turnaround_time = time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        avg_wait_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nShortest Job First Scheduling Algorithm\n");
    printf("---------------------------------------\n");
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, 
            processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("Average Waiting Time: %.2f\n", avg_wait_time/n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time/n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *) malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for process %d:\n", i+1);
        processes[i].pid = i+1;
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    fcfs(processes, n);
    sjf(processes, n);

    free(processes);

    return 0;
}