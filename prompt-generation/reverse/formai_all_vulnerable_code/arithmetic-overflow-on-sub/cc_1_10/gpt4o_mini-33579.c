//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;           // Process ID
    int burst_time;    // Burst time
    int arrival_time;  // Arrival time
} Process;

void fcfs(Process processes[], int n) {
    int wait_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES];
    wait_time[0] = 0;

    for (int i = 1; i < n; i++) {
        wait_time[i] = wait_time[i - 1] + processes[i - 1].burst_time;
    }

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = wait_time[i] + processes[i].burst_time;
    }

    printf("FCFS Scheduling:\n");
    printf("PID\tBurst Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, wait_time[i], turnaround_time[i]);
    }
}

void sjf(Process processes[], int n) {
    int wait_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES];
    int completed[MAX_PROCESSES] = {0};

    // Sort processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    wait_time[0] = 0;
    for (int i = 1; i < n; i++) {
        wait_time[i] = wait_time[i - 1] + processes[i - 1].burst_time;
    }

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = wait_time[i] + processes[i].burst_time;
    }

    printf("SJF Scheduling:\n");
    printf("PID\tBurst Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, wait_time[i], turnaround_time[i]);
    }
}

void round_robin(Process processes[], int n, int quantum) {
    int wait_time[MAX_PROCESSES] = {0};
    int remaining_burst[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = processes[i].burst_time;
    }

    int time = 0;
    int done;
    
    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                if (remaining_burst[i] > quantum) {
                    time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    time += remaining_burst[i];
                    wait_time[i] = time - processes[i].burst_time;
                    remaining_burst[i] = 0;
                }
                done = 0;
            }
        }
    } while (!done);
    
    printf("Round Robin Scheduling:\n");
    printf("PID\tBurst Time\tWait Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, wait_time[i]);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, choice, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n); 
   
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for process %d: ", processes[i].pid);
        scanf("%d", &processes[i].burst_time);
        printf("Enter arrival time for process %d: ", processes[i].pid);
        scanf("%d", &processes[i].arrival_time);
    }

    printf("Choose a scheduling algorithm:\n");
    printf("1. FCFS\n2. SJF\n3. Round Robin\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fcfs(processes, n);
            break;
        case 2:
            sjf(processes, n);
            break;
        case 3:
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &quantum);
            round_robin(processes, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}