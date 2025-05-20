//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Definition of a process */
typedef struct {
    int pid;            /* Process ID */
    int burst_time;     /* Burst time of the process */
    int arrival_time;   /* Arrival time of the process */
    int waiting_time;   /* Waiting time of the process */
    int turnaround_time;/* Turnaround time of the process */
    bool executed;      /* Flag to check if process is executed */
} Process;

/* Function to swap two processes */
void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to sort the processes based on their arrival time */
void sort(Process *p, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i].arrival_time > p[j].arrival_time) {
                swap(&p[i], &p[j]);
            }
        }
    }
}

/* Function to execute the processes using the Shortest Remaining Time First algorithm */
void execute_srtf(Process *p, int n) {
    int current_time = 0;
    int completed_processes = 0;
    while(completed_processes < n) {
        int min_burst_time = 9999;
        int next_process_index = -1;
        for(int i = 0; i < n; i++) {
            if(!p[i].executed && p[i].arrival_time <= current_time) {
                if(p[i].burst_time < min_burst_time) {
                    min_burst_time = p[i].burst_time;
                    next_process_index = i;
                }
            }
        }
        if(next_process_index == -1) {
            printf("\nNo process to execute at time %d\n", current_time);
            current_time++;
            continue;
        }
        current_time += p[next_process_index].burst_time;
        p[next_process_index].turnaround_time = current_time - p[next_process_index].arrival_time;
        p[next_process_index].waiting_time = p[next_process_index].turnaround_time - p[next_process_index].burst_time;
        completed_processes++;
        p[next_process_index].executed = true;
        printf("\nProcess %d executed from %d to %d\n", p[next_process_index].pid, current_time - p[next_process_index].burst_time, current_time);
        printf("Waiting time: %d, Turnaround time: %d\n", p[next_process_index].waiting_time, p[next_process_index].turnaround_time);
    }
}

/* Function to display the final results of the processes */
void display_results(Process *p, int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    printf("\nPID\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    printf("\nAverage waiting time: %.2f", (float) total_waiting_time / n);
    printf("\nAverage turnaround time: %.2f", (float) total_turnaround_time / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process *p = (Process *) malloc(n * sizeof(Process));
    printf("\nEnter the details of the processes:\n");
    for(int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Enter the burst time: ");
        scanf("%d", &p[i].burst_time);
        printf("Enter the arrival time: ");
        scanf("%d", &p[i].arrival_time);
        p[i].pid = i + 1;
        p[i].executed = false;
    }
    sort(p, n);
    execute_srtf(p, n);
    display_results(p, n);
    free(p);
    return 0;
}