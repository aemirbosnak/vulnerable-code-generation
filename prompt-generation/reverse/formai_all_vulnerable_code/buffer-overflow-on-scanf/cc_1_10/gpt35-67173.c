//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESS 10

typedef struct Process {
    int id;
    int priority;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
    int completed;
} Process;

// Sorts the process based on priority (lowest first)
void sort(Process *proc_arr, int n) {
    int i, j;
    Process temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (proc_arr[j].priority > proc_arr[j + 1].priority) {
                temp = proc_arr[j];
                proc_arr[j] = proc_arr[j + 1];
                proc_arr[j + 1] = temp;
            }
        }
    }
}

// Calculates the waiting time and the turnaround time of each process
void calc_process_times(Process *proc_arr, int n) {
    int i, j, t = 0;
    for (i = 0; i < n; i++) {
        t += proc_arr[i].burst_time;
        proc_arr[i].turnaround_time = t - proc_arr[i].arrival_time;
        proc_arr[i].waiting_time = proc_arr[i].turnaround_time - proc_arr[i].burst_time;
    }
}

void print_results(Process *proc_arr, int n) {
    printf("PID\tPriority\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc_arr[i].id, proc_arr[i].priority, 
            proc_arr[i].arrival_time, proc_arr[i].burst_time, proc_arr[i].waiting_time, proc_arr[i].turnaround_time);
    }
}

void round_robin(Process *proc_arr, int n, int tq) {
    int i, j, t = 0, completed = 0;
    while (completed != n) {
        for (i = 0; i < n; i++) {
            if (proc_arr[i].completed == 0) {
                if (proc_arr[i].remaining_time <= tq) {
                    t += proc_arr[i].remaining_time;
                    proc_arr[i].remaining_time = 0;
                    proc_arr[i].completed = 1;
                    completed++;
                    proc_arr[i].turnaround_time = t - proc_arr[i].arrival_time;
                    proc_arr[i].waiting_time = proc_arr[i].turnaround_time - proc_arr[i].burst_time;
                } else {
                    t += tq;
                    proc_arr[i].remaining_time -= tq;
                }
            }
        }
    }
}

int main() {
    Process proc_arr[MAX_PROCESS];
    int i, n, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for process %d\n", i + 1);
        proc_arr[i].id = i + 1;
        printf("Enter Priority: ");
        scanf("%d", &proc_arr[i].priority);
        printf("Enter Arrival Time: ");
        scanf("%d", &proc_arr[i].arrival_time);
        printf("Enter Burst Time: ");
        scanf("%d", &proc_arr[i].burst_time);

        proc_arr[i].completed = 0;
        proc_arr[i].remaining_time = proc_arr[i].burst_time;
    }

    printf("\nEnter the time quantum: ");
    scanf("%d", &tq);

    sort(proc_arr, n);
    round_robin(proc_arr, n, tq);

    calc_process_times(proc_arr, n);
    print_results(proc_arr, n);

    return 0;
}