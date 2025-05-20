//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;       // Process ID
    int burst;     // Burst Time
    int arrival;   // Arrival Time
} Process;

void displayGanttChart(int n, Process proc[], int completion_time[]) {
    printf("\nGantt Chart:\n| ");
    for (int i = 0; i < n; i++) {
        printf("P%d | ", proc[i].pid);
    }
    printf("\n");

    printf("0 ");
    for (int i = 0; i < n; i++) {
        printf("%-3d", completion_time[i]);
    }
    printf("\n");
}

void fcfsScheduling(int n, Process proc[]) {
    int completion_time[MAX_PROCESSES];
    int waiting_time[MAX_PROCESSES];
    int turnaround_time[MAX_PROCESSES];

    completion_time[0] = proc[0].arrival + proc[0].burst;
    waiting_time[0] = 0;
    
    for (int i = 1; i < n; i++) {
        completion_time[i] = completion_time[i-1] + proc[i].burst;
        waiting_time[i] = completion_time[i-1] - proc[i].arrival;
    }

    printf("First-Come, First-Served Scheduling:\n");
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + proc[i].burst;
        printf("P%d: Waiting Time = %d, Turnaround Time = %d\n", proc[i].pid, waiting_time[i], turnaround_time[i]);
    }

    displayGanttChart(n, proc, completion_time);
}

void sjfScheduling(int n, Process proc[]) {
    int completion_time[MAX_PROCESSES];
    int waiting_time[MAX_PROCESSES];
    int turnaround_time[MAX_PROCESSES];

    int completed = 0, current_time = 0, min_index, min_burst;

    while (completed < n) {
        min_burst = 9999;
        min_index = -1;

        for (int j = 0; j < n; j++) {
            if (proc[j].arrival <= current_time && proc[j].burst < min_burst && proc[j].burst > 0) {
                min_burst = proc[j].burst;
                min_index = j;
            }
        }

        if (min_index != -1) {
            current_time += proc[min_index].burst;
            proc[min_index].burst = 0;
            completion_time[completed] = current_time;
            waiting_time[completed] = current_time - proc[min_index].arrival;
            completed++;
        } else {
            current_time++;
        }
    }

    printf("Shortest Job First Scheduling:\n");
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + proc[i].burst;
        printf("P%d: Waiting Time = %d, Turnaround Time = %d\n", proc[i].pid, waiting_time[i], turnaround_time[i]);
    }

    displayGanttChart(n, proc, completion_time);
}

int main() {
    int n;
    Process proc[MAX_PROCESSES];

    printf("Enter the number of processes (max 10): ");
    scanf("%d", &n);

    if (n > MAX_PROCESSES || n <= 0) {
        printf("Invalid number of processes. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter burst time and arrival time for process P%d: ", proc[i].pid);
        scanf("%d %d", &proc[i].burst, &proc[i].arrival);
    }

    fcfsScheduling(n, proc);

    // Reset burst time for SJF scheduling
    for (int i = 0; i < n; i++) {
        printf("Re-Enter burst time for process P%d for SJF: ", proc[i].pid);
        scanf("%d", &proc[i].burst);
    }

    sjfScheduling(n, proc);

    return 0;
}