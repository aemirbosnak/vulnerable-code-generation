//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int process_id;
    int burst_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

void calculateTimes(Process processes[], int n) {
    int total_turnaround_time = 0, total_waiting_time = 0;

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
    }

    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
}

void sortProcessesByArrival(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void roundRobinScheduling(Process processes[], int n, int quantum) {
    int remaining_burst_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }

    int time = 0;
    int completed = 0;
    
    while (completed < n) {
        int burst_done = 0;
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0 && processes[i].arrival_time <= time) {
                if (remaining_burst_time[i] > quantum) {
                    time += quantum;
                    remaining_burst_time[i] -= quantum;
                } else {
                    time += remaining_burst_time[i];
                    processes[i].completion_time = time;
                    remaining_burst_time[i] = 0;
                    completed++;
                }
                burst_done = 1;
            }
        }
        
        // If no process was executed, increment time
        if (burst_done == 0) {
            time++;
        }
    }

    calculateTimes(processes, n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Exceeded maximum processes limit!\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        processes[i].process_id = i + 1;
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].completion_time = 0; // Initialize completion time
    }

    printf("Enter the time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);

    sortProcessesByArrival(processes, n);
    roundRobinScheduling(processes, n, quantum);

    printf("\nProcess ID\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].process_id,
               processes[i].burst_time,
               processes[i].arrival_time,
               processes[i].completion_time,
               processes[i].turnaround_time,
               processes[i].waiting_time);
    }

    return 0;
}