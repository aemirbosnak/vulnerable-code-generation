//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int wait_time;
    int turnaround_time;
    int remaining_time;
    bool executed;
} Process;

void get_input(Process p[], int n) {
    printf("Enter the arrival times and burst times for each process:\n");
    for(int i=0; i<n; i++) {
        printf("Process %d - Arrival Time: ", i+1);
        scanf("%d", &p[i].arrival_time);
        printf("Process %d - Burst Time: ", i+1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i+1;
        p[i].executed = false;
        p[i].remaining_time = p[i].burst_time;
    }
}

void fcfs(Process p[], int n) {
    int clock = p[0].arrival_time;
    for(int i=0; i<n; i++) {
        if(p[i].arrival_time > clock) {
            clock = p[i].arrival_time;
        }
        p[i].wait_time = clock - p[i].arrival_time;
        p[i].turnaround_time = p[i].wait_time + p[i].burst_time;
        clock += p[i].burst_time;
    }
}

void sjf(Process p[], int n) {
    int completed = 0, clock = 0;
    while(completed < n) {
        int min_burst = 999, min_burst_index = -1;
        for(int i=0; i<n; i++) {
            if(p[i].arrival_time <= clock && p[i].executed == false && p[i].remaining_time < min_burst) {
                min_burst = p[i].remaining_time;
                min_burst_index = i;
            }
        }
        if(min_burst_index == -1) {
            clock++;
            continue;
        }
        p[min_burst_index].wait_time = clock - p[min_burst_index].arrival_time;
        p[min_burst_index].turnaround_time = p[min_burst_index].wait_time + p[min_burst_index].burst_time;
        p[min_burst_index].remaining_time = 0;
        p[min_burst_index].executed = true;
        completed++;
        clock += p[min_burst_index].burst_time;
    }
}

void print_output(Process p[], int n) {
    printf("PID\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].wait_time, p[i].turnaround_time);
    }
}

int main() {
    int n, algo;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process p[n];
    get_input(p, n);
    printf("\nEnter the algorithm you wish to use:\n1. FCFS\n2. SJF\n");
    scanf("%d", &algo);
    switch(algo) {
        case 1:
            fcfs(p, n);
            printf("\nFCFS Scheduling:\n");
            print_output(p, n);
            break;
        case 2:
            sjf(p, n);
            printf("\nSJF Scheduling:\n");
            print_output(p, n);
            break;
        default:
            printf("\nInvalid option chosen.\n");
            break;
    }
    return 0;
}